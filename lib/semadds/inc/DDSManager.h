/* 
 * File name : DDSManager
 * Author    : Locke Chen
 * E-Mail    : locke12456@gmail.com
 * Language  : C plus plus 
 */
#ifndef __DDSMANAGER_H__
#define __DDSMANAGER_H__
#ifndef NULL
#define NULL 0
#endif
#include "dllexport.h"
#include "IDDSObject.h"

namespace SEMADDS {
	class libSemaDDS_EXPORT DDSManager
	{
	public:
		static DDSManager & getInstance();
		static void Destroy();
		~DDSManager();
		long GetDomain()const;
		
		bool Setup(const char * domain, const char * topic);

		bool SetupSubscriber();

		bool SetupPubilsher();

		IDDSObject * GetParticipant() const;
		IDDSObject * GetRegister() const;
		IDDSObject * GetPublisher() const;
		IDDSObject * GetSubscriber() const ;
		IDDSObject * GetMessageReader() const;
		IDDSObject * GetMessageWriter() const;
		IDDSObject * GetTopicCreator() const;

	private:
		bool Initialize();
		DDSManager();
		static DDSManager * _this;

		long _domain;
		IDDSObject * _dds_participant;
		IDDSObject * _dds_register;
		IDDSObject * _dds_publisher;
		IDDSObject * _dds_subscriber;
		IDDSObject * _dds_message_reader;
		IDDSObject * _dds_message_writer;
		IDDSObject * _dds_topic_creator;

	};
};
#endif
