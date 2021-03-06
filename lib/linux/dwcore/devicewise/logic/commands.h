//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/commands.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_COMMANDS_H_
#define DW_LOGIC_COMMANDS_H_

#define BLOCK_EVENT				51
#define CMD_EVT_REGISTER		5101
#define CMD_EVT_DEREGISTER		5102
#define CMD_EVT_ENUM 			5104
#define CMD_EVT_INFO 			5105
#define CMD_EVT_CREATE 			5110
#define CMD_EVT_SIGNAL 			5111
#define CMD_EVT_VERIFY 			5112
#define CMD_EVT_QUERY_METADATA	5113
#define CMD_EVT_NOTIFICATION	5120
#define CMD_EVT_COMPLETE 		5121

#define BLOCK_ACTION			52
#define CMD_ACT_ENUM			5204
#define CMD_ACT_INFO			5205
#define CMD_ACT_QUERY_METADATA	5213

#define BLOCK_PROJECT			53
#define CMD_PROJ_ADD			5301
#define CMD_PROJ_DEL			5303
#define CMD_PROJ_START			5304
#define CMD_PROJ_STOP			5305
#define CMD_PROJ_LIST			5307
#define CMD_PROJ_ENUM			5308

#define BLOCK_TRIGGER			54
#define CMD_TRIG_ADD			5401
#define CMD_TRIG_EDIT			5402
#define CMD_TRIG_DEL			5403
#define CMD_TRIG_START			5404
#define CMD_TRIG_STOP			5405
#define CMD_TRIG_INFO			5406
#define CMD_TRIG_LIST			5407
#define CMD_TRIG_COPY			5408
#define CMD_TRIG_ENUM			5409
#define CMD_TRIG_FIRE_NOW		5411
#define CMD_TRIG_CLR_RTSTATUS	5421
#define CMD_TRIG_LIST_MACROS	5422
#define CMD_TRIG_EXEC_SUSPEND	5423
#define CMD_TRIG_PURGE_QUEUE	5424
#define CMD_TRIG_REPORT_NEXT	5431
#define CMD_TRIG_REPORT_LIST	5432
#define CMD_TRIG_REPORT_DELETE	5433
#define CMD_TRIG_REPORT_GET		5434
#define CMD_TRIG_REPORT_MDELETE	5435
#define CMD_TRIG_REPORT_CONFIG	5436
#define CMD_TRIG_REPORT_SUSPEND	5437
#define CMD_TRIG_REPORT_NEXT_SUB	5438

#define BLOCK_HASHMAP			54
#define CMD_HASHMAP_ADD			5441
#define CMD_HASHMAP_DEL			5442
#define CMD_HASHMAP_LIST		5443

#define BLOCK_LOGIC				55

#define BLOCK_EXPRESSION		56
#define CMD_EXPRESSION_SET		5601
#define CMD_EXPRESSION_GET		5602
#define CMD_EXPRESSION_DEL		5603
#define CMD_EXPRESSION_INFO		5604

#define BLOCK_REMTRIGGER		56
#define CMD_REMTRIGGER_PLIST	5621
#define CMD_REMTRIGGER_TLIST	5622
#define CMD_REMTRIGGER_NOTIFY	5623
#define CMD_REMTRIGGER_COMPLETE	5624

#endif /*DW_LOGIC_COMMANDS_H_*/
