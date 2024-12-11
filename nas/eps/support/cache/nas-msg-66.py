ies = []
ies.append({ "iei" : "", "value" : "EPS attach result", "type" : "EPS attach result", "reference" : "9.9.3.10", "presence" : "M", "format" : "V", "length" : "1/2"})
ies.append({ "iei" : "", "value" : "T3412 value", "type" : "GPRS timer", "reference" : "9.9.3.16", "presence" : "M", "format" : "V", "length" : "1"})
ies.append({ "iei" : "", "value" : "TAI list", "type" : "Tracking area identity list", "reference" : "9.9.3.33", "presence" : "M", "format" : "LV", "length" : "7-97"})
ies.append({ "iei" : "", "value" : "ESM message container", "type" : "ESM message container", "reference" : "9.9.3.15", "presence" : "M", "format" : "LV-E", "length" : "5-n"})
ies.append({ "iei" : "50", "value" : "GUTI", "type" : "EPS mobile identity", "reference" : "9.9.3.12", "presence" : "O", "format" : "TLV", "length" : "13"})
ies.append({ "iei" : "13", "value" : "Location area identification", "type" : "Location area identification", "reference" : "9.9.2.2", "presence" : "O", "format" : "TV", "length" : "6"})
ies.append({ "iei" : "23", "value" : "MS identity", "type" : "Mobile identity", "reference" : "9.9.2.3", "presence" : "O", "format" : "TLV", "length" : "7-10"})
ies.append({ "iei" : "53", "value" : "EMM cause", "type" : "EMM cause", "reference" : "9.9.3.9", "presence" : "O", "format" : "TV", "length" : "2"})
ies.append({ "iei" : "17", "value" : "T3402 value", "type" : "GPRS timer", "reference" : "9.9.3.16", "presence" : "O", "format" : "TV", "length" : "2"})
ies.append({ "iei" : "59", "value" : "T3423 value", "type" : "GPRS timer", "reference" : "9.9.3.16", "presence" : "O", "format" : "TV", "length" : "2"})
ies.append({ "iei" : "4A", "value" : "Equivalent PLMNs", "type" : "PLMN list", "reference" : "9.9.2.8", "presence" : "O", "format" : "TLV", "length" : "5-47"})
ies.append({ "iei" : "34", "value" : "Emergency number list", "type" : "Emergency number list", "reference" : "9.9.3.37", "presence" : "O", "format" : "TLV", "length" : "5-50"})
ies.append({ "iei" : "64", "value" : "EPS network feature support", "type" : "EPS network feature support", "reference" : "9.9.3.12A", "presence" : "O", "format" : "TLV", "length" : "3-4"})
ies.append({ "iei" : "F-", "value" : "Additional update result", "type" : "Additional update result", "reference" : "9.9.3.0A", "presence" : "O", "format" : "TV", "length" : "1"})
ies.append({ "iei" : "5E", "value" : "T3412 extended value", "type" : "GPRS timer 3", "reference" : "9.9.3.16B", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "6A", "value" : "T3324 value", "type" : "GPRS timer 2", "reference" : "9.9.3.16A", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "6E", "value" : "Extended DRX parameters", "type" : "Extended DRX parameters", "reference" : "9.9.3.46", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "65", "value" : "DCN-ID", "type" : "DCN-ID", "reference" : "9.9.3.48", "presence" : "O", "format" : "TLV", "length" : "4"})
ies.append({ "iei" : "E-", "value" : "SMS services status", "type" : "SMS services status", "reference" : "9.9.3.4B", "presence" : "O", "format" : "TV", "length" : "1"})
ies.append({ "iei" : "D-", "value" : "Non-3GPP NW provided policies", "type" : "Non-3GPP NW provided policies", "reference" : "9.9.3.49", "presence" : "O", "format" : "TV", "length" : "1"})
ies.append({ "iei" : "6B", "value" : "T3448 value", "type" : "GPRS timer 2", "reference" : "9.9.3.16A", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "C-", "value" : "Network policy", "type" : "Network policy", "reference" : "9.9.3.52", "presence" : "O", "format" : "TV", "length" : "1"})
ies.append({ "iei" : "6C", "value" : "T3447 value", "type" : "GPRS timer 3", "reference" : "9.9.3.16B", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "7A", "value" : "Extended emergency number list", "type" : "Extended emergency number list", "reference" : "9.9.3.37A", "presence" : "O", "format" : "TLV-E", "length" : "7-65538"})
ies.append({ "iei" : "7C", "value" : "Ciphering key data", "type" : "Ciphering key data", "reference" : "9.9.3.56", "presence" : "O", "format" : "TLV-E", "length" : "35-2291"})
ies.append({ "iei" : "66", "value" : "UE radio capability ID", "type" : "UE radio capability ID", "reference" : "9.9.3.60", "presence" : "O", "format" : "TLV", "length" : "3-n"})
ies.append({ "iei" : "B-", "value" : "UE radio capability ID deletion indication", "type" : "UE radio capability ID deletion indication", "reference" : "9.9.3.61", "presence" : "O", "format" : "TV", "length" : "1"})
ies.append({ "iei" : "35", "value" : "Negotiated WUS assistance information", "type" : "WUS assistance information", "reference" : "9.9.3.62", "presence" : "O", "format" : "TLV", "length" : "3-n"})
ies.append({ "iei" : "36", "value" : "Negotiated DRX parameter in NB-S1 mode", "type" : "NB-S1 DRX parameter", "reference" : "9.9.3.63", "presence" : "O", "format" : "TLV", "length" : "3"})
ies.append({ "iei" : "38", "value" : "Negotiated IMSI offset", "type" : "IMSI offset", "reference" : "9.9.3.64", "presence" : "O", "format" : "TLV", "length" : "4"})
ies.append({ "iei" : "1D", "value" : "Forbidden TAI for the list of forbidden tracking areas for roaming", "type" : "Tracking area identity list", "reference" : "9.9.3.33", "presence" : "O", "format" : "TLV", "length" : "8-98"})
ies.append({ "iei" : "1E", "value" : "Forbidden TAI for the list of forbidden tracking areas forregional provision of service", "type" : "Tracking area identity list", "reference" : "9.9.3.33", "presence" : "O", "format" : "TLV", "length" : "8-98"})
msg_list[key]["ies"] = ies
