#ifndef OGS_NAS_COMMON_H
#define OGS_NAS_COMMON_H

#include "../crypt/ogs-crypt.h"
#include "../core/core.h"
#include <assert.h>
#define OGS_NAS_INSIDE

#include "types.h"
#include "conv.h"
#include "security.h"

#undef OGS_NAS_INSIDE

#ifdef __cplusplus
extern "C" {
#endif

extern int __ogs_nas_domain;

#undef OGS_LOG_DOMAIN
#define OGS_LOG_DOMAIN __ogs_nas_domain

#ifdef __cplusplus
}
#endif

#endif /* OGS_NAS_COMMON_H */
