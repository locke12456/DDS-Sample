//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/publisher.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------


#ifndef DW_DATA_PUBLISHER_H_
#define DW_DATA_PUBLISHER_H_

int publisher_variable_subscribe(DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *var,_driver_publish publish,void *custom,int QoS, void *userctx);
int publisher_variable_unsubscribe(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);

#endif /*PUBLISHER_H_*/
