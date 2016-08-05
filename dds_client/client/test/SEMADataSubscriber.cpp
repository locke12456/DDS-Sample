/*
* This file contains the implementation for the 'SEMADDSSubscriber' executable.
*
***/
#include <string>
#include <sstream>
#include <iostream>
#include "DDSManager.h"
#include "DDSMessageReader.h"
#include "SEMADDSClient.h"
#include "DDSEntityManager.h"
#include "ccpp_semadds.h"
#include "vortex_os.h"

#include "test_main.h"
#include "boost/bind.hpp"
using namespace SEMADDS;
using namespace DDS;
using namespace SEMADDS_Types;

/* entry point exported and demangled so symbol can be found in shared library */
extern "C"
{
	OS_API_EXPORT
		int SEMADDSSubscriber(int argc, char *argv[]);
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
		std::cout << (char *) msg << std::endl;
		return;
	}
};
int SEMADDSSubscriber(int argc, char *argv[]) 
{
	os_time delay_200ms = { 0, 200000000 };
	SEMADDSClient client;
	callbak call;
	SEMADDSClient::CallBack calbak = call.calbak;
	client.Setup(calbak);
	for (int i=0; i < 10000; i++)os_nanoSleep(delay_200ms);
	return 0;
}
int OSPL_MAIN(int argc, char *argv[])
{
	return SEMADDSSubscriber(argc, argv);
}
