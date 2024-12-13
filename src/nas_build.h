#ifndef __NAS_BUILD_H
#define __NAS_BUILD_H

#include "ogs-nas-eps.h"
#include "core.h"

pkbuf_t* nas_build_attach_request();

pkbuf_t* nas_build_detach_request();


pkbuf_t *nas_build_identity_request();

pkbuf_t *nas_build_service_reject(ogs_nas_emm_cause_t emm_cause);
#endif