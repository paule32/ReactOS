/* Do not edit this file manually.
   This file is autogenerated by windmc.  */

//
//  The values are 32 bit layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      C    - is the Customer code flag
//
//      R    - is a reserved bit
//
//      Code - is the facility's status code
//
//      Sev  - is the severity code
//
//           Success - 00
#define STATUS_SEVERITY_SUCCESS 0x0
//           Informational - 01
#define STATUS_SEVERITY_INFORMATIONAL 0x1
//           Warning - 02
#define STATUS_SEVERITY_WARNING 0x2
//           Error - 03
#define STATUS_SEVERITY_ERROR 0x3
//
//      Facility - is the facility code
//
//           System - 0000
#define FACILITY_SYSTEM 0x0
//           Application - 0fff
//


 netevent.mc MESSAGE resources for netevent.dll


 message definitions

 Facility=System

 eventlog events 6000-6099

//
// MessageId: EVENT_LOG_FULL
//
#define EVENT_LOG_FULL (DWORD) 0x80001770

//
// MessageId: EVENT_LogFileNotOpened
//
#define EVENT_LogFileNotOpened (DWORD) 0x80001771

//
// MessageId: EVENT_LogFileCorrupt
//
#define EVENT_LogFileCorrupt (DWORD) 0x80001772

//
// MessageId: EVENT_DefaultLogCorrupt
//
#define EVENT_DefaultLogCorrupt (DWORD) 0x80001773

//
// MessageId: EVENT_BadDriverPacket
//
#define EVENT_BadDriverPacket (DWORD) 0x80001774

//
// MessageId: EVENT_EventlogStarted
//
#define EVENT_EventlogStarted (DWORD) 0x80001775

//
// MessageId: EVENT_EventlogStopped
//
#define EVENT_EventlogStopped (DWORD) 0x80001776

//
// MessageId: TITLE_EventlogMessageBox
//
#define TITLE_EventlogMessageBox (DWORD) 0x80001777

//
// MessageId: EVENT_EventlogAbnormalShutdown
//
#define EVENT_EventlogAbnormalShutdown (DWORD) 0x80001778

//
// MessageId: EVENT_EventLogProductInfo
//
#define EVENT_EventLogProductInfo (DWORD) 0x80001779

//
// MessageId: EVENT_ServiceNoEventLog
//
#define EVENT_ServiceNoEventLog (DWORD) 0xc000177a

//
// MessageId: EVENT_ComputerNameChange
//
#define EVENT_ComputerNameChange (DWORD) 0xc000177b

//
// MessageId: EVENT_DNSDomainNameChange
//
#define EVENT_DNSDomainNameChange (DWORD) 0xc000177c


 system events 6100 - 6199

//
// MessageId: EVENT_UP_DRIVER_ON_MP
//
#define EVENT_UP_DRIVER_ON_MP (DWORD) 0xc00017d4


 service controller events 7000-7899

//
// MessageId: EVENT_SERVICE_START_FAILED
//
#define EVENT_SERVICE_START_FAILED (DWORD) 0xc0001b58

//
// MessageId: EVENT_SERVICE_START_FAILED_II
//
#define EVENT_SERVICE_START_FAILED_II (DWORD) 0xc0001b59

//
// MessageId: EVENT_SERVICE_START_FAILED_GROUP
//
#define EVENT_SERVICE_START_FAILED_GROUP (DWORD) 0xc0001b5a

//
// MessageId: EVENT_SERVICE_START_FAILED_NONE
//
#define EVENT_SERVICE_START_FAILED_NONE (DWORD) 0xc0001b5b

//
// MessageId: EVENT_CALL_TO_FUNCTION_FAILED
//
#define EVENT_CALL_TO_FUNCTION_FAILED (DWORD) 0xc0001b5d

//
// MessageId: EVENT_CALL_TO_FUNCTION_FAILED_II
//
#define EVENT_CALL_TO_FUNCTION_FAILED_II (DWORD) 0xc0001b5e

//
// MessageId: EVENT_REVERTED_TO_LASTKNOWNGOOD
//
#define EVENT_REVERTED_TO_LASTKNOWNGOOD (DWORD) 0xc0001b5f

//
// MessageId: EVENT_BAD_ACCOUNT_NAME
//
#define EVENT_BAD_ACCOUNT_NAME (DWORD) 0xc0001b60

//
// MessageId: EVENT_CONNECTION_TIMEOUT
//
#define EVENT_CONNECTION_TIMEOUT (DWORD) 0xc0001b61

//
// MessageId: EVENT_READFILE_TIMEOUT
//
#define EVENT_READFILE_TIMEOUT (DWORD) 0xc0001b62

//
// MessageId: EVENT_TRANSACT_TIMEOUT
//
#define EVENT_TRANSACT_TIMEOUT (DWORD) 0xc0001b63

//
// MessageId: EVENT_TRANSACT_INVALID
//
#define EVENT_TRANSACT_INVALID (DWORD) 0xc0001b64

//
// MessageId: EVENT_FIRST_LOGON_FAILED
//
#define EVENT_FIRST_LOGON_FAILED (DWORD) 0xc0001b65

//
// MessageId: EVENT_SECOND_LOGON_FAILED
//
#define EVENT_SECOND_LOGON_FAILED (DWORD) 0xc0001b66

//
// MessageId: EVENT_INVALID_DRIVER_DEPENDENCY
//
#define EVENT_INVALID_DRIVER_DEPENDENCY (DWORD) 0xc0001b67

