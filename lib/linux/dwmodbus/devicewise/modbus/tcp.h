//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Modbus Driver
//
//-- Filename: devicewise/modbus/tcp.h
//
//-- $Date: 2011/08/30 15:22:34 $
//-- $Revision: 1.1 $
//-- $Name:  $
//
//----------------------------------------------------------------

#ifndef DW_DEVICEWISE_MODBUS_TCP_H_
#define DW_DEVICEWISE_MODBUS_TCP_H_

#define MODBUS_MAX_WORDS_PER_REQUEST	125
#define MODBUS_MAX_BITS_PER_REQUEST		2000

#define MODBUS_TCP_HEADER_LEN	7

typedef struct {
	unsigned short txn_id;
	unsigned short proto;
	unsigned short length;
	unsigned char  unit_id;
	unsigned char  func;
	unsigned char  data[252];
} MODBUS_TCP_PACKET;

typedef struct {
	unsigned char exception_code;
} MODBUS_ERROR_RSP;

typedef struct {
	unsigned short start_address;
	unsigned short count;
} MODBUS_READ_REQ;

typedef struct {
	unsigned char bytes;
	unsigned char data[0];
} MODBUS_READ_RSP;

typedef struct {
	unsigned short start_address;
	unsigned short count;
	unsigned char bytes;
	unsigned char data[0];
} MODBUS_WRITE_REQ;

typedef struct {
	unsigned short start_address;
	unsigned short count;
} MODBUS_WRITE_RSP;

#endif /*DW_DEVICEWISE_MODBUS_TCP_H_*/
