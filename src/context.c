#include "context.h"
#include <string.h>

yaml_document_t* g_document = NULL;
static enb_context_t self;

enb_context_t *enb_self(void)
{
    return &self;
}

int s1ap_plmn_id_build(plmn_id_t *plmn_id, uint16_t mcc, uint16_t mnc, uint16_t mnc_len)
{
    assert(plmn_id);

    plmn_id->mcc1 = (mcc/100) % 10;
    plmn_id->mcc2 = (mcc/10) % 10;
    plmn_id->mcc3 = mcc % 10;

    if (mnc_len == 2)
        plmn_id->mnc1 = 0xf;
    else
        plmn_id->mnc1 = (mnc/100) % 10;

    plmn_id->mnc2 = (mnc/10) % 10;
    plmn_id->mnc3 = mnc % 10;

    return 0;
}

static int yaml_documet_init(const char *filename)
{
    FILE *file;
    yaml_parser_t parser;
    yaml_document_t *document = NULL;

    file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "cannot open file `%s`", filename);
        return -1;
    }
    assert(yaml_parser_initialize(&parser));
    yaml_parser_set_input_file(&parser, file);

    document = calloc(1, sizeof(yaml_document_t));
    if (!yaml_parser_load(&parser, document)) {
        fprintf(stderr, "Failed to parse configuration file '%s'", filename);
        switch (parser.error) {
        case YAML_MEMORY_ERROR:
            fprintf(stderr, "Memory error: Not enough memory for parsing");
            break;
        case YAML_READER_ERROR:
            if (parser.problem_value != -1)
                fprintf(stderr, "Reader error - %s: #%X at %zd", parser.problem,
                    parser.problem_value, parser.problem_offset);
            else
                fprintf(stderr, "Reader error - %s at %zd", parser.problem,
                    parser.problem_offset);
            break;
        case YAML_SCANNER_ERROR:
            if (parser.context)
                fprintf(stderr, "Scanner error - %s at line %zu, column %zu "
                        "%s at line %zu, column %zu", parser.context,
                        parser.context_mark.line+1,
                        parser.context_mark.column+1,
                        parser.problem, parser.problem_mark.line+1,
                        parser.problem_mark.column+1);
            else
                fprintf(stderr, "Scanner error - %s at line %zu, column %zu",
                        parser.problem, parser.problem_mark.line+1,
                        parser.problem_mark.column+1);
            break;
        case YAML_PARSER_ERROR:
            if (parser.context)
                fprintf(stderr, "Parser error - %s at line %zu, column %zu "
                        "%s at line %zu, column %zu", parser.context,
                        parser.context_mark.line+1,
                        parser.context_mark.column+1,
                        parser.problem, parser.problem_mark.line+1,
                        parser.problem_mark.column+1);
            else
                fprintf(stderr, "Parser error - %s at line %zu, column %zu",
                        parser.problem, parser.problem_mark.line+1,
                        parser.problem_mark.column+1);
            break;
        default:
            /* Couldn't happen. */
            abort();
            break;
        }

        free(document);
        yaml_parser_delete(&parser);
        assert(!fclose(file));
        return -1;
    }

    g_document = document;

    yaml_parser_delete(&parser);
    assert(!fclose(file));

    return 0;
}

void enb_context_init(const char* name)
{
    memset(enb_self(), 0, sizeof(enb_context_t));
    enb_self()->enb_name = (char *)malloc(100);
    yaml_documet_init(name);
}