//
// MessageId: EVENT_BAD_SERVICE_STATE
//
#define EVENT_BAD_SERVICE_STATE (DWORD) 0xc0001b68

//
// MessageId: EVENT_CIRCULAR_DEPENDENCY_DEMAND
//
#define EVENT_CIRCULAR_DEPENDENCY_DEMAND (DWORD) 0xc0001b69

//
// MessageId: EVENT_CIRCULAR_DEPENDENCY_AUTO
//
#define EVENT_CIRCULAR_DEPENDENCY_AUTO (DWORD) 0xc0001b6a

//
// MessageId: EVENT_DEPEND_ON_LATER_SERVICE
//
#define EVENT_DEPEND_ON_LATER_SERVICE (DWORD) 0xc0001b6b

//
// MessageId: EVENT_DEPEND_ON_LATER_GROUP
//
#define EVENT_DEPEND_ON_LATER_GROUP (DWORD) 0xc0001b6c

//
// MessageId: EVENT_SEVERE_SERVICE_FAILED
//
#define EVENT_SEVERE_SERVICE_FAILED (DWORD) 0xc0001b6d

//
// MessageId: EVENT_SERVICE_START_HUNG
//
#define EVENT_SERVICE_START_HUNG (DWORD) 0xc0001b6e

//
// MessageId: EVENT_SERVICE_EXIT_FAILED
//
#define EVENT_SERVICE_EXIT_FAILED (DWORD) 0xc0001b6f

//
// MessageId: EVENT_SERVICE_EXIT_FAILED_SPECIFIC
//
#define EVENT_SERVICE_EXIT_FAILED_SPECIFIC (DWORD) 0xc0001b70

//
// MessageId: EVENT_SERVICE_START_AT_BOOT_FAILED
//
#define EVENT_SERVICE_START_AT_BOOT_FAILED (DWORD) 0xc0001b71

//
// MessageId: EVENT_BOOT_SYSTEM_DRIVERS_FAILED
//
#define EVENT_BOOT_SYSTEM_DRIVERS_FAILED (DWORD) 0xc0001b72

//
// MessageId: EVENT_RUNNING_LASTKNOWNGOOD
//
#define EVENT_RUNNING_LASTKNOWNGOOD (DWORD) 0xc0001b73

//
// MessageId: EVENT_TAKE_OWNERSHIP
//
#define EVENT_TAKE_OWNERSHIP (DWORD) 0xc0001b74

//
// MessageId: TITLE_SC_MESSAGE_BOX
//
#define TITLE_SC_MESSAGE_BOX (DWORD) 0xc0001b75

//
// MessageId: EVENT_SERVICE_NOT_INTERACTIVE
//
#define EVENT_SERVICE_NOT_INTERACTIVE (DWORD) 0xc0001b76

//
// MessageId: EVENT_SERVICE_CRASH
//
#define EVENT_SERVICE_CRASH (DWORD) 0xc0001b77

//
// MessageId: EVENT_SERVICE_RECOVERY_FAILED
//
#define EVENT_SERVICE_RECOVERY_FAILED (DWORD) 0xc0001b78

//
// MessageId: EVENT_SERVICE_SCESRV_FAILED
//
#define EVENT_SERVICE_SCESRV_FAILED (DWORD) 0xc0001b79

//
// MessageId: EVENT_SERVICE_CRASH_NO_ACTION
//
#define EVENT_SERVICE_CRASH_NO_ACTION (DWORD) 0xc0001b7a

//
// MessageId: EVENT_SERVICE_CONTROL_SUCCESS
//
#define EVENT_SERVICE_CONTROL_SUCCESS (DWORD) 0x40001b7b

//
// MessageId: EVENT_SERVICE_STATUS_SUCCESS
//
#define EVENT_SERVICE_STATUS_SUCCESS (DWORD) 0x40001b7c

//
// MessageId: EVENT_SERVICE_CONFIG_BACKOUT_FAILED
//
#define EVENT_SERVICE_CONFIG_BACKOUT_FAILED (DWORD) 0xc0001b7d

//
// MessageId: EVENT_FIRST_LOGON_FAILED_II
//
#define EVENT_FIRST_LOGON_FAILED_II (DWORD) 0xc0001b7e

//
// MessageId: EVENT_SERVICE_DIFFERENT_PID_CONNECTED
//
#define EVENT_SERVICE_DIFFERENT_PID_CONNECTED (DWORD) 0x80001b7f

//
// MessageId: EVENT_SERVICE_START_TYPE_CHANGED
//
#define EVENT_SERVICE_START_TYPE_CHANGED (DWORD) 0x40001b80

//
// MessageId: EVENT_SERVICE_LOGON_TYPE_NOT_GRANTED
//
#define EVENT_SERVICE_LOGON_TYPE_NOT_GRANTED (DWORD) 0xc0001b81

//
// MessageId: EVENT_SERVICE_STOP_SUCCESS_WITH_REASON
//
#define EVENT_SERVICE_STOP_SUCCESS_WITH_REASON (DWORD) 0x40001b82

//
// MessageId: EVENT_SERVICE_SHUTDOWN_FAILED
//
#define EVENT_SERVICE_SHUTDOWN_FAILED (DWORD) 0xc0001b83


 transport events 9000-9499

//
// MessageId: EVENT_TRANSPORT_REGISTER_FAILED
//
#define EVENT_TRANSPORT_REGISTER_FAILED (DWORD) 0xc000232c

//
// MessageId: EVENT_TRANSPORT_ADAPTER_NOT_FOUND
//
#define EVENT_TRANSPORT_ADAPTER_NOT_FOUND (DWORD) 0xc000232e
