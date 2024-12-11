#if 1

#include "ogs-crypt.h"

#define SHA1CircularShift(bits,word) \
                ((((word) << (bits)) & 0xFFFFFFFF) | \
                ((word) >> (32-(bits))))

/* Function prototypes */
static void SHA1ProcessMessageBlock(ogs_sha1_ctx *);
static void SHA1PadMessage(ogs_sha1_ctx *);

/*  
 *  sha1_init
 *
 *  Description:
 *      This function will initialize the ogs_sha1_ctx in preparation
 *      for computing a new message digest.
 *
 *  Parameters:
 *      context: [in/out]
 *          The context to reset.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
void ogs_sha1_init(ogs_sha1_ctx *ctx)
{
    ctx->Length_Low             = 0;
    ctx->Length_High            = 0;
    ctx->Message_Block_Index    = 0;

    ctx->Message_Digest[0]      = 0x67452301;
    ctx->Message_Digest[1]      = 0xEFCDAB89;
    ctx->Message_Digest[2]      = 0x98BADCFE;
    ctx->Message_Digest[3]      = 0x10325476;
    ctx->Message_Digest[4]      = 0xC3D2E1F0;

    ctx->Computed   = 0;
    ctx->Corrupted  = 0;
}

void ogs_sha1_final(ogs_sha1_ctx *ctx, uint8_t *digest)

{
    if (!ctx->Computed)
    {
        SHA1PadMessage(ctx);
        ctx->Computed = 1;
    }


// #if OGS_BYTE_ORDER == OGS_BIG_ENDIAN
    memcpy(digest, ctx->Message_Digest, OGS_SHA1_DIGEST_SIZE);

}

/*  
 *  sha1_update
 *
 *  Description:
 *      This function accepts an array of octets as the next portion of
 *      the message.
 *
 *  Parameters:
 *      context: [in/out]
 *          The SHA-1 context to update
 *      message_array: [in]
 *          An array of characters representing the next portion of the
 *          message.
 *      length: [in]
 *          The length of the message in message_array
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
void ogs_sha1_update(ogs_sha1_ctx *ctx, const uint8_t *message_array,
        uint32_t length)
{
    if (!length)
    {
        return;
    }

    if (ctx->Computed || ctx->Corrupted)
    {
        ctx->Corrupted = 1;
        return;
    }

    while(length-- && !ctx->Corrupted)
    {
        ctx->Message_Block[ctx->Message_Block_Index++] =
                                                (*message_array & 0xFF);

        ctx->Length_Low += 8;
        /* Force it to 32 bits */
        ctx->Length_Low &= 0xFFFFFFFF;
        if (ctx->Length_Low == 0)
        {
            ctx->Length_High++;
            /* Force it to 32 bits */
            ctx->Length_High &= 0xFFFFFFFF;
            if (ctx->Length_High == 0)
            {
                /* Message is too long */
                ctx->Corrupted = 1;
            }
        }

        if(ctx->Message_Block_Index == 64)
        {
            SHA1ProcessMessageBlock(ctx);
        }

        message_array++;
    }
}

/*  
 *  SHA1ProcessMessageBlock
 *
 *  Description:
 *      This function will process the next 512 bits of the message
 *      stored in the Message_Block array.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      Many of the variable names in the SHAContext, especially the
 *      single character names, were used because those were the names
 *      used in the publication.
 *         
 *
 */
