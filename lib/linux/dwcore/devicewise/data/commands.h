//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/commands.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_COMMANDS_H_
#define DW_DATA_COMMANDS_H_

#define BLOCK_DATA					60
#define BLOCK_DATA1					61
#define BLOCK_DATA2					62
#define BLOCK_DATA3					63
#define BLOCK_DATA4					64
#define BLOCK_DATA5					65
#define BLOCK_DATA6					66
#define BLOCK_DRVR_PASSTHRU			68

#define CMD_DATA_DRVR_ENUM			6001
#define CMD_DATA_PUB_LIST			6002
#define CMD_DATA_DEV_TYPE_ENUM		6021
#define CMD_DATA_DEV_TYPE_LIST		6022

#define CMD_DATA_DEV_ADD			6101
#define CMD_DATA_DEV_EDIT			6102
#define CMD_DATA_DEV_DEL			6103
#define CMD_DATA_DEV_START			6104
#define CMD_DATA_DEV_STOP			6105
#define CMD_DATA_DEV_INFO			6106
#define CMD_DATA_DEV_LIST			6107
#define CMD_DATA_DEV_VALIDATE		6108
#define CMD_DATA_DEV_CLR_STATUS		6109
#define CMD_DATA_DEV_DUMP			6111
#define CMD_DATA_DEV_COPY			6112
#define CMD_DATA_DEV_REFRESH_MODEL	6113

#define CMD_DATA_COMMAND_EXEC		6121

#define CMD_DATA_VAR_INFO			6206
#define CMD_DATA_VAR_READ			6211
#define CMD_DATA_VAR_WRITE			6212
#define CMD_DATA_VAR_READ_ASYNC		6213
#define CMD_DATA_VAR_WRITE_ASYNC	6214
#define CMD_DATA_VAR_SUBSCRIBE		6221
#define CMD_DATA_VAR_UNSUBSCRIBE	6222
#define CMD_DATA_VAR_PUBLISH		6223

#define CMD_DATA_STRUCT_INFO		6306

#define CMD_DATA_PEER_PUBLISH		6401

#define CMD_DATA_MAP_ADD			6501
#define CMD_DATA_MAP_EDIT			6502
#define CMD_DATA_MAP_DEL			6503
#define CMD_DATA_MAP_START			6504
#define CMD_DATA_MAP_STOP			6505
#define CMD_DATA_MAP_INFO			6506
#define CMD_DATA_MAP_LIST			6507
#define CMD_DATA_DEV_CLR_COUNTERS	6509

#define CMD_DATA_VARGROUP_ADD		6601
#define CMD_DATA_VARGROUP_EDIT		6602
#define CMD_DATA_VARGROUP_DEL		6603
#define CMD_DATA_VARGROUP_START		6604
#define CMD_DATA_VARGROUP_STOP		6605
#define CMD_DATA_VARGROUP_INFO		6606
#define CMD_DATA_VARGROUP_LIST		6607
#define CMD_DATA_VARGROUP_LIST_NAME	6608
#define CMD_DATA_VARGROUP_CLR_ERR	6609

#endif /*DW_DATA_COMMANDS_H_*/
