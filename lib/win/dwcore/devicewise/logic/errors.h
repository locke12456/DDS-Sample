//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/event.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_ERRORS_H_
#define DW_LOGIC_ERRORS_H_

#define ERR_EVT_MODULE_NOT_LOADED		-5101
#define ERR_EVT_TYPE_EXISTS				-5102
#define ERR_EVT_TYPE_NOT_FOUND			-5103
#define ERR_EVT_NOT_FOUND				-5104
#define ERR_EVT_REMOTE_CONN				-5105
#define ERR_EVT_SHUTDOWN				-5106
#define ERR_EVT_DEAD					-5107
#define ERR_EVT_NO_METADATA				-5108
#define ERR_EVT_VAR_NOT_SERVICED		-5109
#define ERR_EVT_VAR_NOTFOUND			-5111
#define ERR_EVT_PROP_MISSING			-5112
#define ERR_EVT_PROP_INVALID			-5113
#define ERR_EVT_BAD_REM_PARMS			-5121
#define ERR_EVT_NO_MATCH				-5131
#define ERR_EVT_DUPE_ENTRY				-5132

#define ERR_ACT_MODULE_NOT_LOADED		-5201
#define ERR_ACT_TYPE_EXISTS				-5202
#define ERR_ACT_TYPE_NOT_FOUND			-5203
#define ERR_ACT_NOT_FOUND				-5204
#define ERR_ACT_NO_METADATA				-5208
#define ERR_ACT_VAR_NOT_SERVICED		-5209
#define ERR_ACT_INVALID					-5211
#define ERR_ACT_PROP_MISSING			-5212
#define ERR_ACT_PROP_INVALID			-5213
#define ERR_ACT_INPUT_VAR_MISSING		-5214
#define ERR_ACT_OUTPUT_VAR_MISSING		-5215
#define ERR_ACT_INPUT_VAR_BAD			-5216
#define ERR_ACT_OUTPUT_VAR_BAD			-5217
#define ERR_ACT_ROUTE_BAD				-5221
#define ERR_ACT_ROUTE_BAD_INDEX			-5222
#define ERR_ACT_ROUTE_UNWIRED			-5223
#define ERR_ACT_FAILED					-5224
#define ERR_ACT_DEFERRED_RESPONSE		-5299

#define ERR_PROJ_EXISTS					-5301
#define ERR_PROJ_NOTFOUND				-5302
#define ERR_PROJ_NOTSTARTED				-5303
#define ERR_PROJ_STARTED				-5304
#define ERR_PROJ_MODULE_NOT_LOADED		-5311
#define ERR_PROJ_HAS_LOADING_TRIGS		-5312

#define ERR_TRIG_EXISTS					-5401
#define ERR_TRIG_NOTFOUND				-5402
#define ERR_TRIG_NOTSTARTED				-5403
#define ERR_TRIG_STARTED				-5404
#define ERR_TRIG_NOTSTOPPED				-5405
#define ERR_TRIG_LOADED					-5406
#define ERR_TRIG_LOAD_FAILED			-5407
#define ERR_TRIG_UNLOADING				-5408
#define ERR_TRIG_BAD_MACRO				-5409
#define ERR_TRIG_OVERFLOW				-5410
#define ERR_TRIG_MODULE_NOT_LOADED		-5411
#define ERR_TRIG_ACTION_FAILED			-5412
#define ERR_TRIG_NOT_LICENSED			-5413
#define ERR_TRIG_BAD_SECURITY			-5414
#define ERR_TRIG_NOTLOADED				-5415
#define ERR_TRIG_TRANSITIONING			-5416
#define ERR_TRIG_ENDERR					-5417
#define ERR_TRIG_NO_ACTIONS_DEFINED		-5418
#define ERR_TRIG_UNKNOWN_DATA_TYPE		-5419
#define ERR_TRIG_FREELIST_FULL			-5420

#define ERR_TRIG_LOAD_MODULE_NOT_LOADED	-5421
#define ERR_TRIG_QUEUE_PURGED			-5422

#define ERR_TRIG_LOCAL_VAR_NOT_FOUND	-5431
#define ERR_TRIG_STATIC_VAR_NOT_FOUND	-5432

#define ERR_TRIG_REPORT_ALREADY_ON		-5441
#define ERR_TRIG_REPORT_NOT_FOUND		-5442
#define ERR_TRIG_REPORT_TOO_MANY_REPS	-5443
#define ERR_TRIG_REPORT_ON_INVALID		-5444
#define ERR_TRIG_REPORT_SUSPENDED		-5445
#define ERR_TRIG_REPORT_NOT_SUSPENDED	-5446

