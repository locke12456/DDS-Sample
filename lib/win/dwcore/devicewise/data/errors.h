//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/errors.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_ERRORS_H_
#define DW_DATA_ERRORS_H_

#define ERR_DATA_NOTINIT		-6001
#define ERR_DATA_BADXML			-6002
#define ERR_DATA_UNKN_TYPE		-6011

#define ERR_DRVR_ALREADYEXISTS	-6101
#define ERR_DRVR_NOTFOUND		-6102
#define ERR_DRVR_NOTINIT		-6103
#define ERR_DRVR_MISSINGFUNCS	-6104
#define ERR_DRVR_NOTIMPLEMENTED	-6105
#define ERR_DRVR_NO_CALLBACK	-6106
#define ERR_DRVR_NO_MODEL_CHG	-6107

#define ERR_DEV_EXISTS			-6201
#define ERR_DEV_NOTFOUND		-6202
#define ERR_DEV_STARTED			-6204
#define ERR_DEV_STOPPED			-6205
#define ERR_DEV_STARTING		-6206
#define ERR_DEV_NOTSTARTED		-6207
#define ERR_DEV_NOTSTOPPED		-6208
#define ERR_DEV_UNEDITABLE		-6209
#define ERR_DEV_UNSTOPPABLE		-6210
#define ERR_DEV_UNDELETABLE		-6211
#define ERR_DEV_NOTLICENSED		-6212
#define ERR_DEV_LICENSELIMIT	-6213
#define ERR_DEV_NOTCREATABLE	-6214

#define ERR_DEV_PROP_NOTFOUND	-6221
#define ERR_DEV_PROP_INVALID	-6222
#define ERR_DEV_SLOT_INVALID	-6223

#define ERR_DEV_INTERNAL		-6231
#define ERR_DEV_COMM			-6232
#define ERR_DEV_TIMEOUT			-6233
#define ERR_DEV_BUSY			-6234
#define ERR_DEV_IO				-6235
#define ERR_DEV_BAD_DATA		-6236
#define ERR_DEV_PROTO			-6237
#define ERR_DEV_BAD_PARMS		-6238
#define ERR_DEV_CONFIGURATION	-6239
#define ERR_DEV_CONFIG_EXISTS	-6240
#define ERR_DEV_CIRCULAR		-6241

#define ERR_DEV_TYPE_EXISTS		-6251
#define ERR_DEV_TYPE_NOTFOUND	-6252
#define ERR_DEV_TYPE_INHIBITED	-6253
#define ERR_IN_BCD_CONVERSION	-6254;

#define ERR_DEV_CMD_NOTFOUND	-6261
#define ERR_DEV_CMD_FAILED		-6262

#define ERR_STRUCT_EXISTS		-6301
#define ERR_STRUCT_NOTFOUND		-6302
#define ERR_STRUCT_MBR_EXISTS	-6303
#define ERR_STRUCT_MBR_NOTFOUND	-6304

#define ERR_VAR_EXISTS			-6401
#define ERR_VAR_NOTFOUND		-6402
#define ERR_VAR_COUNT_MISMATCH	-6403
#define ERR_VAR_DATA_OVERFLOW	-6404
#define ERR_VAR_BAD_TYPE_CONVERSION	-6405
#define ERR_VAR_LENGTH_REQUIRED	-6406
#define ERR_VAR_READ_FAILED		-6407
#define ERR_VAR_DATA_MISMATCH	-6408
#define ERR_VAR_BAD_TYPE		-6409
#define ERR_VAR_BAD_NAME		-6410
#define ERR_VAR_COUNT_OVERFLOW 	-6411
#define ERR_VAR_BAD_TYPE_CAST	-6412
#define ERR_VAR_NOT_HANDLED		-6413
#define ERR_VAR_BLOCK_EMPTY		-6414
#define ERR_VAR_STRING_EMPTY	-6415
#define ERR_VAR_LENGTH_ODD		-6416
#define ERR_VAR_NOT_WRITABLE    -6417
#define ERR_VAR_NOT_READABLE    -6418
#define ERR_VAR_LENGTH_INVALID	-6419
#define ERR_VAR_CREATE_FAILED	-6420
#define ERR_VAR_BITOFS_OVERFLOW	-6421
#define ERR_VAR_INDEX_RANGE		-6422
#define ERR_VAR_BITOFS_MISSING	-6423
#define ERR_VAR_NOT_INITIALED	-6424
#define ERR_VAR_INVALID_VALUE	-6425

#define ERR_MAP_EXISTS			-6501
#define ERR_MAP_NOTFOUND		-6502
#define ERR_MAP_STARTED			-6504
#define ERR_MAP_STOPPED			-6505
#define ERR_MAP_STARTING		-6506
#define ERR_MAP_NOTSTARTED		-6507
#define ERR_MAP_NOTSTOPPED		-6508
#define ERR_MAP_BADEDIT			-6509
#define ERR_MAP_UNLICENSED		-6510
#define ERR_MAP_LOOP_EXISTS		-6511
#define ERR_MAP_SUSPENDED		-6512
#define ERR_MAP_RUNNING			-6513

#define ERR_VARGROUP_NOTFOUND	-6551
#define ERR_VARGROUP_FOUND		-6552
#define ERR_VARGROUP_NOTSTOPPED	-6553
#define ERR_VARGROUP_NOTSTARTED	-6554
#define ERR_VARGROUP_BADEDIT	-6555
#define ERR_VARGROUP_VAR_NOTFOUND	-6556
#define ERR_VARGROUP_VAR_FOUND		-6557

#define ERR_PUBLISHER_UNKNOWN	-6601
#define ERR_PUBLISHER_NOTFOUND	-6602
#define ERR_PUBLISHER_PRIO_NOT_SUPPORTED -6603
#define ERR_PUBLISHER_MISMATCH	-6604
#define ERR_PUBLISHER_SUSPENDED	-6605
#define ERR_PUBLISHER_RUNNING	-6606

#define ERR_PEER_NOT_STARTED	-6701
#define ERR_PEER_DEV_NOTFOUND	-6702

#endif /*DW_DATA_ERRORS_H_*/