int s1ap_context_parse_config(const char* name)
{
    yaml_document_t *document = g_document;
    assert(document);

    int rv;
    yaml_iter_t root_iter;
    yaml_iter_init(&root_iter, g_document);
    while(yaml_iter_next(&root_iter))
    {
        const char *root_key = yaml_iter_key(&root_iter);
        assert(root_key);
        printf("root node = %s\n", root_key);
        if(!strcmp(root_key, "enb"))
        {
            yaml_iter_t enb_iter;
            yaml_iter_recurse(&root_iter, &enb_iter);
            while(yaml_iter_next(&enb_iter))
            {
                const char *enb_key = yaml_iter_key(&enb_iter);
                assert(enb_key);
                printf("enb: node = %s\n", enb_key);

                // ========================================================================
                if(!strcmp(enb_key, "enb_name"))
                {
                    const char* enb_name = yaml_iter_value(&enb_iter);
                    memcpy(enb_self()->enb_name, enb_name, strlen(enb_name)+1);
                }
                else if(!strcmp(enb_key, "enb_ue_s1ap_id"))
                {
                    uint32_t enb_ue_s1ap_id = atoi(yaml_iter_value(&enb_iter));
                    
                    enb_self()->enb_ue_s1ap_id = enb_ue_s1ap_id;
                }
                else if(!strcmp(enb_key, "global_enb_id"))
                {
                    yaml_iter_t gei_iter;
                    yaml_iter_recurse(&enb_iter, &gei_iter);
                    while(yaml_iter_next(&gei_iter))
                    {
                        const char *gei_key = yaml_iter_key(&gei_iter);
                        if(!strcmp(gei_key, "plmn_id"))
                        {
                            yaml_iter_t plmn_id_iter;
                            yaml_iter_recurse(&gei_iter, &plmn_id_iter);
                            const char *mnc = NULL;
                            const char *mcc = NULL;
                            plmn_id_t *plmn_id = &enb_self()->global_enb_id.plmn_id;
                            while(yaml_iter_next(&plmn_id_iter))
                            {
                                const char *plmn_id_key = yaml_iter_key(&plmn_id_iter);
                                if(!strcmp(plmn_id_key, "mcc"))
                                {
                                    mcc = yaml_iter_value(&plmn_id_iter);

                                }
                                else if(!strcmp(plmn_id_key, "mnc"))
                                {
                                    mnc = yaml_iter_value(&plmn_id_iter);
                                }
                                
                            }
                            if(mnc && mnc)
                            {
                                s1ap_plmn_id_build(plmn_id, atoi(mcc), atoi(mnc), strlen(mnc));
                            }
                        }
                        else if(!strcmp(gei_key, "enb_id"))
                        {
                            const char* enb_id = yaml_iter_value(&gei_iter);
                            enb_self()->global_enb_id.enb_id = atoi(enb_id);
                        }
                    }
                }
                else if(!strcmp(enb_key, "supported_tas"))
                {
                    yaml_iter_t sptas_iter;
                    yaml_iter_recurse(&enb_iter, &sptas_iter);
                    int *num_supported_tas = &enb_self()->num_supported_tas;
                    do
                    {
                        int *nums_plmn_id = &enb_self()->supported_tas[*num_supported_tas].nums_plmn_id;
                        yaml_iter_t plmn_id_iter;
                        if(yaml_iter_type(&sptas_iter) == YAML_SEQUENCE_NODE)
                        {
                            if (!yaml_iter_next(&sptas_iter))
                                break;
                            yaml_iter_recurse(&sptas_iter, &plmn_id_iter);
                        }
                        while(yaml_iter_next(&plmn_id_iter))
                        {
                            const char *plmn_id_key = yaml_iter_key(&plmn_id_iter);
                            printf("%s ", plmn_id_key);
                            
                            if(!strcmp(plmn_id_key, "plmn_id"))
                            {
                                yaml_iter_t mmc_iter;
                                yaml_iter_recurse(&plmn_id_iter, &mmc_iter);
                                const char* mnc = NULL;
                                const char* mcc = NULL;
                                // int *nums_plmn_id = &enb_self()->supported_tas->nums_plmn_id;
                                plmn_id_t* plmn_id = &enb_self()->supported_tas[*num_supported_tas].plmn_id[*nums_plmn_id];
                                while(yaml_iter_next(&mmc_iter))
                                {
                                    const char *plmn_id_key = yaml_iter_key(&mmc_iter);
                                    if(!strcmp(plmn_id_key, "mcc"))
                                    {
                                        mcc = yaml_iter_value(&mmc_iter);

                                    }
                                    else if(!strcmp(plmn_id_key, "mnc"))
                                    {
                                        mnc = yaml_iter_value(&mmc_iter);
                                    }
                                    
                                }
                                if(mnc && mnc)
                                {
                                    s1ap_plmn_id_build(plmn_id, atoi(mcc), atoi(mnc), strlen(mnc));
                                    (*nums_plmn_id)++;
                                }
                            }
                            else if(!strcmp(plmn_id_key, "tac"))
                            {
                                const char* tac = yaml_iter_value(&plmn_id_iter);
                                enb_self()->supported_tas[*num_supported_tas].tac = atoi(tac);
                            }
                        }
                        (*num_supported_tas)++;
                    }while(yaml_iter_type(&sptas_iter) == YAML_SEQUENCE_NODE);
                    
                }
                else if(!strcmp(enb_key, "eutran_cgi"))
                {
                    yaml_iter_t ecgi_iter;
                    yaml_iter_recurse(&enb_iter, &ecgi_iter);
                    while(yaml_iter_next(&ecgi_iter))
                    {
                        const char *ecgi_key = yaml_iter_key(&ecgi_iter);
                        if(!strcmp(ecgi_key, "plmn_id"))
                        {
                            
                            yaml_iter_t plmn_id_iter;
                            yaml_iter_recurse(&ecgi_iter, &plmn_id_iter);
                            const char* mnc = NULL;
                            const char* mcc = NULL;
                            plmn_id_t* plmn_id = &enb_self()->eutran_cgi.plmn_id;
                            while(yaml_iter_next(&plmn_id_iter))
                            {
                                const char *plmn_id_key = yaml_iter_key(&plmn_id_iter);
                                if(!strcmp(plmn_id_key, "mcc"))
                                {
                                    mcc = yaml_iter_value(&plmn_id_iter);
                                }
                                else if(!strcmp(plmn_id_key, "mnc"))
                                {
                                    mnc = yaml_iter_value(&plmn_id_iter);
                                }

                            }
                            if(mnc && mnc)
                            {
                                s1ap_plmn_id_build(plmn_id, atoi(mcc), atoi(mnc), strlen(mnc));
                            }
                        }
                        else if(!strcmp(ecgi_key, "cell_id"))
                        {
                            const char* cell_id = yaml_iter_value(&ecgi_iter);
                            enb_self()->eutran_cgi.cell_id = atoi(cell_id);
                        }
                    }
                }
                #if 0
                else if(!strcmp(enb_key, "gummei"))
                {
                    yaml_iter_t gummei_iter;
                    yaml_iter_recurse(&enb_iter, &gummei_iter);
                    // int *nums_
                    do
                    {
                        yaml_iter_t plmn_id_iter;
                        if(yaml_iter_type(&gummei_iter) == YAML_SEQUENCE_NODE)
                        {
                            if (!yaml_iter_next(&gummei_iter))
                                break;
                            yaml_iter_recurse(&gummei_iter, &plmn_id_iter);
                        }

                        while(yaml_iter_next(&plmn_id_iter))
                        {
                            const char *plmn_id_key = yaml_iter_key(&plmn_id_iter);
                            printf("%s ", plmn_id_key);
                            if(!strcmp(plmn_id_key, "plmn_id"))
                            {
                                yaml_iter_t mmc_iter;
                                yaml_iter_recurse(&plmn_id_iter, &mmc_iter);

                                while(yaml_iter_next(&mmc_iter))
                                {
                                    const char *mmc_key = yaml_iter_key(&mmc_iter);
                                    printf("%s ", mmc_key);

                                }
                            }
                            else if(!strcmp(plmn_id_key, "mme_gid"))
                            {
                                
                            }
                            else if(!strcmp(plmn_id_key, "mme_code"))
                            {
                                
                            }
                        }

                        
                    }while(yaml_iter_type(&gummei_iter) == YAML_SEQUENCE_NODE);

                }
                #endif
                else if(!strcmp(enb_key, "tai"))
                {
                    yaml_iter_t tai_iter;
                    yaml_iter_recurse(&enb_iter, &tai_iter);
                    while(yaml_iter_next(&tai_iter))
                    {
                        const char *tai_key = yaml_iter_key(&tai_iter);
                        if(!strcmp(tai_key, "plmn_id"))
                        {
                            yaml_iter_t plmn_id_iter;
                            yaml_iter_recurse(&tai_iter, &plmn_id_iter);
                            const char* mnc = NULL;
                            const char* mcc = NULL;
                            plmn_id_t* plmn_id = &enb_self()->tai.plmn_id;
                            while(yaml_iter_next(&plmn_id_iter))
                            {
                                const char *plmn_id_key = yaml_iter_key(&plmn_id_iter);
                                if(!strcmp(plmn_id_key, "mcc"))
                                {
                                    mcc = yaml_iter_value(&plmn_id_iter);

                                }
                                else if(!strcmp(plmn_id_key, "mnc"))
                                {
                                    mnc = yaml_iter_value(&plmn_id_iter);
                                }

                            }
                            if(mnc && mnc)
                            {
                                s1ap_plmn_id_build(plmn_id, atoi(mcc), atoi(mnc), strlen(mnc));
                            }
                        }
                        else if(!strcmp(tai_key, "tac"))
                        {
                            const char* tac = yaml_iter_value(&tai_iter);
                            enb_self()->tai.tac = atoi(tac);
                        }
                    }
                }
               
            }
        }
    }

    return 0;

}

