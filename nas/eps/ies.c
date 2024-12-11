/*
 * The MIT License
 *
 * Copyright (C) 2019-2023 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*******************************************************************************
 * This file had been created by nas-message.py script v0.1.0
 * Please do not modify this file but regenerate it via script.
 * Created on: 2024-01-21 18:50:03.402793 by acetcom
 * from 24301-h90.docx
 ******************************************************************************/

#include "ogs-nas-eps.h"

int ogs_nas_eps_encode_optional_type(pkbuf_t *pkbuf, uint8_t type)
{
    int size = sizeof(uint8_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &type, size);

    return size;
}
/* 9.9.2.0 Additional information
 * O TLV 3-n */
int ogs_nas_eps_decode_additional_information(ogs_nas_additional_information_t *additional_information, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_additional_information_t *source = (ogs_nas_additional_information_t *)pkbuf->data;

    additional_information->length = source->length;
    size = additional_information->length + sizeof(additional_information->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
    //    //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*additional_information) < size) return -1;
    memcpy(additional_information, pkbuf->data - size, size);

    // //("  ADDITIONAL_INFORMATION - ");
    // //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_additional_information(pkbuf_t *pkbuf, ogs_nas_additional_information_t *additional_information)
{
    int size = additional_information->length + sizeof(additional_information->length);
    ogs_nas_additional_information_t target;

    memcpy(&target, additional_information, sizeof(ogs_nas_additional_information_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    // //("  ADDITIONAL_INFORMATION - ");
    // //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.0A Device properties
 * O TV 1 */
int ogs_nas_eps_decode_device_properties(ogs_nas_device_properties_t *device_properties, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_device_properties_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
    //    //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(device_properties, pkbuf->data - size, size);

    // //("  DEVICE_PROPERTIES - ");
    // //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_device_properties(pkbuf_t *pkbuf, ogs_nas_device_properties_t *device_properties)
{
    int size = sizeof(ogs_nas_device_properties_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, device_properties, size);

    // //("  DEVICE_PROPERTIES - ");
    // //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.1 EPS bearer context status
 * O TLV 4 */
int ogs_nas_eps_decode_eps_bearer_context_status(ogs_nas_eps_bearer_context_status_t *eps_bearer_context_status, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_bearer_context_status_t *source = (ogs_nas_eps_bearer_context_status_t *)pkbuf->data;

    eps_bearer_context_status->length = source->length;
    size = eps_bearer_context_status->length + sizeof(eps_bearer_context_status->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_bearer_context_status) < size) return -1;
    memcpy(eps_bearer_context_status, pkbuf->data - size, size);

    //pkbuf_("  EPS_BEARER_CONTEXT_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_bearer_context_status(pkbuf_t *pkbuf, ogs_nas_eps_bearer_context_status_t *eps_bearer_context_status)
{
    int size = eps_bearer_context_status->length + sizeof(eps_bearer_context_status->length);
    ogs_nas_eps_bearer_context_status_t target;

    memcpy(&target, eps_bearer_context_status, sizeof(ogs_nas_eps_bearer_context_status_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //pkbuf_("  EPS_BEARER_CONTEXT_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.10 Supported Codec List
 * O TLV 5-n */
int ogs_nas_eps_decode_supported_codec_list(ogs_nas_supported_codec_list_t *supported_codec_list, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_supported_codec_list_t *source = (ogs_nas_supported_codec_list_t *)pkbuf->data;

    supported_codec_list->length = source->length;
    size = supported_codec_list->length + sizeof(supported_codec_list->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*supported_codec_list) < size) return -1;
    memcpy(supported_codec_list, pkbuf->data - size, size);

    //("  SUPPORTED_CODEC_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_supported_codec_list(pkbuf_t *pkbuf, ogs_nas_supported_codec_list_t *supported_codec_list)
{
    int size = supported_codec_list->length + sizeof(supported_codec_list->length);
    ogs_nas_supported_codec_list_t target;

    memcpy(&target, supported_codec_list, sizeof(ogs_nas_supported_codec_list_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SUPPORTED_CODEC_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.2 Location area identification
 * O TV 6 */
int ogs_nas_eps_decode_location_area_identification(ogs_nas_location_area_identification_t *location_area_identification, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_location_area_identification_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(location_area_identification, pkbuf->data - size, size);

    location_area_identification->lac = be16toh(location_area_identification->lac);

    //("  LOCATION_AREA_IDENTIFICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_location_area_identification(pkbuf_t *pkbuf, ogs_nas_location_area_identification_t *location_area_identification)
{
    int size = sizeof(ogs_nas_location_area_identification_t);
    ogs_nas_location_area_identification_t target;

    memcpy(&target, location_area_identification, size);
    target.lac = htobe16(location_area_identification->lac);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  LOCATION_AREA_IDENTIFICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.3 Mobile identity
 * O TLV 7-10 */
int ogs_nas_eps_decode_mobile_identity(ogs_nas_mobile_identity_t *mobile_identity, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_mobile_identity_t *source = (ogs_nas_mobile_identity_t *)pkbuf->data;

    mobile_identity->length = source->length;
    size = mobile_identity->length + sizeof(mobile_identity->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*mobile_identity) < size) return -1;
    memcpy(mobile_identity, pkbuf->data - size, size);

    if (mobile_identity->tmsi.type == OGS_NAS_MOBILE_IDENTITY_TMSI) {
        mobile_identity->tmsi.tmsi = be32toh(mobile_identity->tmsi.tmsi);
    }

    //("  MOBILE_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_mobile_identity(pkbuf_t *pkbuf, ogs_nas_mobile_identity_t *mobile_identity)
{
    int size = mobile_identity->length + sizeof(mobile_identity->length);
    ogs_nas_mobile_identity_t target;

    memcpy(&target, mobile_identity, sizeof(ogs_nas_mobile_identity_t));
    if (mobile_identity->tmsi.type == OGS_NAS_MOBILE_IDENTITY_TMSI) {
        target.tmsi.tmsi = htobe32(mobile_identity->tmsi.tmsi);
        target.tmsi.spare = 0xf;
    }

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  MOBILE_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.4 Mobile station classmark 2
 * O TLV 5 */
int ogs_nas_eps_decode_mobile_station_classmark_2(ogs_nas_mobile_station_classmark_2_t *mobile_station_classmark_2, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_mobile_station_classmark_2_t *source = (ogs_nas_mobile_station_classmark_2_t *)pkbuf->data;

    mobile_station_classmark_2->length = source->length;
    size = mobile_station_classmark_2->length + sizeof(mobile_station_classmark_2->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*mobile_station_classmark_2) < size) return -1;
    memcpy(mobile_station_classmark_2, pkbuf->data - size, size);

    //("  MOBILE_STATION_CLASSMARK_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_mobile_station_classmark_2(pkbuf_t *pkbuf, ogs_nas_mobile_station_classmark_2_t *mobile_station_classmark_2)
{
    int size = mobile_station_classmark_2->length + sizeof(mobile_station_classmark_2->length);
    ogs_nas_mobile_station_classmark_2_t target;

    memcpy(&target, mobile_station_classmark_2, sizeof(ogs_nas_mobile_station_classmark_2_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  MOBILE_STATION_CLASSMARK_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.5 Mobile station classmark 3
 * O TLV 2-34 */
int ogs_nas_eps_decode_mobile_station_classmark_3(ogs_nas_mobile_station_classmark_3_t *mobile_station_classmark_3, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_mobile_station_classmark_3_t *source = (ogs_nas_mobile_station_classmark_3_t *)pkbuf->data;

    mobile_station_classmark_3->length = source->length;
    size = mobile_station_classmark_3->length + sizeof(mobile_station_classmark_3->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*mobile_station_classmark_3) < size) return -1;
    memcpy(mobile_station_classmark_3, pkbuf->data - size, size);

    //("  MOBILE_STATION_CLASSMARK_3 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_mobile_station_classmark_3(pkbuf_t *pkbuf, ogs_nas_mobile_station_classmark_3_t *mobile_station_classmark_3)
{
    int size = mobile_station_classmark_3->length + sizeof(mobile_station_classmark_3->length);
    ogs_nas_mobile_station_classmark_3_t target;

    memcpy(&target, mobile_station_classmark_3, sizeof(ogs_nas_mobile_station_classmark_3_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  MOBILE_STATION_CLASSMARK_3 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.2.8 PLMN list
 * O TLV 5-47 */
int ogs_nas_eps_decode_plmn_list(ogs_nas_plmn_list_t *plmn_list, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_plmn_list_t *source = (ogs_nas_plmn_list_t *)pkbuf->data;

    plmn_list->length = source->length;
    size = plmn_list->length + sizeof(plmn_list->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*plmn_list) < size) return -1;
    memcpy(plmn_list, pkbuf->data - size, size);

    //("  PLMN_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_plmn_list(pkbuf_t *pkbuf, ogs_nas_plmn_list_t *plmn_list)
{
    int size = plmn_list->length + sizeof(plmn_list->length);
    ogs_nas_plmn_list_t target;

    memcpy(&target, plmn_list, sizeof(ogs_nas_plmn_list_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PLMN_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.0A Additional update result
 * O TV 1 */
int ogs_nas_eps_decode_additional_update_result(ogs_nas_additional_update_result_t *additional_update_result, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_additional_update_result_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(additional_update_result, pkbuf->data - size, size);

    //("  ADDITIONAL_UPDATE_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_additional_update_result(pkbuf_t *pkbuf, ogs_nas_additional_update_result_t *additional_update_result)
{
    int size = sizeof(ogs_nas_additional_update_result_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, additional_update_result, size);

    //("  ADDITIONAL_UPDATE_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.0B Additional update type
 * O TV 1 */
int ogs_nas_eps_decode_additional_update_type(ogs_nas_additional_update_type_t *additional_update_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_additional_update_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(additional_update_type, pkbuf->data - size, size);

    //("  ADDITIONAL_UPDATE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_additional_update_type(pkbuf_t *pkbuf, ogs_nas_additional_update_type_t *additional_update_type)
{
    int size = sizeof(ogs_nas_additional_update_type_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, additional_update_type, size);

    //("  ADDITIONAL_UPDATE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.1 Authentication failure parameter
 * O TLV 16 */
int ogs_nas_eps_decode_authentication_failure_parameter(ogs_nas_authentication_failure_parameter_t *authentication_failure_parameter, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_authentication_failure_parameter_t *source = (ogs_nas_authentication_failure_parameter_t *)pkbuf->data;

    authentication_failure_parameter->length = source->length;
    size = authentication_failure_parameter->length + sizeof(authentication_failure_parameter->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*authentication_failure_parameter) < size) return -1;
    memcpy(authentication_failure_parameter, pkbuf->data - size, size);

    //("  AUTHENTICATION_FAILURE_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_authentication_failure_parameter(pkbuf_t *pkbuf, ogs_nas_authentication_failure_parameter_t *authentication_failure_parameter)
{
    int size = authentication_failure_parameter->length + sizeof(authentication_failure_parameter->length);
    ogs_nas_authentication_failure_parameter_t target;

    memcpy(&target, authentication_failure_parameter, sizeof(ogs_nas_authentication_failure_parameter_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  AUTHENTICATION_FAILURE_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.10 EPS attach result
 * M V 1/2 */
int ogs_nas_eps_decode_eps_attach_result(ogs_nas_eps_attach_result_t *eps_attach_result, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_eps_attach_result_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(eps_attach_result, pkbuf->data - size, size);

    //("  EPS_ATTACH_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_attach_result(pkbuf_t *pkbuf, ogs_nas_eps_attach_result_t *eps_attach_result)
{
    int size = sizeof(ogs_nas_eps_attach_result_t);
    ogs_nas_eps_attach_result_t target;

    memcpy(&target, eps_attach_result, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_ATTACH_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.11 EPS attach type
 * M V 1/2 */
int ogs_nas_eps_decode_eps_attach_type(ogs_nas_eps_attach_type_t *eps_attach_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_eps_attach_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(eps_attach_type, pkbuf->data - size, size);

    //("  EPS_ATTACH_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_attach_type(pkbuf_t *pkbuf, ogs_nas_eps_attach_type_t *eps_attach_type)
{
    int size = sizeof(ogs_nas_eps_attach_type_t);
    ogs_nas_eps_attach_type_t target;

    memcpy(&target, eps_attach_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_ATTACH_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.12 EPS mobile identity
 * M LV 5-12 */
int ogs_nas_eps_decode_eps_mobile_identity(ogs_nas_eps_mobile_identity_t *eps_mobile_identity, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_mobile_identity_t *source = (ogs_nas_eps_mobile_identity_t *)pkbuf->data;

    eps_mobile_identity->length = source->length;
    size = eps_mobile_identity->length + sizeof(eps_mobile_identity->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_mobile_identity) < size) return -1;
    memcpy(eps_mobile_identity, pkbuf->data - size, size);

    if (eps_mobile_identity->guti.type == OGS_NAS_EPS_MOBILE_IDENTITY_GUTI) {
        eps_mobile_identity->guti.mme_gid = be16toh(eps_mobile_identity->guti.mme_gid);
        eps_mobile_identity->guti.m_tmsi = be32toh(eps_mobile_identity->guti.m_tmsi);
    }

    //("  EPS_MOBILE_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_mobile_identity(pkbuf_t *pkbuf, ogs_nas_eps_mobile_identity_t *eps_mobile_identity)
{
    int size = eps_mobile_identity->length + sizeof(eps_mobile_identity->length);
    ogs_nas_eps_mobile_identity_t target;

    memcpy(&target, eps_mobile_identity, sizeof(ogs_nas_eps_mobile_identity_t));
    if (target.guti.type == OGS_NAS_EPS_MOBILE_IDENTITY_GUTI) {
        target.guti.spare = 0xf;
        target.guti.mme_gid = htobe16(eps_mobile_identity->guti.mme_gid);
        target.guti.m_tmsi = htobe32(eps_mobile_identity->guti.m_tmsi);
    }

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_MOBILE_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.12A EPS network feature support
 * O TLV 3-4 */
int ogs_nas_eps_decode_eps_network_feature_support(ogs_nas_eps_network_feature_support_t *eps_network_feature_support, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_network_feature_support_t *source = (ogs_nas_eps_network_feature_support_t *)pkbuf->data;

    eps_network_feature_support->length = source->length;
    size = eps_network_feature_support->length + sizeof(eps_network_feature_support->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_network_feature_support) < size) return -1;
    memcpy(eps_network_feature_support, pkbuf->data - size, size);

    //("  EPS_NETWORK_FEATURE_SUPPORT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_network_feature_support(pkbuf_t *pkbuf, ogs_nas_eps_network_feature_support_t *eps_network_feature_support)
{
    int size = eps_network_feature_support->length + sizeof(eps_network_feature_support->length);
    ogs_nas_eps_network_feature_support_t target;

    memcpy(&target, eps_network_feature_support, sizeof(ogs_nas_eps_network_feature_support_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_NETWORK_FEATURE_SUPPORT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.13 EPS update result
 * M V 1/2 */
int ogs_nas_eps_decode_eps_update_result(ogs_nas_eps_update_result_t *eps_update_result, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_eps_update_result_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(eps_update_result, pkbuf->data - size, size);

    //("  EPS_UPDATE_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_update_result(pkbuf_t *pkbuf, ogs_nas_eps_update_result_t *eps_update_result)
{
    int size = sizeof(ogs_nas_eps_update_result_t);
    ogs_nas_eps_update_result_t target;

    memcpy(&target, eps_update_result, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_UPDATE_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.14 EPS update type
 * M V 1/2 */
int ogs_nas_eps_decode_eps_update_type(ogs_nas_eps_update_type_t *eps_update_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_eps_update_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(eps_update_type, pkbuf->data - size, size);

    //("  EPS_UPDATE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_update_type(pkbuf_t *pkbuf, ogs_nas_eps_update_type_t *eps_update_type)
{
    int size = sizeof(ogs_nas_eps_update_type_t);
    ogs_nas_eps_update_type_t target;

    memcpy(&target, eps_update_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_UPDATE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.15 ESM message container
 * M LV-E 5-n */
int ogs_nas_eps_decode_esm_message_container(ogs_nas_esm_message_container_t *esm_message_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_esm_message_container_t *source = (ogs_nas_esm_message_container_t *)pkbuf->data;

    esm_message_container->length = be16toh(source->length);
    size = esm_message_container->length + sizeof(esm_message_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    esm_message_container->buffer = pkbuf->data - size + sizeof(esm_message_container->length);

    //("  ESM_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, (void*)esm_message_container->buffer, esm_message_container->length);

    return size;
}

int ogs_nas_eps_encode_esm_message_container(pkbuf_t *pkbuf, ogs_nas_esm_message_container_t *esm_message_container)
{
    int size = 0;
    int target;

    assert(esm_message_container);
    assert(esm_message_container->buffer);

    size = sizeof(esm_message_container->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(esm_message_container->length);
    memcpy(pkbuf->data - size, &target, size);

    size = esm_message_container->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, esm_message_container->buffer, size);

    //("  ESM_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return esm_message_container->length + sizeof(esm_message_container->length);
}

/* 9.9.3.16 GPRS timer
 * M V 1 */
int ogs_nas_eps_decode_gprs_timer(ogs_nas_gprs_timer_t *gprs_timer, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_gprs_timer_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(gprs_timer, pkbuf->data - size, size);

    //("  GPRS_TIMER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_gprs_timer(pkbuf_t *pkbuf, ogs_nas_gprs_timer_t *gprs_timer)
{
    int size = sizeof(ogs_nas_gprs_timer_t);
    ogs_nas_gprs_timer_t target;

    memcpy(&target, gprs_timer, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  GPRS_TIMER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.16A GPRS timer 2
 * O TLV 3 */
int ogs_nas_eps_decode_gprs_timer_2(ogs_nas_gprs_timer_2_t *gprs_timer_2, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_gprs_timer_2_t *source = (ogs_nas_gprs_timer_2_t *)pkbuf->data;

    gprs_timer_2->length = source->length;
    size = gprs_timer_2->length + sizeof(gprs_timer_2->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*gprs_timer_2) < size) return -1;
    memcpy(gprs_timer_2, pkbuf->data - size, size);

    //("  GPRS_TIMER_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_gprs_timer_2(pkbuf_t *pkbuf, ogs_nas_gprs_timer_2_t *gprs_timer_2)
{
    int size = gprs_timer_2->length + sizeof(gprs_timer_2->length);
    ogs_nas_gprs_timer_2_t target;

    memcpy(&target, gprs_timer_2, sizeof(ogs_nas_gprs_timer_2_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  GPRS_TIMER_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.16B GPRS timer 3
 * O TLV 3 */
int ogs_nas_eps_decode_gprs_timer_3(ogs_nas_gprs_timer_3_t *gprs_timer_3, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_gprs_timer_3_t *source = (ogs_nas_gprs_timer_3_t *)pkbuf->data;

    gprs_timer_3->length = source->length;
    size = gprs_timer_3->length + sizeof(gprs_timer_3->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*gprs_timer_3) < size) return -1;
    memcpy(gprs_timer_3, pkbuf->data - size, size);

    //("  GPRS_TIMER_3 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_gprs_timer_3(pkbuf_t *pkbuf, ogs_nas_gprs_timer_3_t *gprs_timer_3)
{
    int size = gprs_timer_3->length + sizeof(gprs_timer_3->length);
    ogs_nas_gprs_timer_3_t target;

    memcpy(&target, gprs_timer_3, sizeof(ogs_nas_gprs_timer_3_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  GPRS_TIMER_3 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.17 Identity type 2
 * M V 1/2 */
int ogs_nas_eps_decode_identity_type_2(ogs_nas_identity_type_2_t *identity_type_2, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_identity_type_2_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(identity_type_2, pkbuf->data - size, size);

    //("  IDENTITY_TYPE_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_identity_type_2(pkbuf_t *pkbuf, ogs_nas_identity_type_2_t *identity_type_2)
{
    int size = sizeof(ogs_nas_identity_type_2_t);
    ogs_nas_identity_type_2_t target;

    memcpy(&target, identity_type_2, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  IDENTITY_TYPE_2 - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.18 IMEISV request
 * O TV 1 */
int ogs_nas_eps_decode_imeisv_request(ogs_nas_imeisv_request_t *imeisv_request, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_imeisv_request_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(imeisv_request, pkbuf->data - size, size);

    //("  IMEISV_REQUEST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_imeisv_request(pkbuf_t *pkbuf, ogs_nas_imeisv_request_t *imeisv_request)
{
    int size = sizeof(ogs_nas_imeisv_request_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, imeisv_request, size);

    //("  IMEISV_REQUEST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.19 KSI and sequence number
 * M V 1 */
int ogs_nas_eps_decode_ksi_and_sequence_number(ogs_nas_ksi_and_sequence_number_t *ksi_and_sequence_number, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ksi_and_sequence_number_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ksi_and_sequence_number, pkbuf->data - size, size);

    //("  KSI_AND_SEQUENCE_NUMBER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ksi_and_sequence_number(pkbuf_t *pkbuf, ogs_nas_ksi_and_sequence_number_t *ksi_and_sequence_number)
{
    int size = sizeof(ogs_nas_ksi_and_sequence_number_t);
    ogs_nas_ksi_and_sequence_number_t target;

    memcpy(&target, ksi_and_sequence_number, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  KSI_AND_SEQUENCE_NUMBER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.2 Authentication parameter AUTN
 * M LV 17 */
int ogs_nas_eps_decode_authentication_parameter_autn(ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_authentication_parameter_autn_t *source = (ogs_nas_authentication_parameter_autn_t *)pkbuf->data;

    authentication_parameter_autn->length = source->length;
    size = authentication_parameter_autn->length + sizeof(authentication_parameter_autn->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*authentication_parameter_autn) < size) return -1;
    memcpy(authentication_parameter_autn, pkbuf->data - size, size);

    //("  AUTHENTICATION_PARAMETER_AUTN - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_authentication_parameter_autn(pkbuf_t *pkbuf, ogs_nas_authentication_parameter_autn_t *authentication_parameter_autn)
{
    int size = authentication_parameter_autn->length + sizeof(authentication_parameter_autn->length);
    ogs_nas_authentication_parameter_autn_t target;

    memcpy(&target, authentication_parameter_autn, sizeof(ogs_nas_authentication_parameter_autn_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  AUTHENTICATION_PARAMETER_AUTN - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.20 MS network capability
 * O TLV 4-10 */
int ogs_nas_eps_decode_ms_network_capability(ogs_nas_ms_network_capability_t *ms_network_capability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ms_network_capability_t *source = (ogs_nas_ms_network_capability_t *)pkbuf->data;

    ms_network_capability->length = source->length;
    size = ms_network_capability->length + sizeof(ms_network_capability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ms_network_capability) < size) return -1;
    memcpy(ms_network_capability, pkbuf->data - size, size);

    //("  MS_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ms_network_capability(pkbuf_t *pkbuf, ogs_nas_ms_network_capability_t *ms_network_capability)
{
    int size = ms_network_capability->length + sizeof(ms_network_capability->length);
    ogs_nas_ms_network_capability_t target;

    memcpy(&target, ms_network_capability, sizeof(ogs_nas_ms_network_capability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  MS_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.20A MS network feature support
 * O TV 1 */
int ogs_nas_eps_decode_ms_network_feature_support(ogs_nas_ms_network_feature_support_t *ms_network_feature_support, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ms_network_feature_support_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ms_network_feature_support, pkbuf->data - size, size);

    //("  MS_NETWORK_FEATURE_SUPPORT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ms_network_feature_support(pkbuf_t *pkbuf, ogs_nas_ms_network_feature_support_t *ms_network_feature_support)
{
    int size = sizeof(ogs_nas_ms_network_feature_support_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, ms_network_feature_support, size);

    //("  MS_NETWORK_FEATURE_SUPPORT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.21 key set identifier
 * O TV 1 */
int ogs_nas_eps_decode_key_set_identifier(ogs_nas_key_set_identifier_t *key_set_identifier, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_key_set_identifier_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(key_set_identifier, pkbuf->data - size, size);

    //("  KEY_SET_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_key_set_identifier(pkbuf_t *pkbuf, ogs_nas_key_set_identifier_t *key_set_identifier)
{
    int size = sizeof(ogs_nas_key_set_identifier_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, key_set_identifier, size);

    //("  KEY_SET_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.22 EPS message container
 * M LV 3-252 */
int ogs_nas_eps_decode_eps_message_container(ogs_nas_eps_message_container_t *eps_message_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_message_container_t *source = (ogs_nas_eps_message_container_t *)pkbuf->data;

    eps_message_container->length = source->length;
    size = eps_message_container->length + sizeof(eps_message_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_message_container) < size) return -1;
    memcpy(eps_message_container, pkbuf->data - size, size);

    //("  EPS_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_message_container(pkbuf_t *pkbuf, ogs_nas_eps_message_container_t *eps_message_container)
{
    int size = eps_message_container->length + sizeof(eps_message_container->length);
    ogs_nas_eps_message_container_t target;

    memcpy(&target, eps_message_container, sizeof(ogs_nas_eps_message_container_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.23 security algorithms
 * M V 1 */
int ogs_nas_eps_decode_security_algorithms(ogs_nas_security_algorithms_t *security_algorithms, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_security_algorithms_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(security_algorithms, pkbuf->data - size, size);

    //("  SECURITY_ALGORITHMS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_security_algorithms(pkbuf_t *pkbuf, ogs_nas_security_algorithms_t *security_algorithms)
{
    int size = sizeof(ogs_nas_security_algorithms_t);
    ogs_nas_security_algorithms_t target;

    memcpy(&target, security_algorithms, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SECURITY_ALGORITHMS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.24 Network name
 * O TLV 3-n */
int ogs_nas_eps_decode_network_name(ogs_nas_network_name_t *network_name, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_network_name_t *source = (ogs_nas_network_name_t *)pkbuf->data;

    network_name->length = source->length;
    size = network_name->length + sizeof(network_name->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*network_name) < size) return -1;
    memcpy(network_name, pkbuf->data - size, size);

    //("  NETWORK_NAME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_network_name(pkbuf_t *pkbuf, ogs_nas_network_name_t *network_name)
{
    int size = network_name->length + sizeof(network_name->length);
    ogs_nas_network_name_t target;

    memcpy(&target, network_name, sizeof(ogs_nas_network_name_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  NETWORK_NAME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.24A Network resource identifier container
 * O TLV 4 */
int ogs_nas_eps_decode_network_resource_identifier_container(ogs_nas_network_resource_identifier_container_t *network_resource_identifier_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_network_resource_identifier_container_t *source = (ogs_nas_network_resource_identifier_container_t *)pkbuf->data;

    network_resource_identifier_container->length = source->length;
    size = network_resource_identifier_container->length + sizeof(network_resource_identifier_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*network_resource_identifier_container) < size) return -1;
    memcpy(network_resource_identifier_container, pkbuf->data - size, size);

    //("  NETWORK_RESOURCE_IDENTIFIER_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_network_resource_identifier_container(pkbuf_t *pkbuf, ogs_nas_network_resource_identifier_container_t *network_resource_identifier_container)
{
    int size = network_resource_identifier_container->length + sizeof(network_resource_identifier_container->length);
    ogs_nas_network_resource_identifier_container_t target;

    memcpy(&target, network_resource_identifier_container, sizeof(ogs_nas_network_resource_identifier_container_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  NETWORK_RESOURCE_IDENTIFIER_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.25 Nonce
 * O TV 5 */
int ogs_nas_eps_decode_nonce(ogs_nas_nonce_t *nonce, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_nonce_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(nonce, pkbuf->data - size, size);

    *nonce = be32toh(*nonce);

    //("  NONCE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_nonce(pkbuf_t *pkbuf, ogs_nas_nonce_t *nonce)
{
    int size = sizeof(ogs_nas_nonce_t);
    ogs_nas_nonce_t target;

    memcpy(&target, nonce, size);
    target = htobe32(*nonce);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  NONCE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.25A Paging identity
 * M V 1 */
int ogs_nas_eps_decode_paging_identity(ogs_nas_paging_identity_t *paging_identity, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_paging_identity_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(paging_identity, pkbuf->data - size, size);

    //("  PAGING_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_paging_identity(pkbuf_t *pkbuf, ogs_nas_paging_identity_t *paging_identity)
{
    int size = sizeof(ogs_nas_paging_identity_t);
    ogs_nas_paging_identity_t target;

    memcpy(&target, paging_identity, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PAGING_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.26 P-TMSI signature
 * O TV 4 */
int ogs_nas_eps_decode_p_tmsi_signature(ogs_nas_p_tmsi_signature_t *p_tmsi_signature, pkbuf_t *pkbuf)
{
    int size = 3;

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(p_tmsi_signature, pkbuf->data - size, size);

    *p_tmsi_signature = htobe32(*p_tmsi_signature);

    //("  P_TMSI_SIGNATURE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_p_tmsi_signature(pkbuf_t *pkbuf, ogs_nas_p_tmsi_signature_t *p_tmsi_signature)
{
    int size = 3;
    ogs_nas_p_tmsi_signature_t target;

    memcpy(&target, p_tmsi_signature, size);
    *p_tmsi_signature = be32toh(*p_tmsi_signature);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  P_TMSI_SIGNATURE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.26A Extended EMM cause
 * O TV 1 */
int ogs_nas_eps_decode_extended_emm_cause(ogs_nas_extended_emm_cause_t *extended_emm_cause, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_extended_emm_cause_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(extended_emm_cause, pkbuf->data - size, size);

    //("  EXTENDED_EMM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_extended_emm_cause(pkbuf_t *pkbuf, ogs_nas_extended_emm_cause_t *extended_emm_cause)
{
    int size = sizeof(ogs_nas_extended_emm_cause_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, extended_emm_cause, size);

    //("  EXTENDED_EMM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.27 Service type
 * M V 1/2 */
int ogs_nas_eps_decode_service_type(ogs_nas_service_type_t *service_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_service_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(service_type, pkbuf->data - size, size);

    //("  SERVICE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_service_type(pkbuf_t *pkbuf, ogs_nas_service_type_t *service_type)
{
    int size = sizeof(ogs_nas_service_type_t);
    ogs_nas_service_type_t target;

    memcpy(&target, service_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SERVICE_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.28 Short MAC
 * M V 2 */
int ogs_nas_eps_decode_short_mac(ogs_nas_short_mac_t *short_mac, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_short_mac_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(short_mac, pkbuf->data - size, size);

    *short_mac = be16toh(*short_mac);

    //("  SHORT_MAC - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_short_mac(pkbuf_t *pkbuf, ogs_nas_short_mac_t *short_mac)
{
    int size = sizeof(ogs_nas_short_mac_t);
    ogs_nas_short_mac_t target;

    memcpy(&target, short_mac, size);
    target = htobe16(*short_mac);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SHORT_MAC - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.29 Time zone
 * O TV 2 */
int ogs_nas_eps_decode_time_zone(ogs_nas_time_zone_t *time_zone, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_time_zone_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(time_zone, pkbuf->data - size, size);

    //("  TIME_ZONE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_time_zone(pkbuf_t *pkbuf, ogs_nas_time_zone_t *time_zone)
{
    int size = sizeof(ogs_nas_time_zone_t);
    ogs_nas_time_zone_t target;

    memcpy(&target, time_zone, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TIME_ZONE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.3 Authentication parameter RAND
 * M V 16 */
int ogs_nas_eps_decode_authentication_parameter_rand(ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_authentication_parameter_rand_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(authentication_parameter_rand, pkbuf->data - size, size);

    //("  AUTHENTICATION_PARAMETER_RAND - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_authentication_parameter_rand(pkbuf_t *pkbuf, ogs_nas_authentication_parameter_rand_t *authentication_parameter_rand)
{
    int size = sizeof(ogs_nas_authentication_parameter_rand_t);
    ogs_nas_authentication_parameter_rand_t target;

    memcpy(&target, authentication_parameter_rand, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  AUTHENTICATION_PARAMETER_RAND - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.30 Time zone and time
 * O TV 8 */
int ogs_nas_eps_decode_time_zone_and_time(ogs_nas_time_zone_and_time_t *time_zone_and_time, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_time_zone_and_time_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(time_zone_and_time, pkbuf->data - size, size);

    //("  TIME_ZONE_AND_TIME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_time_zone_and_time(pkbuf_t *pkbuf, ogs_nas_time_zone_and_time_t *time_zone_and_time)
{
    int size = sizeof(ogs_nas_time_zone_and_time_t);
    ogs_nas_time_zone_and_time_t target;

    memcpy(&target, time_zone_and_time, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TIME_ZONE_AND_TIME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.31 TMSI status
 * O TV 1 */
int ogs_nas_eps_decode_tmsi_status(ogs_nas_tmsi_status_t *tmsi_status, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_tmsi_status_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(tmsi_status, pkbuf->data - size, size);

    //("  TMSI_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_tmsi_status(pkbuf_t *pkbuf, ogs_nas_tmsi_status_t *tmsi_status)
{
    int size = sizeof(ogs_nas_tmsi_status_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, tmsi_status, size);

    //("  TMSI_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.32 Tracking area identity
 * O TV 6 */
int ogs_nas_eps_decode_tracking_area_identity(ogs_nas_tracking_area_identity_t *tracking_area_identity, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_tracking_area_identity_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(tracking_area_identity, pkbuf->data - size, size);

    tracking_area_identity->tac = be16toh(tracking_area_identity->tac);

    //("  TRACKING_AREA_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_tracking_area_identity(pkbuf_t *pkbuf, ogs_nas_tracking_area_identity_t *tracking_area_identity)
{
    int size = sizeof(ogs_nas_tracking_area_identity_t);
    ogs_nas_tracking_area_identity_t target;

    memcpy(&target, tracking_area_identity, size);
    target.tac = htobe16(tracking_area_identity->tac);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TRACKING_AREA_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.33 Tracking area identity list
 * M LV 7-97 */
int ogs_nas_eps_decode_tracking_area_identity_list(ogs_nas_tracking_area_identity_list_t *tracking_area_identity_list, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_tracking_area_identity_list_t *source = (ogs_nas_tracking_area_identity_list_t *)pkbuf->data;

    tracking_area_identity_list->length = source->length;
    size = tracking_area_identity_list->length + sizeof(tracking_area_identity_list->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*tracking_area_identity_list) < size) return -1;
    memcpy(tracking_area_identity_list, pkbuf->data - size, size);

    //("  TRACKING_AREA_IDENTITY_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_tracking_area_identity_list(pkbuf_t *pkbuf, ogs_nas_tracking_area_identity_list_t *tracking_area_identity_list)
{
    int size = tracking_area_identity_list->length + sizeof(tracking_area_identity_list->length);
    ogs_nas_tracking_area_identity_list_t target;

    memcpy(&target, tracking_area_identity_list, sizeof(ogs_nas_tracking_area_identity_list_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TRACKING_AREA_IDENTITY_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.34 UE network capability
 * M LV 3-14 */
int ogs_nas_eps_decode_ue_network_capability(ogs_nas_ue_network_capability_t *ue_network_capability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_network_capability_t *source = (ogs_nas_ue_network_capability_t *)pkbuf->data;

    ue_network_capability->length = source->length;
    size = ue_network_capability->length + sizeof(ue_network_capability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_network_capability) < size) return -1;
    memcpy(ue_network_capability, pkbuf->data - size, size);

    //("  UE_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_network_capability(pkbuf_t *pkbuf, ogs_nas_ue_network_capability_t *ue_network_capability)
{
    int size = ue_network_capability->length + sizeof(ue_network_capability->length);
    ogs_nas_ue_network_capability_t target;

    memcpy(&target, ue_network_capability, sizeof(ogs_nas_ue_network_capability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.35 UE radio capability information update needed
 * O TV 1 */
int ogs_nas_eps_decode_ue_radio_capability_information_update_needed(ogs_nas_ue_radio_capability_information_update_needed_t *ue_radio_capability_information_update_needed, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ue_radio_capability_information_update_needed_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ue_radio_capability_information_update_needed, pkbuf->data - size, size);

    //("  UE_RADIO_CAPABILITY_INFORMATION_UPDATE_NEEDED - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_radio_capability_information_update_needed(pkbuf_t *pkbuf, ogs_nas_ue_radio_capability_information_update_needed_t *ue_radio_capability_information_update_needed)
{
    int size = sizeof(ogs_nas_ue_radio_capability_information_update_needed_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, ue_radio_capability_information_update_needed, size);

    //("  UE_RADIO_CAPABILITY_INFORMATION_UPDATE_NEEDED - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.36 UE security capability
 * M LV 3-6 */
int ogs_nas_eps_decode_ue_security_capability(ogs_nas_ue_security_capability_t *ue_security_capability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_security_capability_t *source = (ogs_nas_ue_security_capability_t *)pkbuf->data;

    ue_security_capability->length = source->length;
    size = ue_security_capability->length + sizeof(ue_security_capability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_security_capability) < size) return -1;
    memcpy(ue_security_capability, pkbuf->data - size, size);

    //("  UE_SECURITY_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_security_capability(pkbuf_t *pkbuf, ogs_nas_ue_security_capability_t *ue_security_capability)
{
    int size = ue_security_capability->length + sizeof(ue_security_capability->length);
    ogs_nas_ue_security_capability_t target;

    memcpy(&target, ue_security_capability, sizeof(ogs_nas_ue_security_capability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_SECURITY_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.37 Emergency number list
 * O TLV 5-50 */
int ogs_nas_eps_decode_emergency_number_list(ogs_nas_emergency_number_list_t *emergency_number_list, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_emergency_number_list_t *source = (ogs_nas_emergency_number_list_t *)pkbuf->data;

    emergency_number_list->length = source->length;
    size = emergency_number_list->length + sizeof(emergency_number_list->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*emergency_number_list) < size) return -1;
    memcpy(emergency_number_list, pkbuf->data - size, size);

    //("  EMERGENCY_NUMBER_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_emergency_number_list(pkbuf_t *pkbuf, ogs_nas_emergency_number_list_t *emergency_number_list)
{
    int size = emergency_number_list->length + sizeof(emergency_number_list->length);
    ogs_nas_emergency_number_list_t target;

    memcpy(&target, emergency_number_list, sizeof(ogs_nas_emergency_number_list_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EMERGENCY_NUMBER_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.37A Extended emergency number list
 * O TLV-E 7-65538 */
int ogs_nas_eps_decode_extended_emergency_number_list(ogs_nas_extended_emergency_number_list_t *extended_emergency_number_list, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_extended_emergency_number_list_t *source = (ogs_nas_extended_emergency_number_list_t *)pkbuf->data;

    extended_emergency_number_list->length = be16toh(source->length);
    size = extended_emergency_number_list->length + sizeof(extended_emergency_number_list->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    extended_emergency_number_list->buffer = pkbuf->data - size + sizeof(extended_emergency_number_list->length);

    //("  EXTENDED_EMERGENCY_NUMBER_LIST - ");
    //(OGS_LOG_TRACE, (void*)extended_emergency_number_list->buffer, extended_emergency_number_list->length);

    return size;
}

int ogs_nas_eps_encode_extended_emergency_number_list(pkbuf_t *pkbuf, ogs_nas_extended_emergency_number_list_t *extended_emergency_number_list)
{
    int size = 0;
    int target;

    assert(extended_emergency_number_list);
    assert(extended_emergency_number_list->buffer);

    size = sizeof(extended_emergency_number_list->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(extended_emergency_number_list->length);
    memcpy(pkbuf->data - size, &target, size);

    size = extended_emergency_number_list->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, extended_emergency_number_list->buffer, size);

    //("  EXTENDED_EMERGENCY_NUMBER_LIST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return extended_emergency_number_list->length + sizeof(extended_emergency_number_list->length);
}

/* 9.9.3.38 CLI
 * O TLV 3-14 */
int ogs_nas_eps_decode_cli(ogs_nas_cli_t *cli, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_cli_t *source = (ogs_nas_cli_t *)pkbuf->data;

    cli->length = source->length;
    size = cli->length + sizeof(cli->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*cli) < size) return -1;
    memcpy(cli, pkbuf->data - size, size);

    //("  CLI - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_cli(pkbuf_t *pkbuf, ogs_nas_cli_t *cli)
{
    int size = cli->length + sizeof(cli->length);
    ogs_nas_cli_t target;

    memcpy(&target, cli, sizeof(ogs_nas_cli_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  CLI - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.39 SS Code
 * O TV 2 */
int ogs_nas_eps_decode_ss_code(ogs_nas_ss_code_t *ss_code, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ss_code_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ss_code, pkbuf->data - size, size);

    //("  SS_CODE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ss_code(pkbuf_t *pkbuf, ogs_nas_ss_code_t *ss_code)
{
    int size = sizeof(ogs_nas_ss_code_t);
    ogs_nas_ss_code_t target;

    memcpy(&target, ss_code, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SS_CODE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.4 Authentication response parameter
 * M LV 5-17 */
int ogs_nas_eps_decode_authentication_response_parameter(ogs_nas_authentication_response_parameter_t *authentication_response_parameter, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_authentication_response_parameter_t *source = (ogs_nas_authentication_response_parameter_t *)pkbuf->data;

    authentication_response_parameter->length = source->length;
    size = authentication_response_parameter->length + sizeof(authentication_response_parameter->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*authentication_response_parameter) < size) return -1;
    memcpy(authentication_response_parameter, pkbuf->data - size, size);

    //("  AUTHENTICATION_RESPONSE_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_authentication_response_parameter(pkbuf_t *pkbuf, ogs_nas_authentication_response_parameter_t *authentication_response_parameter)
{
    int size = authentication_response_parameter->length + sizeof(authentication_response_parameter->length);
    ogs_nas_authentication_response_parameter_t target;

    memcpy(&target, authentication_response_parameter, sizeof(ogs_nas_authentication_response_parameter_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  AUTHENTICATION_RESPONSE_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.40 LCS indicator
 * O TV 2 */
int ogs_nas_eps_decode_lcs_indicator(ogs_nas_lcs_indicator_t *lcs_indicator, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_lcs_indicator_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(lcs_indicator, pkbuf->data - size, size);

    //("  LCS_INDICATOR - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_lcs_indicator(pkbuf_t *pkbuf, ogs_nas_lcs_indicator_t *lcs_indicator)
{
    int size = sizeof(ogs_nas_lcs_indicator_t);
    ogs_nas_lcs_indicator_t target;

    memcpy(&target, lcs_indicator, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  LCS_INDICATOR - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.41 LCS client identity
 * O TLV 3-257 */
int ogs_nas_eps_decode_lcs_client_identity(ogs_nas_lcs_client_identity_t *lcs_client_identity, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_lcs_client_identity_t *source = (ogs_nas_lcs_client_identity_t *)pkbuf->data;

    lcs_client_identity->length = source->length;
    size = lcs_client_identity->length + sizeof(lcs_client_identity->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*lcs_client_identity) < size) return -1;
    memcpy(lcs_client_identity, pkbuf->data - size, size);

    //("  LCS_CLIENT_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_lcs_client_identity(pkbuf_t *pkbuf, ogs_nas_lcs_client_identity_t *lcs_client_identity)
{
    int size = lcs_client_identity->length + sizeof(lcs_client_identity->length);
    ogs_nas_lcs_client_identity_t target;

    memcpy(&target, lcs_client_identity, sizeof(ogs_nas_lcs_client_identity_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  LCS_CLIENT_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.42 Generic message container type
 * M V 1 */
int ogs_nas_eps_decode_generic_message_container_type(ogs_nas_generic_message_container_type_t *generic_message_container_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_generic_message_container_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(generic_message_container_type, pkbuf->data - size, size);

    //("  GENERIC_MESSAGE_CONTAINER_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_generic_message_container_type(pkbuf_t *pkbuf, ogs_nas_generic_message_container_type_t *generic_message_container_type)
{
    int size = sizeof(ogs_nas_generic_message_container_type_t);
    ogs_nas_generic_message_container_type_t target;

    memcpy(&target, generic_message_container_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  GENERIC_MESSAGE_CONTAINER_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.43 Generic message container
 * M LV-E 3-n */
int ogs_nas_eps_decode_generic_message_container(ogs_nas_generic_message_container_t *generic_message_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_generic_message_container_t *source = (ogs_nas_generic_message_container_t *)pkbuf->data;

    generic_message_container->length = be16toh(source->length);
    size = generic_message_container->length + sizeof(generic_message_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    generic_message_container->buffer = pkbuf->data - size + sizeof(generic_message_container->length);

    //("  GENERIC_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, (void*)generic_message_container->buffer, generic_message_container->length);

    return size;
}

int ogs_nas_eps_encode_generic_message_container(pkbuf_t *pkbuf, ogs_nas_generic_message_container_t *generic_message_container)
{
    int size = 0;
    int target;

    assert(generic_message_container);
    assert(generic_message_container->buffer);

    size = sizeof(generic_message_container->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(generic_message_container->length);
    memcpy(pkbuf->data - size, &target, size);

    size = generic_message_container->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, generic_message_container->buffer, size);

    //("  GENERIC_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return generic_message_container->length + sizeof(generic_message_container->length);
}

/* 9.9.3.44 Voice domain preference and UE usage setting
 * O TLV 3 */
int ogs_nas_eps_decode_voice_domain_preference_and_ue_usage_setting(ogs_nas_voice_domain_preference_and_ue_usage_setting_t *voice_domain_preference_and_ue_usage_setting, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_voice_domain_preference_and_ue_usage_setting_t *source = (ogs_nas_voice_domain_preference_and_ue_usage_setting_t *)pkbuf->data;

    voice_domain_preference_and_ue_usage_setting->length = source->length;
    size = voice_domain_preference_and_ue_usage_setting->length + sizeof(voice_domain_preference_and_ue_usage_setting->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*voice_domain_preference_and_ue_usage_setting) < size) return -1;
    memcpy(voice_domain_preference_and_ue_usage_setting, pkbuf->data - size, size);

    //("  VOICE_DOMAIN_PREFERENCE_AND_UE_USAGE_SETTING - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_voice_domain_preference_and_ue_usage_setting(pkbuf_t *pkbuf, ogs_nas_voice_domain_preference_and_ue_usage_setting_t *voice_domain_preference_and_ue_usage_setting)
{
    int size = voice_domain_preference_and_ue_usage_setting->length + sizeof(voice_domain_preference_and_ue_usage_setting->length);
    ogs_nas_voice_domain_preference_and_ue_usage_setting_t target;

    memcpy(&target, voice_domain_preference_and_ue_usage_setting, sizeof(ogs_nas_voice_domain_preference_and_ue_usage_setting_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  VOICE_DOMAIN_PREFERENCE_AND_UE_USAGE_SETTING - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.45 GUTI type
 * O TV 1 */
int ogs_nas_eps_decode_guti_type(ogs_nas_guti_type_t *guti_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_guti_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(guti_type, pkbuf->data - size, size);

    //("  GUTI_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_guti_type(pkbuf_t *pkbuf, ogs_nas_guti_type_t *guti_type)
{
    int size = sizeof(ogs_nas_guti_type_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, guti_type, size);

    //("  GUTI_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.46 Extended DRX parameters
 * O TLV 3 */
int ogs_nas_eps_decode_extended_drx_parameters(ogs_nas_extended_drx_parameters_t *extended_drx_parameters, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_extended_drx_parameters_t *source = (ogs_nas_extended_drx_parameters_t *)pkbuf->data;

    extended_drx_parameters->length = source->length;
    size = extended_drx_parameters->length + sizeof(extended_drx_parameters->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*extended_drx_parameters) < size) return -1;
    memcpy(extended_drx_parameters, pkbuf->data - size, size);

    //("  EXTENDED_DRX_PARAMETERS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_extended_drx_parameters(pkbuf_t *pkbuf, ogs_nas_extended_drx_parameters_t *extended_drx_parameters)
{
    int size = extended_drx_parameters->length + sizeof(extended_drx_parameters->length);
    ogs_nas_extended_drx_parameters_t target;

    memcpy(&target, extended_drx_parameters, sizeof(ogs_nas_extended_drx_parameters_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EXTENDED_DRX_PARAMETERS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.48 DCN-ID
 * O TLV 4 */
int ogs_nas_eps_decode_dcn_id(ogs_nas_dcn_id_t *dcn_id, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_dcn_id_t *source = (ogs_nas_dcn_id_t *)pkbuf->data;

    dcn_id->length = source->length;
    size = dcn_id->length + sizeof(dcn_id->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*dcn_id) < size) return -1;
    memcpy(dcn_id, pkbuf->data - size, size);

    //("  DCN_ID - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_dcn_id(pkbuf_t *pkbuf, ogs_nas_dcn_id_t *dcn_id)
{
    int size = dcn_id->length + sizeof(dcn_id->length);
    ogs_nas_dcn_id_t target;

    memcpy(&target, dcn_id, sizeof(ogs_nas_dcn_id_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  DCN_ID - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.49 Non-3GPP NW provided policies
 * O TV 1 */
int ogs_nas_eps_decode_non__nw_provided_policies(ogs_nas_non__nw_provided_policies_t *non__nw_provided_policies, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_non__nw_provided_policies_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(non__nw_provided_policies, pkbuf->data - size, size);

    //("  NON__NW_PROVIDED_POLICIES - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_non__nw_provided_policies(pkbuf_t *pkbuf, ogs_nas_non__nw_provided_policies_t *non__nw_provided_policies)
{
    int size = sizeof(ogs_nas_non__nw_provided_policies_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, non__nw_provided_policies, size);

    //("  NON__NW_PROVIDED_POLICIES - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.4B SMS services status
 * O TV 1 */
int ogs_nas_eps_decode_sms_services_status(ogs_nas_sms_services_status_t *sms_services_status, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_sms_services_status_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(sms_services_status, pkbuf->data - size, size);

    //("  SMS_SERVICES_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_sms_services_status(pkbuf_t *pkbuf, ogs_nas_sms_services_status_t *sms_services_status)
{
    int size = sizeof(ogs_nas_sms_services_status_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, sms_services_status, size);

    //("  SMS_SERVICES_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.4a Ciphering key sequence number
 * O TV 1 */
int ogs_nas_eps_decode_ciphering_key_sequence_number(ogs_nas_ciphering_key_sequence_number_t *ciphering_key_sequence_number, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ciphering_key_sequence_number_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ciphering_key_sequence_number, pkbuf->data - size, size);

    //("  CIPHERING_KEY_SEQUENCE_NUMBER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ciphering_key_sequence_number(pkbuf_t *pkbuf, ogs_nas_ciphering_key_sequence_number_t *ciphering_key_sequence_number)
{
    int size = sizeof(ogs_nas_ciphering_key_sequence_number_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, ciphering_key_sequence_number, size);

    //("  CIPHERING_KEY_SEQUENCE_NUMBER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.5 CSFB response
 * C TV 1 */
int ogs_nas_eps_decode_csfb_response(ogs_nas_csfb_response_t *csfb_response, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_csfb_response_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(csfb_response, pkbuf->data - size, size);

    //("  CSFB_RESPONSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_csfb_response(pkbuf_t *pkbuf, ogs_nas_csfb_response_t *csfb_response)
{
    int size = sizeof(ogs_nas_csfb_response_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, csfb_response, size);

    //("  CSFB_RESPONSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.50 HashMME
 * O TLV 10 */
int ogs_nas_eps_decode_hashmme(ogs_nas_hashmme_t *hashmme, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_hashmme_t *source = (ogs_nas_hashmme_t *)pkbuf->data;

    hashmme->length = source->length;
    size = hashmme->length + sizeof(hashmme->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*hashmme) < size) return -1;
    memcpy(hashmme, pkbuf->data - size, size);

    //("  HASHMME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_hashmme(pkbuf_t *pkbuf, ogs_nas_hashmme_t *hashmme)
{
    int size = hashmme->length + sizeof(hashmme->length);
    ogs_nas_hashmme_t target;

    memcpy(&target, hashmme, sizeof(ogs_nas_hashmme_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  HASHMME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.51 Replayed NAS message container
 * O TLV-E 3-n */
int ogs_nas_eps_decode_replayed_nas_message_container(ogs_nas_replayed_nas_message_container_t *replayed_nas_message_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_replayed_nas_message_container_t *source = (ogs_nas_replayed_nas_message_container_t *)pkbuf->data;

    replayed_nas_message_container->length = be16toh(source->length);
    size = replayed_nas_message_container->length + sizeof(replayed_nas_message_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    replayed_nas_message_container->buffer = pkbuf->data - size + sizeof(replayed_nas_message_container->length);

    //("  REPLAYED_NAS_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, (void*)replayed_nas_message_container->buffer, replayed_nas_message_container->length);

    return size;
}

int ogs_nas_eps_encode_replayed_nas_message_container(pkbuf_t *pkbuf, ogs_nas_replayed_nas_message_container_t *replayed_nas_message_container)
{
    int size = 0;
    int target;

    assert(replayed_nas_message_container);
    assert(replayed_nas_message_container->buffer);

    size = sizeof(replayed_nas_message_container->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(replayed_nas_message_container->length);
    memcpy(pkbuf->data - size, &target, size);

    size = replayed_nas_message_container->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, replayed_nas_message_container->buffer, size);

    //("  REPLAYED_NAS_MESSAGE_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return replayed_nas_message_container->length + sizeof(replayed_nas_message_container->length);
}

/* 9.9.3.52 Network policy
 * O TV 1 */
int ogs_nas_eps_decode_network_policy(ogs_nas_network_policy_t *network_policy, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_network_policy_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(network_policy, pkbuf->data - size, size);

    //("  NETWORK_POLICY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_network_policy(pkbuf_t *pkbuf, ogs_nas_network_policy_t *network_policy)
{
    int size = sizeof(ogs_nas_network_policy_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, network_policy, size);

    //("  NETWORK_POLICY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.53 UE additional security capability
 * O TLV 6 */
int ogs_nas_eps_decode_ue_additional_security_capability(ogs_nas_ue_additional_security_capability_t *ue_additional_security_capability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_additional_security_capability_t *source = (ogs_nas_ue_additional_security_capability_t *)pkbuf->data;

    ue_additional_security_capability->length = source->length;
    size = ue_additional_security_capability->length + sizeof(ue_additional_security_capability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_additional_security_capability) < size) return -1;
    memcpy(ue_additional_security_capability, pkbuf->data - size, size);

    //("  UE_ADDITIONAL_SECURITY_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_additional_security_capability(pkbuf_t *pkbuf, ogs_nas_ue_additional_security_capability_t *ue_additional_security_capability)
{
    int size = ue_additional_security_capability->length + sizeof(ue_additional_security_capability->length);
    ogs_nas_ue_additional_security_capability_t target;

    memcpy(&target, ue_additional_security_capability, sizeof(ogs_nas_ue_additional_security_capability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_ADDITIONAL_SECURITY_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.54 UE status
 * O TLV 3 */
int ogs_nas_eps_decode_ue_status(ogs_nas_ue_status_t *ue_status, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_status_t *source = (ogs_nas_ue_status_t *)pkbuf->data;

    ue_status->length = source->length;
    size = ue_status->length + sizeof(ue_status->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_status) < size) return -1;
    memcpy(ue_status, pkbuf->data - size, size);

    //("  UE_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_status(pkbuf_t *pkbuf, ogs_nas_ue_status_t *ue_status)
{
    int size = ue_status->length + sizeof(ue_status->length);
    ogs_nas_ue_status_t target;

    memcpy(&target, ue_status, sizeof(ogs_nas_ue_status_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.55 Additional information requested
 * O TV 2 */
int ogs_nas_eps_decode_additional_information_requested(ogs_nas_additional_information_requested_t *additional_information_requested, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_additional_information_requested_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(additional_information_requested, pkbuf->data - size, size);

    //("  ADDITIONAL_INFORMATION_REQUESTED - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_additional_information_requested(pkbuf_t *pkbuf, ogs_nas_additional_information_requested_t *additional_information_requested)
{
    int size = sizeof(ogs_nas_additional_information_requested_t);
    ogs_nas_additional_information_requested_t target;

    memcpy(&target, additional_information_requested, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  ADDITIONAL_INFORMATION_REQUESTED - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.56 Ciphering key data
 * O TLV-E 35-2291 */
int ogs_nas_eps_decode_ciphering_key_data(ogs_nas_ciphering_key_data_t *ciphering_key_data, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ciphering_key_data_t *source = (ogs_nas_ciphering_key_data_t *)pkbuf->data;

    ciphering_key_data->length = be16toh(source->length);
    size = ciphering_key_data->length + sizeof(ciphering_key_data->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    ciphering_key_data->buffer = pkbuf->data - size + sizeof(ciphering_key_data->length);

    //("  CIPHERING_KEY_DATA - ");
    //(OGS_LOG_TRACE, (void*)ciphering_key_data->buffer, ciphering_key_data->length);

    return size;
}

int ogs_nas_eps_encode_ciphering_key_data(pkbuf_t *pkbuf, ogs_nas_ciphering_key_data_t *ciphering_key_data)
{
    int size = 0;
    int target;

    assert(ciphering_key_data);
    assert(ciphering_key_data->buffer);

    size = sizeof(ciphering_key_data->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(ciphering_key_data->length);
    memcpy(pkbuf->data - size, &target, size);

    size = ciphering_key_data->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, ciphering_key_data->buffer, size);

    //("  CIPHERING_KEY_DATA - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return ciphering_key_data->length + sizeof(ciphering_key_data->length);
}

/* 9.9.3.57 N1 UE network capability
 * O TLV 3-15 */
int ogs_nas_eps_decode_n1_ue_network_capability(ogs_nas_n1_ue_network_capability_t *n1_ue_network_capability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_n1_ue_network_capability_t *source = (ogs_nas_n1_ue_network_capability_t *)pkbuf->data;

    n1_ue_network_capability->length = source->length;
    size = n1_ue_network_capability->length + sizeof(n1_ue_network_capability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*n1_ue_network_capability) < size) return -1;
    memcpy(n1_ue_network_capability, pkbuf->data - size, size);

    //("  N1_UE_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_n1_ue_network_capability(pkbuf_t *pkbuf, ogs_nas_n1_ue_network_capability_t *n1_ue_network_capability)
{
    int size = n1_ue_network_capability->length + sizeof(n1_ue_network_capability->length);
    ogs_nas_n1_ue_network_capability_t target;

    memcpy(&target, n1_ue_network_capability, sizeof(ogs_nas_n1_ue_network_capability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  N1_UE_NETWORK_CAPABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.58 UE radio capability ID availability
 * O TLV 3 */
int ogs_nas_eps_decode_ue_radio_capability_id_availability(ogs_nas_ue_radio_capability_id_availability_t *ue_radio_capability_id_availability, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_radio_capability_id_availability_t *source = (ogs_nas_ue_radio_capability_id_availability_t *)pkbuf->data;

    ue_radio_capability_id_availability->length = source->length;
    size = ue_radio_capability_id_availability->length + sizeof(ue_radio_capability_id_availability->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_radio_capability_id_availability) < size) return -1;
    memcpy(ue_radio_capability_id_availability, pkbuf->data - size, size);

    //("  UE_RADIO_CAPABILITY_ID_AVAILABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_radio_capability_id_availability(pkbuf_t *pkbuf, ogs_nas_ue_radio_capability_id_availability_t *ue_radio_capability_id_availability)
{
    int size = ue_radio_capability_id_availability->length + sizeof(ue_radio_capability_id_availability->length);
    ogs_nas_ue_radio_capability_id_availability_t target;

    memcpy(&target, ue_radio_capability_id_availability, sizeof(ogs_nas_ue_radio_capability_id_availability_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_RADIO_CAPABILITY_ID_AVAILABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.59 UE radio capability ID request
 * O TLV 3 */
int ogs_nas_eps_decode_ue_radio_capability_id_request(ogs_nas_ue_radio_capability_id_request_t *ue_radio_capability_id_request, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_radio_capability_id_request_t *source = (ogs_nas_ue_radio_capability_id_request_t *)pkbuf->data;

    ue_radio_capability_id_request->length = source->length;
    size = ue_radio_capability_id_request->length + sizeof(ue_radio_capability_id_request->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_radio_capability_id_request) < size) return -1;
    memcpy(ue_radio_capability_id_request, pkbuf->data - size, size);

    //("  UE_RADIO_CAPABILITY_ID_REQUEST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_radio_capability_id_request(pkbuf_t *pkbuf, ogs_nas_ue_radio_capability_id_request_t *ue_radio_capability_id_request)
{
    int size = ue_radio_capability_id_request->length + sizeof(ue_radio_capability_id_request->length);
    ogs_nas_ue_radio_capability_id_request_t target;

    memcpy(&target, ue_radio_capability_id_request, sizeof(ogs_nas_ue_radio_capability_id_request_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_RADIO_CAPABILITY_ID_REQUEST - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.6 Daylight saving time
 * O TLV 3 */
int ogs_nas_eps_decode_daylight_saving_time(ogs_nas_daylight_saving_time_t *daylight_saving_time, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_daylight_saving_time_t *source = (ogs_nas_daylight_saving_time_t *)pkbuf->data;

    daylight_saving_time->length = source->length;
    size = daylight_saving_time->length + sizeof(daylight_saving_time->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*daylight_saving_time) < size) return -1;
    memcpy(daylight_saving_time, pkbuf->data - size, size);

    //("  DAYLIGHT_SAVING_TIME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_daylight_saving_time(pkbuf_t *pkbuf, ogs_nas_daylight_saving_time_t *daylight_saving_time)
{
    int size = daylight_saving_time->length + sizeof(daylight_saving_time->length);
    ogs_nas_daylight_saving_time_t target;

    memcpy(&target, daylight_saving_time, sizeof(ogs_nas_daylight_saving_time_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  DAYLIGHT_SAVING_TIME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.60 UE radio capability ID
 * O TLV 3-n */
int ogs_nas_eps_decode_ue_radio_capability_id(ogs_nas_ue_radio_capability_id_t *ue_radio_capability_id, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_radio_capability_id_t *source = (ogs_nas_ue_radio_capability_id_t *)pkbuf->data;

    ue_radio_capability_id->length = source->length;
    size = ue_radio_capability_id->length + sizeof(ue_radio_capability_id->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_radio_capability_id) < size) return -1;
    memcpy(ue_radio_capability_id, pkbuf->data - size, size);

    //("  UE_RADIO_CAPABILITY_ID - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_radio_capability_id(pkbuf_t *pkbuf, ogs_nas_ue_radio_capability_id_t *ue_radio_capability_id)
{
    int size = ue_radio_capability_id->length + sizeof(ue_radio_capability_id->length);
    ogs_nas_ue_radio_capability_id_t target;

    memcpy(&target, ue_radio_capability_id, sizeof(ogs_nas_ue_radio_capability_id_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_RADIO_CAPABILITY_ID - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.61 UE radio capability ID deletion indication
 * O TV 1 */
int ogs_nas_eps_decode_ue_radio_capability_id_deletion_indication(ogs_nas_ue_radio_capability_id_deletion_indication_t *ue_radio_capability_id_deletion_indication, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_ue_radio_capability_id_deletion_indication_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(ue_radio_capability_id_deletion_indication, pkbuf->data - size, size);

    //("  UE_RADIO_CAPABILITY_ID_DELETION_INDICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_radio_capability_id_deletion_indication(pkbuf_t *pkbuf, ogs_nas_ue_radio_capability_id_deletion_indication_t *ue_radio_capability_id_deletion_indication)
{
    int size = sizeof(ogs_nas_ue_radio_capability_id_deletion_indication_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, ue_radio_capability_id_deletion_indication, size);

    //("  UE_RADIO_CAPABILITY_ID_DELETION_INDICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.62 WUS assistance information
 * O TLV 3-n */
int ogs_nas_eps_decode_wus_assistance_information(ogs_nas_wus_assistance_information_t *wus_assistance_information, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_wus_assistance_information_t *source = (ogs_nas_wus_assistance_information_t *)pkbuf->data;

    wus_assistance_information->length = source->length;
    size = wus_assistance_information->length + sizeof(wus_assistance_information->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*wus_assistance_information) < size) return -1;
    memcpy(wus_assistance_information, pkbuf->data - size, size);

    //("  WUS_ASSISTANCE_INFORMATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_wus_assistance_information(pkbuf_t *pkbuf, ogs_nas_wus_assistance_information_t *wus_assistance_information)
{
    int size = wus_assistance_information->length + sizeof(wus_assistance_information->length);
    ogs_nas_wus_assistance_information_t target;

    memcpy(&target, wus_assistance_information, sizeof(ogs_nas_wus_assistance_information_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  WUS_ASSISTANCE_INFORMATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.63 NB-S1 DRX parameter
 * O TLV 3 */
int ogs_nas_eps_decode_nb_s1_drx_parameter(ogs_nas_nb_s1_drx_parameter_t *nb_s1_drx_parameter, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_nb_s1_drx_parameter_t *source = (ogs_nas_nb_s1_drx_parameter_t *)pkbuf->data;

    nb_s1_drx_parameter->length = source->length;
    size = nb_s1_drx_parameter->length + sizeof(nb_s1_drx_parameter->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*nb_s1_drx_parameter) < size) return -1;
    memcpy(nb_s1_drx_parameter, pkbuf->data - size, size);

    //("  NB_S1_DRX_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_nb_s1_drx_parameter(pkbuf_t *pkbuf, ogs_nas_nb_s1_drx_parameter_t *nb_s1_drx_parameter)
{
    int size = nb_s1_drx_parameter->length + sizeof(nb_s1_drx_parameter->length);
    ogs_nas_nb_s1_drx_parameter_t target;

    memcpy(&target, nb_s1_drx_parameter, sizeof(ogs_nas_nb_s1_drx_parameter_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  NB_S1_DRX_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.64 IMSI offset
 * O TLV 4 */
int ogs_nas_eps_decode_imsi_offset(ogs_nas_imsi_offset_t *imsi_offset, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_imsi_offset_t *source = (ogs_nas_imsi_offset_t *)pkbuf->data;

    imsi_offset->length = source->length;
    size = imsi_offset->length + sizeof(imsi_offset->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*imsi_offset) < size) return -1;
    memcpy(imsi_offset, pkbuf->data - size, size);

    //("  IMSI_OFFSET - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_imsi_offset(pkbuf_t *pkbuf, ogs_nas_imsi_offset_t *imsi_offset)
{
    int size = imsi_offset->length + sizeof(imsi_offset->length);
    ogs_nas_imsi_offset_t target;

    memcpy(&target, imsi_offset, sizeof(ogs_nas_imsi_offset_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  IMSI_OFFSET - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.65 UE request type
 * O TLV 3 */
int ogs_nas_eps_decode_ue_request_type(ogs_nas_ue_request_type_t *ue_request_type, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_ue_request_type_t *source = (ogs_nas_ue_request_type_t *)pkbuf->data;

    ue_request_type->length = source->length;
    size = ue_request_type->length + sizeof(ue_request_type->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*ue_request_type) < size) return -1;
    memcpy(ue_request_type, pkbuf->data - size, size);

    //("  UE_REQUEST_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_ue_request_type(pkbuf_t *pkbuf, ogs_nas_ue_request_type_t *ue_request_type)
{
    int size = ue_request_type->length + sizeof(ue_request_type->length);
    ogs_nas_ue_request_type_t target;

    memcpy(&target, ue_request_type, sizeof(ogs_nas_ue_request_type_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  UE_REQUEST_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.66 Paging restriction
 * O TLV 3-5 */
int ogs_nas_eps_decode_paging_restriction(ogs_nas_paging_restriction_t *paging_restriction, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_paging_restriction_t *source = (ogs_nas_paging_restriction_t *)pkbuf->data;

    paging_restriction->length = source->length;
    size = paging_restriction->length + sizeof(paging_restriction->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*paging_restriction) < size) return -1;
    memcpy(paging_restriction, pkbuf->data - size, size);

    //("  PAGING_RESTRICTION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_paging_restriction(pkbuf_t *pkbuf, ogs_nas_paging_restriction_t *paging_restriction)
{
    int size = paging_restriction->length + sizeof(paging_restriction->length);
    ogs_nas_paging_restriction_t target;

    memcpy(&target, paging_restriction, sizeof(ogs_nas_paging_restriction_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PAGING_RESTRICTION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.67 EPS additional request result
 * O TLV 3 */
int ogs_nas_eps_decode_eps_additional_request_result(ogs_nas_eps_additional_request_result_t *eps_additional_request_result, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_additional_request_result_t *source = (ogs_nas_eps_additional_request_result_t *)pkbuf->data;

    eps_additional_request_result->length = source->length;
    size = eps_additional_request_result->length + sizeof(eps_additional_request_result->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_additional_request_result) < size) return -1;
    memcpy(eps_additional_request_result, pkbuf->data - size, size);

    //("  EPS_ADDITIONAL_REQUEST_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_additional_request_result(pkbuf_t *pkbuf, ogs_nas_eps_additional_request_result_t *eps_additional_request_result)
{
    int size = eps_additional_request_result->length + sizeof(eps_additional_request_result->length);
    ogs_nas_eps_additional_request_result_t target;

    memcpy(&target, eps_additional_request_result, sizeof(ogs_nas_eps_additional_request_result_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_ADDITIONAL_REQUEST_RESULT - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.7 Detach type
 * M V 1/2 */
int ogs_nas_eps_decode_detach_type(ogs_nas_detach_type_t *detach_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_detach_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(detach_type, pkbuf->data - size, size);

    //("  DETACH_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_detach_type(pkbuf_t *pkbuf, ogs_nas_detach_type_t *detach_type)
{
    int size = sizeof(ogs_nas_detach_type_t);
    ogs_nas_detach_type_t target;

    memcpy(&target, detach_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  DETACH_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.8 DRX parameter
 * O TV 3 */
int ogs_nas_eps_decode_drx_parameter(ogs_nas_drx_parameter_t *drx_parameter, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_drx_parameter_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(drx_parameter, pkbuf->data - size, size);

    //("  DRX_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_drx_parameter(pkbuf_t *pkbuf, ogs_nas_drx_parameter_t *drx_parameter)
{
    int size = sizeof(ogs_nas_drx_parameter_t);
    ogs_nas_drx_parameter_t target;

    memcpy(&target, drx_parameter, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  DRX_PARAMETER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.3.9 EMM cause
 * O TV 2 */
int ogs_nas_eps_decode_emm_cause(ogs_nas_emm_cause_t *emm_cause, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_emm_cause_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(emm_cause, pkbuf->data - size, size);

    //("  EMM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_emm_cause(pkbuf_t *pkbuf, ogs_nas_emm_cause_t *emm_cause)
{
    int size = sizeof(ogs_nas_emm_cause_t);
    ogs_nas_emm_cause_t target;

    memcpy(&target, emm_cause, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EMM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.1 Access point name
 * M LV 2-101 */
int ogs_nas_eps_decode_access_point_name(ogs_nas_access_point_name_t *access_point_name, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_access_point_name_t *source = (ogs_nas_access_point_name_t *)pkbuf->data;

    access_point_name->length = source->length;
    size = access_point_name->length + sizeof(access_point_name->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*access_point_name) < size) return -1;
    memcpy(access_point_name, pkbuf->data - size, size);

    {
        char apn[OGS_MAX_APN_LEN+1];
        access_point_name->length = ogs_fqdn_parse(apn, access_point_name->apn, ogs_min(access_point_name->length, OGS_MAX_APN_LEN));
        if (access_point_name->length > 0) {
            ogs_cpystrn(access_point_name->apn, apn, ogs_min(access_point_name->length, OGS_MAX_APN_LEN)+1);
        } else {
            //("UE not APN setting");
        }
    }

    //("  ACCESS_POINT_NAME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_access_point_name(pkbuf_t *pkbuf, ogs_nas_access_point_name_t *access_point_name)
{
    int size = access_point_name->length + sizeof(access_point_name->length);
    ogs_nas_access_point_name_t target;

    memcpy(&target, access_point_name, sizeof(ogs_nas_access_point_name_t));
    target.length = ogs_fqdn_build(target.apn, access_point_name->apn, access_point_name->length);
    size = target.length + sizeof(target.length);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  ACCESS_POINT_NAME - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.11 Protocol configuration options
 * O TLV 3-253 */
int ogs_nas_eps_decode_protocol_configuration_options(ogs_nas_protocol_configuration_options_t *protocol_configuration_options, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_protocol_configuration_options_t *source = (ogs_nas_protocol_configuration_options_t *)pkbuf->data;

    protocol_configuration_options->length = source->length;
    size = protocol_configuration_options->length + sizeof(protocol_configuration_options->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*protocol_configuration_options) < size) return -1;
    memcpy(protocol_configuration_options, pkbuf->data - size, size);

    //("  PROTOCOL_CONFIGURATION_OPTIONS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_protocol_configuration_options(pkbuf_t *pkbuf, ogs_nas_protocol_configuration_options_t *protocol_configuration_options)
{
    int size = protocol_configuration_options->length + sizeof(protocol_configuration_options->length);
    ogs_nas_protocol_configuration_options_t target;

    memcpy(&target, protocol_configuration_options, sizeof(ogs_nas_protocol_configuration_options_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PROTOCOL_CONFIGURATION_OPTIONS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.12 Quality of service
 * O TLV 14-22 */
int ogs_nas_eps_decode_quality_of_service(ogs_nas_quality_of_service_t *quality_of_service, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_quality_of_service_t *source = (ogs_nas_quality_of_service_t *)pkbuf->data;

    quality_of_service->length = source->length;
    size = quality_of_service->length + sizeof(quality_of_service->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*quality_of_service) < size) return -1;
    memcpy(quality_of_service, pkbuf->data - size, size);

    //("  QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_quality_of_service(pkbuf_t *pkbuf, ogs_nas_quality_of_service_t *quality_of_service)
{
    int size = quality_of_service->length + sizeof(quality_of_service->length);
    ogs_nas_quality_of_service_t target;

    memcpy(&target, quality_of_service, sizeof(ogs_nas_quality_of_service_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.13 Radio priority
 * O TV 1 */
int ogs_nas_eps_decode_radio_priority(ogs_nas_radio_priority_t *radio_priority, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_radio_priority_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(radio_priority, pkbuf->data - size, size);

    //("  RADIO_PRIORITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_radio_priority(pkbuf_t *pkbuf, ogs_nas_radio_priority_t *radio_priority)
{
    int size = sizeof(ogs_nas_radio_priority_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, radio_priority, size);

    //("  RADIO_PRIORITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.13A Re-attempt indicator
 * O TLV 3 */
int ogs_nas_eps_decode_re_attempt_indicator(ogs_nas_re_attempt_indicator_t *re_attempt_indicator, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_re_attempt_indicator_t *source = (ogs_nas_re_attempt_indicator_t *)pkbuf->data;

    re_attempt_indicator->length = source->length;
    size = re_attempt_indicator->length + sizeof(re_attempt_indicator->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*re_attempt_indicator) < size) return -1;
    memcpy(re_attempt_indicator, pkbuf->data - size, size);

    //("  RE_ATTEMPT_INDICATOR - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_re_attempt_indicator(pkbuf_t *pkbuf, ogs_nas_re_attempt_indicator_t *re_attempt_indicator)
{
    int size = re_attempt_indicator->length + sizeof(re_attempt_indicator->length);
    ogs_nas_re_attempt_indicator_t target;

    memcpy(&target, re_attempt_indicator, sizeof(ogs_nas_re_attempt_indicator_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  RE_ATTEMPT_INDICATOR - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.14 Request type
 * M V 1/2 */
int ogs_nas_eps_decode_request_type(ogs_nas_request_type_t *request_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_request_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(request_type, pkbuf->data - size, size);

    //("  REQUEST_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_request_type(pkbuf_t *pkbuf, ogs_nas_request_type_t *request_type)
{
    int size = sizeof(ogs_nas_request_type_t);
    ogs_nas_request_type_t target;

    memcpy(&target, request_type, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  REQUEST_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.15 Traffic flow aggregate description
 * M LV 2-256 */
int ogs_nas_eps_decode_traffic_flow_aggregate_description(ogs_nas_traffic_flow_aggregate_description_t *traffic_flow_aggregate_description, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_traffic_flow_aggregate_description_t *source = (ogs_nas_traffic_flow_aggregate_description_t *)pkbuf->data;

    traffic_flow_aggregate_description->length = source->length;
    size = traffic_flow_aggregate_description->length + sizeof(traffic_flow_aggregate_description->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*traffic_flow_aggregate_description) < size) return -1;
    memcpy(traffic_flow_aggregate_description, pkbuf->data - size, size);

    //("  TRAFFIC_FLOW_AGGREGATE_DESCRIPTION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_traffic_flow_aggregate_description(pkbuf_t *pkbuf, ogs_nas_traffic_flow_aggregate_description_t *traffic_flow_aggregate_description)
{
    int size = traffic_flow_aggregate_description->length + sizeof(traffic_flow_aggregate_description->length);
    ogs_nas_traffic_flow_aggregate_description_t target;

    memcpy(&target, traffic_flow_aggregate_description, sizeof(ogs_nas_traffic_flow_aggregate_description_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TRAFFIC_FLOW_AGGREGATE_DESCRIPTION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.16 Traffic flow template
 * M LV 2-256 */
int ogs_nas_eps_decode_traffic_flow_template(ogs_nas_traffic_flow_template_t *traffic_flow_template, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_traffic_flow_template_t *source = (ogs_nas_traffic_flow_template_t *)pkbuf->data;

    traffic_flow_template->length = source->length;
    size = traffic_flow_template->length + sizeof(traffic_flow_template->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*traffic_flow_template) < size) return -1;
    memcpy(traffic_flow_template, pkbuf->data - size, size);

    //("  TRAFFIC_FLOW_TEMPLATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_traffic_flow_template(pkbuf_t *pkbuf, ogs_nas_traffic_flow_template_t *traffic_flow_template)
{
    int size = traffic_flow_template->length + sizeof(traffic_flow_template->length);
    ogs_nas_traffic_flow_template_t target;

    memcpy(&target, traffic_flow_template, sizeof(ogs_nas_traffic_flow_template_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TRAFFIC_FLOW_TEMPLATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.17 Transaction identifier
 * O TLV 3-4 */
int ogs_nas_eps_decode_transaction_identifier(ogs_nas_transaction_identifier_t *transaction_identifier, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_transaction_identifier_t *source = (ogs_nas_transaction_identifier_t *)pkbuf->data;

    transaction_identifier->length = source->length;
    size = transaction_identifier->length + sizeof(transaction_identifier->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*transaction_identifier) < size) return -1;
    memcpy(transaction_identifier, pkbuf->data - size, size);

    //("  TRANSACTION_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_transaction_identifier(pkbuf_t *pkbuf, ogs_nas_transaction_identifier_t *transaction_identifier)
{
    int size = transaction_identifier->length + sizeof(transaction_identifier->length);
    ogs_nas_transaction_identifier_t target;

    memcpy(&target, transaction_identifier, sizeof(ogs_nas_transaction_identifier_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  TRANSACTION_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.18 WLAN offload acceptability
 * O TV 1 */
int ogs_nas_eps_decode_wlan_offload_acceptability(ogs_nas_wlan_offload_acceptability_t *wlan_offload_acceptability, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_wlan_offload_acceptability_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(wlan_offload_acceptability, pkbuf->data - size, size);

    //("  WLAN_OFFLOAD_ACCEPTABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_wlan_offload_acceptability(pkbuf_t *pkbuf, ogs_nas_wlan_offload_acceptability_t *wlan_offload_acceptability)
{
    int size = sizeof(ogs_nas_wlan_offload_acceptability_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, wlan_offload_acceptability, size);

    //("  WLAN_OFFLOAD_ACCEPTABILITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.19 NBIFOM container
 * O TLV 3-257 */
int ogs_nas_eps_decode_nbifom_container(ogs_nas_nbifom_container_t *nbifom_container, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_nbifom_container_t *source = (ogs_nas_nbifom_container_t *)pkbuf->data;

    nbifom_container->length = source->length;
    size = nbifom_container->length + sizeof(nbifom_container->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*nbifom_container) < size) return -1;
    memcpy(nbifom_container, pkbuf->data - size, size);

    //("  NBIFOM_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_nbifom_container(pkbuf_t *pkbuf, ogs_nas_nbifom_container_t *nbifom_container)
{
    int size = nbifom_container->length + sizeof(nbifom_container->length);
    ogs_nas_nbifom_container_t target;

    memcpy(&target, nbifom_container, sizeof(ogs_nas_nbifom_container_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  NBIFOM_CONTAINER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.2 APN aggregate maximum bit rate
 * O TLV 4-8 */
int ogs_nas_eps_decode_apn_aggregate_maximum_bit_rate(ogs_nas_apn_aggregate_maximum_bit_rate_t *apn_aggregate_maximum_bit_rate, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_apn_aggregate_maximum_bit_rate_t *source = (ogs_nas_apn_aggregate_maximum_bit_rate_t *)pkbuf->data;

    apn_aggregate_maximum_bit_rate->length = source->length;
    size = apn_aggregate_maximum_bit_rate->length + sizeof(apn_aggregate_maximum_bit_rate->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*apn_aggregate_maximum_bit_rate) < size) return -1;
    memcpy(apn_aggregate_maximum_bit_rate, pkbuf->data - size, size);

    //("  APN_AGGREGATE_MAXIMUM_BIT_RATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_apn_aggregate_maximum_bit_rate(pkbuf_t *pkbuf, ogs_nas_apn_aggregate_maximum_bit_rate_t *apn_aggregate_maximum_bit_rate)
{
    int size = apn_aggregate_maximum_bit_rate->length + sizeof(apn_aggregate_maximum_bit_rate->length);
    ogs_nas_apn_aggregate_maximum_bit_rate_t target;

    memcpy(&target, apn_aggregate_maximum_bit_rate, sizeof(ogs_nas_apn_aggregate_maximum_bit_rate_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  APN_AGGREGATE_MAXIMUM_BIT_RATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.22 Header compression configuration
 * O TLV 5-257 */
int ogs_nas_eps_decode_header_compression_configuration(ogs_nas_header_compression_configuration_t *header_compression_configuration, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_header_compression_configuration_t *source = (ogs_nas_header_compression_configuration_t *)pkbuf->data;

    header_compression_configuration->length = source->length;
    size = header_compression_configuration->length + sizeof(header_compression_configuration->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*header_compression_configuration) < size) return -1;
    memcpy(header_compression_configuration, pkbuf->data - size, size);

    header_compression_configuration->max_cid = be16toh(header_compression_configuration->max_cid);

    //("  HEADER_COMPRESSION_CONFIGURATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_header_compression_configuration(pkbuf_t *pkbuf, ogs_nas_header_compression_configuration_t *header_compression_configuration)
{
    int size = header_compression_configuration->length + sizeof(header_compression_configuration->length);
    ogs_nas_header_compression_configuration_t target;

    memcpy(&target, header_compression_configuration, sizeof(ogs_nas_header_compression_configuration_t));
    target.max_cid = htobe16(header_compression_configuration->max_cid);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  HEADER_COMPRESSION_CONFIGURATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.23 Control plane only indication
 * O TV 1 */
int ogs_nas_eps_decode_control_plane_only_indication(ogs_nas_control_plane_only_indication_t *control_plane_only_indication, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_control_plane_only_indication_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(control_plane_only_indication, pkbuf->data - size, size);

    //("  CONTROL_PLANE_ONLY_INDICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_control_plane_only_indication(pkbuf_t *pkbuf, ogs_nas_control_plane_only_indication_t *control_plane_only_indication)
{
    int size = sizeof(ogs_nas_control_plane_only_indication_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, control_plane_only_indication, size);

    //("  CONTROL_PLANE_ONLY_INDICATION - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.26 Extended protocol configuration options
 * O TLV-E 4-65538 */
int ogs_nas_eps_decode_extended_protocol_configuration_options(ogs_nas_extended_protocol_configuration_options_t *extended_protocol_configuration_options, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_extended_protocol_configuration_options_t *source = (ogs_nas_extended_protocol_configuration_options_t *)pkbuf->data;

    extended_protocol_configuration_options->length = be16toh(source->length);
    size = extended_protocol_configuration_options->length + sizeof(extended_protocol_configuration_options->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    extended_protocol_configuration_options->buffer = pkbuf->data - size + sizeof(extended_protocol_configuration_options->length);

    //("  EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS - ");
    //(OGS_LOG_TRACE, (void*)extended_protocol_configuration_options->buffer, extended_protocol_configuration_options->length);

    return size;
}

int ogs_nas_eps_encode_extended_protocol_configuration_options(pkbuf_t *pkbuf, ogs_nas_extended_protocol_configuration_options_t *extended_protocol_configuration_options)
{
    int size = 0;
    int target;

    assert(extended_protocol_configuration_options);
    assert(extended_protocol_configuration_options->buffer);

    size = sizeof(extended_protocol_configuration_options->length);
    assert(pkbuf_pull(pkbuf, size));
    target = htobe16(extended_protocol_configuration_options->length);
    memcpy(pkbuf->data - size, &target, size);

    size = extended_protocol_configuration_options->length;
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, extended_protocol_configuration_options->buffer, size);

    //("  EXTENDED_PROTOCOL_CONFIGURATION_OPTIONS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return extended_protocol_configuration_options->length + sizeof(extended_protocol_configuration_options->length);
}

/* 9.9.4.27 Header compression configuration status
 * O TLV 4 */
int ogs_nas_eps_decode_header_compression_configuration_status(ogs_nas_header_compression_configuration_status_t *header_compression_configuration_status, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_header_compression_configuration_status_t *source = (ogs_nas_header_compression_configuration_status_t *)pkbuf->data;

    header_compression_configuration_status->length = source->length;
    size = header_compression_configuration_status->length + sizeof(header_compression_configuration_status->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*header_compression_configuration_status) < size) return -1;
    memcpy(header_compression_configuration_status, pkbuf->data - size, size);

    //("  HEADER_COMPRESSION_CONFIGURATION_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_header_compression_configuration_status(pkbuf_t *pkbuf, ogs_nas_header_compression_configuration_status_t *header_compression_configuration_status)
{
    int size = header_compression_configuration_status->length + sizeof(header_compression_configuration_status->length);
    ogs_nas_header_compression_configuration_status_t target;

    memcpy(&target, header_compression_configuration_status, sizeof(ogs_nas_header_compression_configuration_status_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  HEADER_COMPRESSION_CONFIGURATION_STATUS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.28 Serving PLMN rate control
 * O TLV 4 */
int ogs_nas_eps_decode_serving_plmn_rate_control(ogs_nas_serving_plmn_rate_control_t *serving_plmn_rate_control, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_serving_plmn_rate_control_t *source = (ogs_nas_serving_plmn_rate_control_t *)pkbuf->data;

    serving_plmn_rate_control->length = source->length;
    size = serving_plmn_rate_control->length + sizeof(serving_plmn_rate_control->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*serving_plmn_rate_control) < size) return -1;
    memcpy(serving_plmn_rate_control, pkbuf->data - size, size);

    //("  SERVING_PLMN_RATE_CONTROL - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_serving_plmn_rate_control(pkbuf_t *pkbuf, ogs_nas_serving_plmn_rate_control_t *serving_plmn_rate_control)
{
    int size = serving_plmn_rate_control->length + sizeof(serving_plmn_rate_control->length);
    ogs_nas_serving_plmn_rate_control_t target;

    memcpy(&target, serving_plmn_rate_control, sizeof(ogs_nas_serving_plmn_rate_control_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  SERVING_PLMN_RATE_CONTROL - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.29 Extended APN aggregate maximum bit rate
 * O TLV 8 */
int ogs_nas_eps_decode_extended_apn_aggregate_maximum_bit_rate(ogs_nas_extended_apn_aggregate_maximum_bit_rate_t *extended_apn_aggregate_maximum_bit_rate, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_extended_apn_aggregate_maximum_bit_rate_t *source = (ogs_nas_extended_apn_aggregate_maximum_bit_rate_t *)pkbuf->data;

    extended_apn_aggregate_maximum_bit_rate->length = source->length;
    size = extended_apn_aggregate_maximum_bit_rate->length + sizeof(extended_apn_aggregate_maximum_bit_rate->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*extended_apn_aggregate_maximum_bit_rate) < size) return -1;
    memcpy(extended_apn_aggregate_maximum_bit_rate, pkbuf->data - size, size);

    //("  EXTENDED_APN_AGGREGATE_MAXIMUM_BIT_RATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_extended_apn_aggregate_maximum_bit_rate(pkbuf_t *pkbuf, ogs_nas_extended_apn_aggregate_maximum_bit_rate_t *extended_apn_aggregate_maximum_bit_rate)
{
    int size = extended_apn_aggregate_maximum_bit_rate->length + sizeof(extended_apn_aggregate_maximum_bit_rate->length);
    ogs_nas_extended_apn_aggregate_maximum_bit_rate_t target;

    memcpy(&target, extended_apn_aggregate_maximum_bit_rate, sizeof(ogs_nas_extended_apn_aggregate_maximum_bit_rate_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EXTENDED_APN_AGGREGATE_MAXIMUM_BIT_RATE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.2A Connectivity type
 * O TV 1 */
int ogs_nas_eps_decode_connectivity_type(ogs_nas_connectivity_type_t *connectivity_type, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_connectivity_type_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(connectivity_type, pkbuf->data - size, size);

    //("  CONNECTIVITY_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_connectivity_type(pkbuf_t *pkbuf, ogs_nas_connectivity_type_t *connectivity_type)
{
    int size = sizeof(ogs_nas_connectivity_type_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, connectivity_type, size);

    //("  CONNECTIVITY_TYPE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.3 EPS quality of service
 * M LV 2-14 */
int ogs_nas_eps_decode_eps_quality_of_service(ogs_nas_eps_quality_of_service_t *eps_quality_of_service, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_eps_quality_of_service_t *source = (ogs_nas_eps_quality_of_service_t *)pkbuf->data;

    eps_quality_of_service->length = source->length;
    size = eps_quality_of_service->length + sizeof(eps_quality_of_service->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*eps_quality_of_service) < size) return -1;
    memcpy(eps_quality_of_service, pkbuf->data - size, size);

    //("  EPS_QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_eps_quality_of_service(pkbuf_t *pkbuf, ogs_nas_eps_quality_of_service_t *eps_quality_of_service)
{
    int size = eps_quality_of_service->length + sizeof(eps_quality_of_service->length);
    ogs_nas_eps_quality_of_service_t target;

    memcpy(&target, eps_quality_of_service, sizeof(ogs_nas_eps_quality_of_service_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EPS_QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.30 Extended quality of service
 * O TLV 12 */
int ogs_nas_eps_decode_extended_quality_of_service(ogs_nas_extended_quality_of_service_t *extended_quality_of_service, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_extended_quality_of_service_t *source = (ogs_nas_extended_quality_of_service_t *)pkbuf->data;

    extended_quality_of_service->length = source->length;
    size = extended_quality_of_service->length + sizeof(extended_quality_of_service->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*extended_quality_of_service) < size) return -1;
    memcpy(extended_quality_of_service, pkbuf->data - size, size);

    //("  EXTENDED_QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_extended_quality_of_service(pkbuf_t *pkbuf, ogs_nas_extended_quality_of_service_t *extended_quality_of_service)
{
    int size = extended_quality_of_service->length + sizeof(extended_quality_of_service->length);
    ogs_nas_extended_quality_of_service_t target;

    memcpy(&target, extended_quality_of_service, sizeof(ogs_nas_extended_quality_of_service_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  EXTENDED_QUALITY_OF_SERVICE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.4 ESM cause
 * O TV 2 */
int ogs_nas_eps_decode_esm_cause(ogs_nas_esm_cause_t *esm_cause, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_esm_cause_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(esm_cause, pkbuf->data - size, size);

    //("  ESM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_esm_cause(pkbuf_t *pkbuf, ogs_nas_esm_cause_t *esm_cause)
{
    int size = sizeof(ogs_nas_esm_cause_t);
    ogs_nas_esm_cause_t target;

    memcpy(&target, esm_cause, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  ESM_CAUSE - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.5 ESM information transfer flag
 * O TV 1 */
int ogs_nas_eps_decode_esm_information_transfer_flag(ogs_nas_esm_information_transfer_flag_t *esm_information_transfer_flag, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_esm_information_transfer_flag_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(esm_information_transfer_flag, pkbuf->data - size, size);

    //("  ESM_INFORMATION_TRANSFER_FLAG - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_esm_information_transfer_flag(pkbuf_t *pkbuf, ogs_nas_esm_information_transfer_flag_t *esm_information_transfer_flag)
{
    int size = sizeof(ogs_nas_esm_information_transfer_flag_t);

    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, esm_information_transfer_flag, size);

    //("  ESM_INFORMATION_TRANSFER_FLAG - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.6 Linked EPS bearer identity
 * M V 1/2 */
int ogs_nas_eps_decode_linked_eps_bearer_identity(ogs_nas_linked_eps_bearer_identity_t *linked_eps_bearer_identity, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_linked_eps_bearer_identity_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(linked_eps_bearer_identity, pkbuf->data - size, size);

    //("  LINKED_EPS_BEARER_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_linked_eps_bearer_identity(pkbuf_t *pkbuf, ogs_nas_linked_eps_bearer_identity_t *linked_eps_bearer_identity)
{
    int size = sizeof(ogs_nas_linked_eps_bearer_identity_t);
    ogs_nas_linked_eps_bearer_identity_t target;

    memcpy(&target, linked_eps_bearer_identity, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  LINKED_EPS_BEARER_IDENTITY - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.7 LLC service access point identifier
 * O TV 2 */
int ogs_nas_eps_decode_llc_service_access_point_identifier(ogs_nas_llc_service_access_point_identifier_t *llc_service_access_point_identifier, pkbuf_t *pkbuf)
{
    int size = sizeof(ogs_nas_llc_service_access_point_identifier_t);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    memcpy(llc_service_access_point_identifier, pkbuf->data - size, size);

    //("  LLC_SERVICE_ACCESS_POINT_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_llc_service_access_point_identifier(pkbuf_t *pkbuf, ogs_nas_llc_service_access_point_identifier_t *llc_service_access_point_identifier)
{
    int size = sizeof(ogs_nas_llc_service_access_point_identifier_t);
    ogs_nas_llc_service_access_point_identifier_t target;

    memcpy(&target, llc_service_access_point_identifier, size);
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  LLC_SERVICE_ACCESS_POINT_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.8 Packet flow Identifier
 * O TLV 3 */
int ogs_nas_eps_decode_packet_flow_identifier(ogs_nas_packet_flow_identifier_t *packet_flow_identifier, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_packet_flow_identifier_t *source = (ogs_nas_packet_flow_identifier_t *)pkbuf->data;

    packet_flow_identifier->length = source->length;
    size = packet_flow_identifier->length + sizeof(packet_flow_identifier->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*packet_flow_identifier) < size) return -1;
    memcpy(packet_flow_identifier, pkbuf->data - size, size);

    //("  PACKET_FLOW_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_packet_flow_identifier(pkbuf_t *pkbuf, ogs_nas_packet_flow_identifier_t *packet_flow_identifier)
{
    int size = packet_flow_identifier->length + sizeof(packet_flow_identifier->length);
    ogs_nas_packet_flow_identifier_t target;

    memcpy(&target, packet_flow_identifier, sizeof(ogs_nas_packet_flow_identifier_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PACKET_FLOW_IDENTIFIER - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

/* 9.9.4.9 PDN address
 * M LV 6-14 */
int ogs_nas_eps_decode_pdn_address(ogs_nas_pdn_address_t *pdn_address, pkbuf_t *pkbuf)
{
    int size = 0;
    ogs_nas_pdn_address_t *source = (ogs_nas_pdn_address_t *)pkbuf->data;

    pdn_address->length = source->length;
    size = pdn_address->length + sizeof(pdn_address->length);

    if (pkbuf_pull(pkbuf, size) == NULL) {
       //("pkbuf_pull() failed [size:%d]", (int)size);
       return -1;
    }

    if (sizeof(*pdn_address) < size) return -1;
    memcpy(pdn_address, pkbuf->data - size, size);

    //("  PDN_ADDRESS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

int ogs_nas_eps_encode_pdn_address(pkbuf_t *pkbuf, ogs_nas_pdn_address_t *pdn_address)
{
    int size = pdn_address->length + sizeof(pdn_address->length);
    ogs_nas_pdn_address_t target;

    memcpy(&target, pdn_address, sizeof(ogs_nas_pdn_address_t));
    assert(pkbuf_pull(pkbuf, size));
    memcpy(pkbuf->data - size, &target, size);

    //("  PDN_ADDRESS - ");
    //(OGS_LOG_TRACE, pkbuf->data - size, size);

    return size;
}