static void SHA1ProcessMessageBlock(ogs_sha1_ctx *ctx)
{
    const unsigned K[] =            /* Constants defined in SHA-1   */      
    {
        0x5A827999,
        0x6ED9EBA1,
        0x8F1BBCDC,
        0xCA62C1D6
    };
    int         t;                  /* Loop counter                 */
    unsigned    temp;               /* Temporary word value         */
    unsigned    W[80];              /* Word sequence                */
    unsigned    A, B, C, D, E;      /* Word buffers                 */

    /*
     *  Initialize the first 16 words in the array W
     */
    for(t = 0; t < 16; t++)
    {
        W[t] = ((unsigned) ctx->Message_Block[t * 4]) << 24;
        W[t] |= ((unsigned) ctx->Message_Block[t * 4 + 1]) << 16;
        W[t] |= ((unsigned) ctx->Message_Block[t * 4 + 2]) << 8;
        W[t] |= ((unsigned) ctx->Message_Block[t * 4 + 3]);
    }

    for(t = 16; t < 80; t++)
    {
       W[t] = SHA1CircularShift(1,W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
    }

    A = ctx->Message_Digest[0];
    B = ctx->Message_Digest[1];
    C = ctx->Message_Digest[2];
    D = ctx->Message_Digest[3];
    E = ctx->Message_Digest[4];

    for(t = 0; t < 20; t++)
    {
        temp =  SHA1CircularShift(5,A) +
                ((B & C) | ((~B) & D)) + E + W[t] + K[0];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 20; t < 40; t++)
    {
        temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[1];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 40; t < 60; t++)
    {
        temp = SHA1CircularShift(5,A) +
               ((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 60; t < 80; t++)
    {
        temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[3];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    ctx->Message_Digest[0] =
                        (ctx->Message_Digest[0] + A) & 0xFFFFFFFF;
    ctx->Message_Digest[1] =
                        (ctx->Message_Digest[1] + B) & 0xFFFFFFFF;
    ctx->Message_Digest[2] =
                        (ctx->Message_Digest[2] + C) & 0xFFFFFFFF;
    ctx->Message_Digest[3] =
                        (ctx->Message_Digest[3] + D) & 0xFFFFFFFF;
    ctx->Message_Digest[4] =
                        (ctx->Message_Digest[4] + E) & 0xFFFFFFFF;

    ctx->Message_Block_Index = 0;
}

/*  
 *  SHA1PadMessage
 *
 *  Description:
 *      According to the standard, the message must be padded to an even
 *      512 bits.  The first padding bit must be a '1'.  The last 64
 *      bits represent the length of the original message.  All bits in
 *      between should be 0.  This function will pad the message
 *      according to those rules by filling the Message_Block array
 *      accordingly.  It will also call SHA1ProcessMessageBlock()
 *      appropriately.  When it returns, it can be assumed that the
 *      message digest has been computed.
 *
 *  Parameters:
 *      context: [in/out]
 *          The context to pad
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
static void SHA1PadMessage(ogs_sha1_ctx *ctx)
{
    /*
     *  Check to see if the current message block is too small to hold
     *  the initial padding bits and length.  If so, we will pad the
     *  block, process it, and then continue padding into a second
     *  block.
     */
    if (ctx->Message_Block_Index > 55)
    {
        ctx->Message_Block[ctx->Message_Block_Index++] = 0x80;
        while(ctx->Message_Block_Index < 64)
        {
            ctx->Message_Block[ctx->Message_Block_Index++] = 0;
        }

        SHA1ProcessMessageBlock(ctx);

        while(ctx->Message_Block_Index < 56)
        {
            ctx->Message_Block[ctx->Message_Block_Index++] = 0;
        }
    }
    else
    {
        ctx->Message_Block[ctx->Message_Block_Index++] = 0x80;
        while(ctx->Message_Block_Index < 56)
        {
            ctx->Message_Block[ctx->Message_Block_Index++] = 0;
        }
    }

    /*
     *  Store the message length as the last 8 octets
     */
    ctx->Message_Block[56] = (ctx->Length_High >> 24) & 0xFF;
    ctx->Message_Block[57] = (ctx->Length_High >> 16) & 0xFF;
    ctx->Message_Block[58] = (ctx->Length_High >> 8) & 0xFF;
    ctx->Message_Block[59] = (ctx->Length_High) & 0xFF;
    ctx->Message_Block[60] = (ctx->Length_Low >> 24) & 0xFF;
    ctx->Message_Block[61] = (ctx->Length_Low >> 16) & 0xFF;
    ctx->Message_Block[62] = (ctx->Length_Low >> 8) & 0xFF;
    ctx->Message_Block[63] = (ctx->Length_Low) & 0xFF;

    SHA1ProcessMessageBlock(ctx);
}

void ogs_sha1(const uint8_t *message, uint32_t len, uint8_t *digest)
{
    ogs_sha1_ctx ctx;

    ogs_sha1_init(&ctx);
    ogs_sha1_update(&ctx, message, len);
    ogs_sha1_final(&ctx, digest);
}

#endif