int init_s1_setup_req_args(s1_setup_req_arg* args)
{
    if(!args)
        return -1;
    int i, j;
    memcpy(args->enb_name, enb_self()->enb_name, strlen(enb_self()->enb_name));
    #if 0
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
    #endif
    memcpy(&args->global_enb_id, &enb_self()->global_enb_id, sizeof(enb_self()->global_enb_id));
    args->num_supported_tas = enb_self()->num_supported_tas;
    memcpy(&args->supported_tas, &enb_self()->supported_tas, sizeof(enb_self()->supported_tas));


    return 0;
}

int init_s1_setup_res_args(s1_setup_res_arg* args)
{
    if(!args)
        return -1;
    int i, j;
    
    memcpy(args->mme_name, "mme0", 5);

    args->num_of_served_gummei = 4;
    for(i = 0; i < args->num_of_served_gummei; i++)
    {
        (args->served_gummei[i]).num_of_group_id = 10;
        for(j = 0; j < (args->served_gummei[i]).num_of_group_id; j++)
        {
            (args->served_gummei[i]).mme_gid[j] = 0x1234;
        }

        (args->served_gummei[i]).num_of_mme_code = 10;
        for(j = 0; j < (args->served_gummei[i]).num_of_mme_code; j++)
        {
            (args->served_gummei[i]).mme_code[j] = 0x10;
        }

        (args->served_gummei[i]).num_of_plmn_id = 4;
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
    #if 0
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
    #else
    args->end_ue_s1ap_id = enb_self()->enb_ue_s1ap_id;
    memcpy(&args->tai, &enb_self()->tai, sizeof(args->tai));
    memcpy(&args->eutran_cgi, &enb_self()->eutran_cgi, sizeof(enb_self()->eutran_cgi));
    args->id_rrc_establismnet_cause = S1AP_RRC_Establishment_Cause_mo_Data;
    #endif
    return 0;
}