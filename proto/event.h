#ifndef OGS_PROTO_EVENT_H
#define OGS_PROTO_EVENT_H

#if 0

#include "ogs-proto.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char *OGS_EVENT_NAME_SBI_SERVER;
extern const char *OGS_EVENT_NAME_SBI_CLIENT;
extern const char *OGS_EVENT_NAME_SBI_TIMER;

typedef enum {
    OGS_EVENT_BASE = OGS_FSM_USER_SIG,

    OGS_EVENT_SBI_SERVER,
    OGS_EVENT_SBI_CLIENT,
    OGS_EVENT_SBI_TIMER,

    OGS_MAX_NUM_OF_PROTO_EVENT,

} ogs_event_e;

typedef struct ogs_sbi_request_s ogs_sbi_request_t;
typedef struct ogs_sbi_response_s ogs_sbi_response_t;
typedef struct ogs_sbi_message_s ogs_sbi_message_t;

typedef struct ogs_event_s {
    int id;
    int timer_id;

    struct {
        ogs_sbi_request_t *request;
        ogs_sbi_response_t *response;
        void *data;
        int state;

        ogs_sbi_message_t *message;
    } sbi;

} ogs_event_t;

#define OGS_EVENT_SIZE 256

void *ogs_event_size(int id, size_t size);
ogs_event_t *ogs_event_new(int id);
void ogs_event_free(void *e);

const char *ogs_event_get_name(ogs_event_t *e);

#ifdef __cplusplus
}
#endif

#endif

#endif /* OGS_PROTO_EVENT_H */
