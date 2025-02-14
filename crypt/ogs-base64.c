#include "ogs-crypt.h"

/* aaaack but it's fast and const should make it shared text page. */
static const unsigned char pr2six[256] =
{
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
    64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
    64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
    64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64
};

int ogs_base64_decode_len(const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register size_t nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);

    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = (((int)nprbytes + 3) / 4) * 3;

    return nbytesdecoded + 1;
}

int ogs_base64_decode(char *bufplain, const char *bufcoded)
{
    int len;
    
    len = ogs_base64_decode_binary((unsigned char *) bufplain, bufcoded);
    bufplain[len] = '\0';
    return len;
}

/* This is the same as ogs_base64_decode() except:
 * - no \0 is appended
 */
int ogs_base64_decode_binary(unsigned char *bufplain, const char *bufcoded)
{
    int nbytesdecoded;
    register const unsigned char *bufin;
    register unsigned char *bufout;
    register size_t nprbytes;

    bufin = (const unsigned char *) bufcoded;
    while (pr2six[*(bufin++)] <= 63);
    nprbytes = (bufin - (const unsigned char *) bufcoded) - 1;
    nbytesdecoded = (((int)nprbytes + 3) / 4) * 3;

    bufout = (unsigned char *) bufplain;
    bufin = (const unsigned char *) bufcoded;

    while (nprbytes > 4) {
	*(bufout++) =
	    (unsigned char) (pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
	*(bufout++) =
	    (unsigned char) (pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
	*(bufout++) =
	    (unsigned char) (pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
	bufin += 4;
	nprbytes -= 4;
    }

    /* Note: (nprbytes == 1) would be an error, so just ignore that case */
    if (nprbytes > 1) {
	*(bufout++) =
	    (unsigned char) (pr2six[*bufin] << 2 | pr2six[bufin[1]] >> 4);
    }
    if (nprbytes > 2) {
	*(bufout++) =
	    (unsigned char) (pr2six[bufin[1]] << 4 | pr2six[bufin[2]] >> 2);
    }
    if (nprbytes > 3) {
	*(bufout++) =
	    (unsigned char) (pr2six[bufin[2]] << 6 | pr2six[bufin[3]]);
    }

    nbytesdecoded -= (4 - (int)nprbytes) & 3;
    return nbytesdecoded;
}

static const char basis_64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int ogs_base64_encode_len(int len)
{
    return ((len + 2) / 3 * 4) + 1;
}

int ogs_base64_encode(char *encoded, const char *string, int len)
{
    return ogs_base64_encode_binary(
            encoded, (const unsigned char *) string, len);
}

/* This is the same as ogs_base64_encode() except on EBCDIC machines, where
 * the conversion of the input to ascii is left out.
 */
int ogs_base64_encode_binary(
        char *encoded, const unsigned char *string, int len)
{
    int i;
    char *p;

    p = encoded;
    for (i = 0; i < len - 2; i += 3) {
	*p++ = basis_64[(string[i] >> 2) & 0x3F];
	*p++ = basis_64[((string[i] & 0x3) << 4) |
	                ((int) (string[i + 1] & 0xF0) >> 4)];
	*p++ = basis_64[((string[i + 1] & 0xF) << 2) |
	                ((int) (string[i + 2] & 0xC0) >> 6)];
	*p++ = basis_64[string[i + 2] & 0x3F];
    }
    if (i < len) {
	*p++ = basis_64[(string[i] >> 2) & 0x3F];
	if (i == (len - 1)) {
	    *p++ = basis_64[((string[i] & 0x3) << 4)];
	    *p++ = '=';
	}
	else {
	    *p++ = basis_64[((string[i] & 0x3) << 4) |
	                    ((int) (string[i + 1] & 0xF0) >> 4)];
	    *p++ = basis_64[((string[i + 1] & 0xF) << 2)];
	}
	*p++ = '=';
    }

    *p++ = '\0';
    return (int)(p - encoded);
}

/* copies data to result but removes newlines and <CR>
 * returns the size of the data copied.
 *
 * It will fail with GNUTLS_E_BASE64_DECODING_ERROR if the
 * end-result is the empty string.
 */
inline static int
cpydata(const uint8_t *data, int data_size, uint8_t **result, int *result_size)
{
	int i, j;

	*result = malloc(data_size + 1);
	if (*result == NULL) {
        // //("malloc failed[%d]", data_size+1);
        return -1;
    }

	for (j = i = 0; i < data_size; i++) {
		if (data[i] == '\n' || data[i] == '\r' || data[i] == ' '
		    || data[i] == '\t')
			continue;
		else if (data[i] == '-')
			break;
		(*result)[j] = data[i];
		j++;
	}

	*result_size = j;
	(*result)[j] = 0;

	if (j==0) {
        free(*result);
        // //("No Data");
		return -1;
	}

	return j;
}

#define MEMSUB(x,y) ((ssize_t)((ptrdiff_t)x-(ptrdiff_t)y))
#define ENDSTR "-----"
int ogs_fbase64_decode(const char *header,
        const uint8_t *data, size_t data_size, ogs_datum_t *result)
{
    static const char top[] = "-----BEGIN ";
    static const char bottom[] = "-----END ";
    uint8_t *rdata, *kdata;
    int rdata_size;
#define MAX_PEM_HEADER_LEN 128
    char pem_header[MAX_PEM_HEADER_LEN];

    uint8_t *bufcoded;
    int bufcoded_len;
    char *p, *last;

    assert(header);
    assert(data);
    assert(data_size);
    assert(result);

    memset(result, 0, sizeof(*result));

    p = pem_header;
    last = pem_header + MAX_PEM_HEADER_LEN;

    p = log_slprintf(p, last, "%s", top);
    if (header != NULL)
        p = log_slprintf(p, last, "%s", header);

    rdata = memmem(data, data_size, pem_header, strlen(pem_header));
    if (rdata == NULL) {
        // //("Cound not find [%s]", pem_header);
        // //(OGS_LOG_ERROR, data, data_size);
        return -1;
    }

    data_size -= MEMSUB(rdata, data);

    if (data_size < 4 + strlen(bottom)) {
        //("Not enough data (%d < 4 + %d)",
                // (int)data_size, (int)strlen(bottom));
        //(OGS_LOG_ERROR, data, data_size);
        return -1;
    }

    kdata =
        memmem(rdata + 1, data_size - 1, ENDSTR, sizeof(ENDSTR) - 1);
    /* allow CR as well.
     */
    if (kdata == NULL) {
        //("Cound not find [%s]", ENDSTR);
        //(OGS_LOG_ERROR, data, data_size);
        return -1;
    }
    data_size -= strlen(ENDSTR);
    data_size -= MEMSUB(kdata, rdata);

    rdata = kdata + strlen(ENDSTR);

    /* position is now after the ---BEGIN--- headers */

    kdata = memmem(rdata, data_size, bottom, strlen(bottom));
    if (kdata == NULL) {
        //("Cound not find [%s]", bottom);
        //(OGS_LOG_ERROR, data, data_size);
        return -1;
    }

    /* position of kdata is before the ----END--- footer
     */
    rdata_size = MEMSUB(kdata, rdata);

    if (rdata_size < 4) {
        //("Not enough data [%d]", rdata_size);
        //(OGS_LOG_ERROR, data, data_size);
        return -1;
    }

    if (cpydata(rdata, rdata_size, &bufcoded, &bufcoded_len) == -1) {
        //("cpydata() failed");
        //(OGS_LOG_ERROR, rdata, rdata_size);
        return -1;
    }

    result->data = calloc(1, bufcoded_len);
    if (result->data == NULL) {
        //("ogs_calloc() failed [%d]", bufcoded_len);
        free(bufcoded);
        return -1;
    }

    result->size = ogs_base64_decode_binary(
            result->data, (const char *)bufcoded);
    if (result->size == 0) {
        //("ogs_base64_decode_binary() failed");
        //(OGS_LOG_ERROR, bufcoded, bufcoded_len);
        free(bufcoded);
        return -1;
    }

    free(bufcoded);

    return 0;
}
#if 0
int ogs_pem_decode_curve25519_key(const char *filename, uint8_t *key)
{
    int rv;

    uint8_t buf[OGS_HUGE_LEN];
    size_t bytes_read;
    ogs_datum_t result;

#define CURVE25519_HEADER_LEN 16
    const char *_header = "302e0201 00300506 032b656e 04220420";
    uint8_t header[CURVE25519_HEADER_LEN];

    assert(filename);
    assert(key);

    rv = ogs_file_read_full(filename, buf, OGS_HUGE_LEN, &bytes_read);
    if (rv != 0) {
        //("ogs_file_read_full[%s] failed", filename);
        return -1;
    }

    rv = ogs_fbase64_decode("PRIVATE KEY", buf, bytes_read, &result);
    if (rv != 0) {
        //("ogs_fbase64_decode[%s] failed", filename);
        //(OGS_LOG_ERROR, result.data, result.size);
        return -1;
    }

    rv = 0;

    if (result.size != 48) {
        //("Invalid size [%d]", (int)result.size);
        rv = -1;
        goto cleanup;
    }

    if (memcmp(ogs_hex_from_string(_header, header, sizeof(header)),
                result.data, CURVE25519_HEADER_LEN) != 0) {
        //("Invalid header [%d]", (int)result.size);
        //(OGS_LOG_FATAL, result.data, result.size);
        rv = -1;
        goto cleanup;
    }

    memcpy(key, result.data+CURVE25519_HEADER_LEN, OGS_ECCKEY_LEN);

cleanup:
    if (result.data)
        free(result.data);

    return rv;
}

int ogs_pem_decode_secp256r1_key(const char *filename, uint8_t *key)
{
    int rv;

    uint8_t buf[OGS_HUGE_LEN];
    size_t bytes_read;
    ogs_datum_t result;

#define SECP256R1_HEADER_LEN 7
    const char *_header = "30770201 010420";
    uint8_t header[SECP256R1_HEADER_LEN];

    assert(filename);
    assert(key);

    rv = ogs_file_read_full(filename, buf, OGS_HUGE_LEN, &bytes_read);
    if (rv != 0) {
        //("ogs_file_read_full[%s] failed", filename);
        return -1;
    }

    rv = ogs_fbase64_decode("EC PRIVATE KEY", buf, bytes_read, &result);
    if (rv != 0) {
        //("ogs_fbase64_decode[%s] failed", filename);
        //(OGS_LOG_ERROR, result.data, result.size);
        return -1;
    }

    rv = 0;

    if (result.size != 121) {
        //("Invalid size [%d]", (int)result.size);
        rv = -1;
        goto cleanup;
    }

    if (memcmp(ogs_hex_from_string(_header, header, sizeof(header)),
                result.data, SECP256R1_HEADER_LEN) != 0) {
        //("Invalid header [%d]", (int)result.size);
        //(OGS_LOG_FATAL, result.data, result.size);
        rv = -1;
        goto cleanup;
    }

    memcpy(key, result.data+SECP256R1_HEADER_LEN, OGS_ECCKEY_LEN);

cleanup:
    if (result.data)
        free(result.data);

    return rv;
}
#endif










