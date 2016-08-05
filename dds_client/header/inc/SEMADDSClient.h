/* 
 * File name : SEMADDSClient
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __SEMADDSCLIENT_H__
#define __SEMADDSCLIENT_H__

#include "dllexport.h"

#include "boost/function.hpp"
namespace SEMADDS {
	class libSemaDDS_EXPORT SEMADDSClient
	{
	public:
		typedef boost::function< void(int, void *)> CallBack;
		SEMADDSClient();
		virtual ~SEMADDSClient();
		bool Setup(CallBack callbak);
		bool publishMessage(int id , const char *);
	private:
		bool _stopped();
		void _subscriber();
		bool _thread_ready;
		bool _stop;
		CallBack _callbak;
	};
};
#endif
