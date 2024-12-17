#ifndef __NAS_SECURITY_H
#define __NAS_SECURITY_H

#include "ogs-nas-eps.h"
#include "core.h"

#define NAS_SECURITY_BEARER 0
#define NAS_SECURITY_MAC_SIZE 4

pkbuf_t *nas_eps_security_encode(ogs_nas_eps_message_t *message);
int nas_eps_security_decode(ogs_nas_security_header_type_t security_header_type, pkbuf_t *pkbuf);

#endif