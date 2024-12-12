#include "context.h"
#include <string.h>

int init_s1_setup_req_args(s1_setup_req_arg* args)
{
    if(!args)
        return -1;
    int i, j;
    memcpy(args->enb_name, "Yuanxin-LTE2", 13);

    args->global_enb_id.plmn_id.mcc1 = 4;
    args->global_enb_id.plmn_id.mcc2 = 6;
    args->global_enb_id.plmn_id.mcc3 = 0;
    args->global_enb_id.plmn_id.mnc1 = 15;
    args->global_enb_id.plmn_id.mnc2 = 0;
    args->global_enb_id.plmn_id.mnc3 = 5;

    args->global_enb_id.enb_id = 0x00018aee;
    args->num_supported_tas = 4;
    for(i = 0; i < args->num_supported_tas; i++)
    {
        args->supported_tas[i].nums_plmn_id = 6;
        args->supported_tas[i].tac = 0x4600;
        for(j = 0; j < args->supported_tas[i].nums_plmn_id; j++)
        {
            args->supported_tas[i].plmn_id[j].mcc1 = 4;
            args->supported_tas[i].plmn_id[j].mcc2 = 6;
            args->supported_tas[i].plmn_id[j].mcc3 = 0;
            args->supported_tas[i].plmn_id[j].mnc1 = 15;
            args->supported_tas[i].plmn_id[j].mnc2 = 0;
            args->supported_tas[i].plmn_id[j].mnc3 = 5;
        }
    }

    return 0;
}

int init_s1_setup_res_args(s1_setup_res_arg* args)
{
    if(!args)
        return -1;
    int i, j;
    memcpy(args->mme_name, "mme0", 5);

    args->num_of_served_gummei = 8;
    for(i = 0; i < args->num_of_served_gummei; i++)
    {
        (args->served_gummei[i]).num_of_group_id = 256;
        for(j = 0; j < (args->served_gummei[i]).num_of_group_id; j++)
        {
            (args->served_gummei[i]).mme_gid[j] = 0x1234;
        }

        (args->served_gummei[i]).num_of_mme_code = 256;
        for(j = 0; j < (args->served_gummei[i]).num_of_mme_code; j++)
        {
            (args->served_gummei[i]).mme_code[j] = 0x10;
        }

        (args->served_gummei[i]).num_of_plmn_id = 32;
        for(j = 0; j < (args->served_gummei[i]).num_of_plmn_id; j++)
        {
            ((args->served_gummei[i]).plmn_id[j]).mcc1 = 4;
            ((args->served_gummei[i]).plmn_id[j]).mcc2 = 6;
            ((args->served_gummei[i]).plmn_id[j]).mcc3 = 0;
            ((args->served_gummei[i]).plmn_id[j]).mnc1 = 15;
            ((args->served_gummei[i]).plmn_id[j]).mnc2 = 6;
            ((args->served_gummei[i]).plmn_id[j]).mnc3 = 5;

        }
    }
    args->relativeMMECapacity = 1;
    return 0;
}

int init_initial_uemessage_arg(initial_uemessage_arg* args)
{
    if(!args)
        return -1;

    args->end_ue_s1ap_id = 12;

    args->tai.plmn_id.mcc1 = 4;
    args->tai.plmn_id.mcc2 = 6;
    args->tai.plmn_id.mcc3 = 0;
    args->tai.plmn_id.mnc1 = 15;
    args->tai.plmn_id.mnc2 = 0;
    args->tai.plmn_id.mnc3 = 5;
    args->tai.tac = 0x9080;

    args->eutran_cgi.plmn_id.mcc1 = 4;
    args->eutran_cgi.plmn_id.mcc2 = 6;
    args->eutran_cgi.plmn_id.mcc3 = 0;
    args->eutran_cgi.plmn_id.mnc1 = 15;
    args->eutran_cgi.plmn_id.mnc2 = 0;
    args->eutran_cgi.plmn_id.mnc3 = 5;
    args->eutran_cgi.cell_id = 0x78902145;

    args->id_rrc_establismnet_cause = S1AP_RRC_Establishment_Cause_mo_Data;

    return 0;
}