#define ERR_TRIG_XML_BAD_XML				-5451
#define ERR_TRIG_XML_BAD_EVENT				-5452
#define ERR_TRIG_XML_BAD_ACTION				-5453
#define ERR_TRIG_XML_LOCAL_VAR_NOTFOUND		-5454
#define ERR_TRIG_XML_STATIC_VAR_NOTFOUND	-5455

#define ERR_TRIG_EXEC_SUSPENDED			-5461
#define ERR_TRIG_EXEC_RUNNING			-5462

#define ERR_EXPRESSION_SEE_MSG			-5601
#define ERR_EXPRESSION_EXISTS			-5602
#define ERR_EXPRESSION_NOT_FOUND		-5603
#define ERR_EXPRESSION_BAD_XML			-5604
#define ERR_EXPRESSION_UNKNOWN			-5605
#define ERR_EXPRESSION_VAR_NOT_FOUND	-5606
#define ERR_EXPRESSION_OVER_COUNT		-5607
#define ERR_EXPRESSION_UNDER_COUNT		-5608
#define ERR_EXPRESSION_INVALID_VAR		-5609
#define ERR_EXPRESSION_DIVIDE_BY_ZERO	-5610
#define ERR_EXPRESSION_BAD_DEF_LENGTH	-5611
#define ERR_EXPRESSION_DIVIDE_ITEMS		-5612

#define ERR_FOR_INVALID_ARGS			-5621
#define ERR_FOR_MISSING_ARGS			-5622

#define ERR_REMTRIGGER_TIMEOUT			-5631

#define ERR_REGULAR_UNKNOWN				-5701
#define ERR_REGULAR_BAD_XML				-5702
#define ERR_REGULAR_FAILED				-5703
#define ERR_REGULAR_VAR_NOT_FOUND		-5704
#define ERR_REGULAR_NOT_FOUND			-5705
#define ERR_REGULAR_INPUT_NOT_STRING	-5706

#define ERR_SECURITY_BAD_OP				-5711

#define ERR_DEVICE_CONTROL_BAD_OP		-5721

#define ERR_STRBLDR_BAD_FORMAT			-5731
#define ERR_STRBLDR_BAD_TAG_TOO_LONG	-5732
#define ERR_STRTIME_INVALID_COUNT		-5735

#define ERR_BITS_INDEX_OVERFLOW			-5741

#define ERR_WAIT_LESS_THAN_ZERO			-5742

#define ERR_LOCALDB_BLOB_NOT_SUPPORT	-5743

#define ERR_SUBTRIG_NOTSTARTED			-5744
#define ERR_SUBTRIG_NOTFOUND			-5745

#define ERR_BINARY_DECODE_BUFFER_OVERFLOW	-5746
#define ERR_BINARY_DECODE_OFFSET_OVERFLOW	-5747

#define ERR_SUBTRIG_STARTED				-5748

#define ERR_LOGGING_BAD_MINMAX			-5751

#define ERR_EMAIL_NO_MSG				-5761
#define ERR_EMAIL_NO_DEST				-5762
#define ERR_EMAIL_NO_FROM				-5763

#define ERR_DATAEVENT_BAD_XML			-5801
#define ERR_DATAEVENT_ARRAY_NO_DEADBAND	-5802

#define ERR_ONDEMAND_NOTFOUND			-5805

#define ERR_USEROP_EVT_EXISTS			-5811

#define ERR_DEMANDRW_OTHER				-5821
#define ERR_DEMANDRW_VALUE_UNDERFLOW	-5822
#define ERR_DEMANDRW_VALUE_OVERFLOW		-5823

#define ERR_UDP_SEND_LEN_OVERFLOW		-5831
#define ERR_UDP_SEND_INVALID_TYPE		-5832
#define ERR_UDP_SEND_LEN_0				-5833

#define ERR_UDP_RECEIVE_BIND_FAILED		-5840
#define ERR_UDP_RECEIVE_CREATE_FAILED	-5841

#define ERR_UDP_RECEIVE_BIND_FAILED		-5840
#define ERR_UDP_RECEIVE_CREATE_FAILED	-5841
#define ERR_UDP_RECEIVE_EVENT_FAILED	-5842

#endif /*DW_LOGIC_ERRORS_H_*/
