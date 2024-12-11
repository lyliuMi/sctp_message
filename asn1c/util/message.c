/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "message.h"

pkbuf_t* asn_encode_custom(const asn_TYPE_descriptor_t *td, void *sptr)
{
    asn_enc_rval_t enc_ret = {0};
    pkbuf_t *pkbuf = NULL;

    assert(td);
    assert(sptr);

    pkbuf = pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    if (!pkbuf) {
        // ogs_error("ogs_pkbuf_alloc() failed");
        return NULL;
    }
    pkbuf_put(pkbuf, OGS_MAX_SDU_LEN);

    enc_ret = aper_encode_to_buffer(td, NULL,
                    sptr, pkbuf->data, OGS_MAX_SDU_LEN);
    asn_free_custom(td, sptr);

    if (enc_ret.encoded < 0) {
        // ogs_error("Failed to encode ASN-PDU [%d]", (int)enc_ret.encoded);
        pkbuf_free(pkbuf);
        return NULL;
    }

    pkbuf_trim(pkbuf, ((enc_ret.encoded + 7) >> 3));

    return pkbuf;
}

int asn_decode_custom(const asn_TYPE_descriptor_t *td,
        void *struct_ptr, size_t struct_size, pkbuf_t *pkbuf)
{
    asn_dec_rval_t dec_ret = {0};

    assert(td);
    assert(struct_ptr);
    assert(struct_size);
    assert(pkbuf);
    assert(pkbuf->data);
    assert(pkbuf->len);

    memset(struct_ptr, 0, struct_size);
    dec_ret = aper_decode(NULL, td, (void **)&struct_ptr,
            pkbuf->data, pkbuf->len, 0, 0);

    if (dec_ret.code != RC_OK) {
        // ogs_warn("Failed to decode ASN-PDU [code:%d,consumed:%d]",
        //         dec_ret.code, (int)dec_ret.consumed);
        return -1;
    }

    return 0;
}

void asn_free_custom(const asn_TYPE_descriptor_t *td, void *sptr)
{
    assert(td);
    assert(sptr);

    ASN_STRUCT_FREE_CONTENTS_ONLY(*td, sptr);
}
