#ifndef _CONTEXT_H
#define _CONTEXT_H
#include <stdint.h>
#include "s1ap_msg_hdr.h"

typedef struct plmn_id_s
{
    uint8_t mcc1:4;
    uint8_t mcc2:4;
    uint8_t mcc3:4;
    uint8_t mnc1:4;
    uint8_t mnc2:4;
    uint8_t mnc3:4;
}plmn_id_t;

typedef struct s1_setup_req_arg
{
    char enb_name[20];

    struct
    {
        plmn_id_t plmn_id;
        uint32_t enb_id;
    }global_enb_id;
    
    int num_supported_tas;
    struct
    {
        int nums_plmn_id;
        uint16_t tac;
        plmn_id_t plmn_id[6];
    }supported_tas[256];

}s1_setup_req_arg;

typedef struct s1_setup_res_arg
{
    char mme_name[20];
    int num_of_served_gummei;
    struct
    {
        int num_of_plmn_id;
        plmn_id_t plmn_id[32];
        int num_of_group_id;
        uint16_t mme_gid[256];
        int num_of_mme_code;
        uint8_t mme_code[256];
    }served_gummei[8];
    long relativeMMECapacity;
}s1_setup_res_arg;

typedef struct initial_uemessage_arg
{
    long end_ue_s1ap_id;
    struct
    {
        plmn_id_t plmn_id;
        uint16_t tac;
    }tai;
        
    struct
    {
        plmn_id_t plmn_id;
        uint32_t cell_id;
    }eutran_cgi;

    long id_rrc_establismnet_cause;
}initial_uemessage_arg;


int init_s1_setup_req_args(s1_setup_req_arg* args);

int init_s1_setup_res_args(s1_setup_res_arg* args);

int init_initial_uemessage_arg(initial_uemessage_arg* args);


#endif