/*
 * This file contains the implementation for the 'SEMADDSPublisher' executable.
 *
 ***/
#include <string>
#include <sstream>
#include <iostream>
#include "DDSEntityManager.h"
#include "SEMADDSClient.h"
#include "ccpp_semadds.h"
#include "vortex_os.h"

#include "DDSManager.h"
#include "DDSMessageWriter.h"
#include "json/json.h"
#include "test_main.h"

using namespace DDS;
using namespace SEMADDS;
using namespace SEMADDS_Types;

#include "boost/lexical_cast.hpp"
#include "boost/bind.hpp"
/* entry point exported and demangled so symbol can be found in shared library */
extern "C"
{
  OS_API_EXPORT
  int SEMADDSPublisher(int argc, char *argv[]);
}
class callbak {
public:
	SEMADDSClient::CallBack calbak;
	callbak() {

		calbak = boost::bind(&callbak::call, this, _1, _2);
	
	};
	~callbak() {};
	void call(int id, void * msg)
	{
		std::string json((char *)msg);
		std::string deviceidentifier;
		std::string sensoridentifier;
		long int	data;
		std::string datatype;
		long int	protocolid;
		std::string datetime;
		Json::Reader reader;
		Json::Value property;
		reader.parse(json, property);
		deviceidentifier = property["deviceidentifier"].asString();
		sensoridentifier = property["sensoridentifier"].asString();
		data = boost::lexical_cast<long int>(property["data"].asString());
		//datatype = property["datatype"].asString();
		//protocolid = (long int)property["protocolid"].asInt64();
		//datetime = property["datetime"].asString();

		std::cout << deviceidentifier << std::endl;
		std::cout << sensoridentifier << std::endl;
		std::cout << data << std::endl;
		std::cout << datatype << std::endl;
		std::cout << protocolid << std::endl;
		std::cout << datetime << std::endl;
		return;
	}
};
 
int SEMADDSPublisher(int argc, char *argv[])
{
	os_time delay_1s = { 1, 0 };
	SEMADDSClient client;
	callbak call;
	SEMADDSClient::CallBack calbak = call.calbak;
	client.Setup(calbak);
	for (int i = 0; i < 100; i++) {
		char msg[1024];
		sprintf(msg, "{ \"deviceidentifier\" : \"%s\", \"sensoridentifier\" : \"%s\", \"data\" : \"%d\", \"datatype\" : \"%s\", \"protocolid\" : \"%s\", \"datetime\" : \"%s\" }", "00E04C341AF6", "16_MODBUS_15", 0, "0x00", "6", "2016-03-12 12:39:23");

		client.publishMessage(  i , msg);
		os_nanoSleep(delay_1s);
	}
	return 0;
}
int OSPL_MAIN (int argc, char *argv[])
{
  return SEMADDSPublisher (argc, argv);
}
