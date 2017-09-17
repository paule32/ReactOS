#pragma once


#define MAKE_S_ITF_HRESULT(x)   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, (x))
#define MAKE_E_ITF_HRESULT(x)   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, (x))
const unsigned int MPEG2_BASE = 0x200;

const HRESULT MPEG2_E_UNINITIALIZED                     = MAKE_E_ITF_HRESULT(MPEG2_BASE + 0);
const HRESULT MPEG2_E_ALREADY_INITIALIZED               = MAKE_E_ITF_HRESULT(MPEG2_BASE + 1);
const HRESULT MPEG2_E_OUT_OF_BOUNDS                     = MAKE_E_ITF_HRESULT(MPEG2_BASE + 2);
const HRESULT MPEG2_E_MALFORMED_TABLE                   = MAKE_E_ITF_HRESULT(MPEG2_BASE + 3);
const HRESULT MPEG2_E_UNDEFINED                         = MAKE_E_ITF_HRESULT(MPEG2_BASE + 4);
const HRESULT MPEG2_E_NOT_PRESENT                       = MAKE_E_ITF_HRESULT(MPEG2_BASE + 5);
const HRESULT MPEG2_E_SECTION_NOT_FOUND                 = MAKE_E_ITF_HRESULT(MPEG2_BASE + 6);
const HRESULT MPEG2_E_TX_STREAM_UNAVAILABLE             = MAKE_E_ITF_HRESULT(MPEG2_BASE + 7);
const HRESULT MPEG2_E_SERVICE_ID_NOT_FOUND              = MAKE_E_ITF_HRESULT(MPEG2_BASE + 8);
const HRESULT MPEG2_E_SERVICE_PMT_NOT_FOUND             = MAKE_E_ITF_HRESULT(MPEG2_BASE + 9);
const HRESULT MPEG2_E_DSI_NOT_FOUND                     = MAKE_E_ITF_HRESULT(MPEG2_BASE + 10);
const HRESULT MPEG2_E_SERVER_UNAVAILABLE                = MAKE_E_ITF_HRESULT(MPEG2_BASE + 11);
const HRESULT MPEG2_E_INVALID_CAROUSEL_ID               = MAKE_E_ITF_HRESULT(MPEG2_BASE + 12);
const HRESULT MPEG2_E_MALFORMED_DSMCC_MESSAGE           = MAKE_E_ITF_HRESULT(MPEG2_BASE + 13);
const HRESULT MPEG2_E_INVALID_SG_OBJECT_KIND            = MAKE_E_ITF_HRESULT(MPEG2_BASE + 14);
const HRESULT MPEG2_E_OBJECT_NOT_FOUND                  = MAKE_E_ITF_HRESULT(MPEG2_BASE + 15);
const HRESULT MPEG2_E_OBJECT_KIND_NOT_A_DIRECTORY       = MAKE_E_ITF_HRESULT(MPEG2_BASE + 16);
const HRESULT MPEG2_E_OBJECT_KIND_NOT_A_FILE            = MAKE_E_ITF_HRESULT(MPEG2_BASE + 17);
const HRESULT MPEG2_E_FILE_OFFSET_TOO_BIG               = MAKE_E_ITF_HRESULT(MPEG2_BASE + 18);
const HRESULT MPEG2_E_STREAM_STOPPED                    = MAKE_E_ITF_HRESULT(MPEG2_BASE + 19);
const HRESULT MPEG2_E_REGISTRY_ACCESS_FAILED            = MAKE_E_ITF_HRESULT(MPEG2_BASE + 20);
const HRESULT MPEG2_E_INVALID_UDP_PORT                  = MAKE_E_ITF_HRESULT(MPEG2_BASE + 21);
const HRESULT MPEG2_E_DATA_SOURCE_FAILED                = MAKE_E_ITF_HRESULT(MPEG2_BASE + 22);
const HRESULT MPEG2_E_DII_NOT_FOUND                     = MAKE_E_ITF_HRESULT(MPEG2_BASE + 23);
const HRESULT MPEG2_E_DSHOW_PIN_NOT_FOUND               = MAKE_E_ITF_HRESULT(MPEG2_BASE + 24);
const HRESULT MPEG2_E_BUFFER_TOO_SMALL                  = MAKE_E_ITF_HRESULT(MPEG2_BASE + 25);
const HRESULT MPEG2_E_MISSING_SECTIONS                  = MAKE_E_ITF_HRESULT(MPEG2_BASE + 26);
const HRESULT MPEG2_E_TOO_MANY_SECTIONS                 = MAKE_E_ITF_HRESULT(MPEG2_BASE + 27);
const HRESULT MPEG2_E_NEXT_TABLE_OPS_NOT_AVAILABLE      = MAKE_E_ITF_HRESULT(MPEG2_BASE + 28);

const HRESULT MPEG2_S_MORE_DATA_AVAILABLE               = MAKE_S_ITF_HRESULT(MPEG2_BASE + 0);
const HRESULT MPEG2_S_NO_MORE_DATA_AVAILABLE            = MAKE_S_ITF_HRESULT(MPEG2_BASE + 1);
const HRESULT MPEG2_S_SG_INFO_FOUND                     = MAKE_S_ITF_HRESULT(MPEG2_BASE + 2);
const HRESULT MPEG2_S_SG_INFO_NOT_FOUND                 = MAKE_S_ITF_HRESULT(MPEG2_BASE + 3);
const HRESULT MPEG2_S_MPE_INFO_FOUND                    = MAKE_S_ITF_HRESULT(MPEG2_BASE + 4);
const HRESULT MPEG2_S_MPE_INFO_NOT_FOUND                = MAKE_S_ITF_HRESULT(MPEG2_BASE + 5);
const HRESULT MPEG2_S_NEW_MODULE_VERSION                = MAKE_S_ITF_HRESULT(MPEG2_BASE + 6);

