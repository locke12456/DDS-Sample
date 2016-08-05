/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

/**
 * @brief This class provides the internal mechanisms needed to set up the
 * client part of the remote server. The abstract methods should be implemented
 * by the generated code.
 */

#ifndef SDK_CINTERFACEPROXYIMPL_HPP_
#define SDK_CINTERFACEPROXYIMPL_HPP_

// For Windows build.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#include "WindowsBuild.h"
#else
#define DDS_SERVICE_API
#endif

#include "sdk_mutex.h"
#include "sdk_cruntimeimpl.h"



namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {
      /**
       * @brief This class provides the internal mechanisms needed to set up the
       *        client part of the remote server. The abstract methods should be
       *        implemented by the generated code.
       */
      class DDS_SERVICE_API CInterfaceProxyImpl : public CInterfaceProxy
      {
      public:

        /**
         * @brief Default constructor
         */
        CInterfaceProxyImpl() :
          m_bDiffusion(false)
        {
        }

        /**
         * @brief Constructor setting the diffusion mode
         */
        CInterfaceProxyImpl(bool diffusion);

        /**
         * @brief Destructor
         */
        virtual
        ~CInterfaceProxyImpl();

        virtual bool
        isDiffusion()
        {
          return m_bDiffusion;
        }

        /**
         * \internal
         * @brief Topic QoS configuration which is implemented by the derived class
         * generated by the code generator
         * \endinternal
         */
        virtual void
        setTopicQoS(DDS::TopicQos& qos, int opIndex, int mode) = 0;

        /**
         * \internal
         * @brief Operation infos getter which is implemented by the derived class
         * generated by the code generator
         * \endinternal
         */
        virtual OperationInfo *
        getInfos() = 0;

        /**
         * \internal
         * @brief Number of operations getter which is implemented by the derived class
         * generated by the code generator
         * \endinternal
         */
        virtual int
        getOperationNumber() = 0;

        /**
         * \internal
         * @brief creates and registers the request/reply topic instances
         * \endinternal
         */
        virtual void
        setup_instances() = 0;

        virtual void
        setTimeout(unsigned int millis)
        {
          m_Timeout = millis;
        }

        virtual unsigned int
        getTimeout()
        {
          return m_Timeout;
        }

        /**
         * \internal
         * @brief To get the client identification for this interface proxy
         * \endinternal
         */
        virtual void
        fillIdentification(::DDS_RMI::Client_Identification& client_id);

        /**
         * \internal
         * @brief To wait for the reply for the given operation index in asynchronous mode
         * \endinternal
         */
        virtual void
        asyncWait(int opIndex, ::DDS_RMI::Request_Header& header,
            CAsyncReplyHandler* handler);

        /**
         * @brief Gets the Publisher of this interface proxy
         */
        virtual DDS::Publisher_var
        getPublisher()
        {
          return m_Publisher;
        }

        /**
         * @brief Gets the Subscriber of this interface proxy
         */
        virtual DDS::Subscriber_var
        getSubscriber()
        {
          return m_Subscriber;
        }

        /**
         * \internal
         * @brief Gets the DataWriter of the requests of this interface proxy
         * for the given operation index
         * \endinternal
         */
        virtual DDS::DataWriter_var
        getRequestWriter(int opIndex)
        {
          return m_RequestWriter[opIndex];
        }

        /**
         * \internal
         * @brief Gets the DataReader of the replies of this interface proxy
         * for the given operation index
         * \endinternal
         */
        virtual DDS::DataReader_var
        getReplyReader(int opIndex)
        {
          return m_ReplyReader[opIndex];
        }

        /**
         * \internal
         * @brief To setup the different DDS entities needed by this interface
         * \endinternal
         */
        virtual bool
        setup(::DDS_RMI::Identification ident, std::string proxy_name,
            int proxy_instance);

        virtual ::DDS_RMI::Identification
        getIdent()
        {
          return m_Ident;
        }

        /**
         * \internal
         * @brief checks if the given reply is for the current client proxy
         * \endinternal
         */
        virtual bool
        isMyReply(::DDS_RMI::Client_Identification & header);

        /**
         * \internal
         * @brief Return the identification of this interface
         * \endinternal
         */
        virtual ::DDS_RMI::Client_Identification
        getClientIdent()
        {
          return m_Client;
        }

        /**
         * \internal
         * @brief Set the identification of this interface
         * \endinternal
         */
        virtual void
        setIdent(::DDS_RMI::Identification ident)
        {
          m_Ident = ident;
        }

        /**
         * @brief returns true if the proxy has run with MT configuration option
         */
        bool
        isMultiThreaded();

        /**
         * @brief To indicate the partition to use for (1) requests and (2) replies
         */
        virtual void
        setPartition(std::string partition[2]);

      private:
        Mutex m_Mutex;

        unsigned int m_Timeout;
        ::DDS_RMI::Identification m_Ident;
        ::DDS_RMI::Client_Identification m_Client;
        std::string * m_Partition;
        DDS::Publisher_var m_Publisher;
        DDS::Subscriber_var m_Subscriber;
        DDS::DataWriter_var * m_RequestWriter;
        DDS::DataReader_var * m_ReplyReader;
        bool m_bDiffusion;

        /**
         * \internal
         * @brief publishes the proxy identity to the server so that he can create the client partition according to the client identity
         * \endinternal
         */
        //virtual bool connectToService();

      protected:

        DDS::InstanceHandle_t * m_ReqInstancesHandles;

        /**
         * \internal
         * @brief Identify this proxy
         * No proxy operation can be called before this setting
         * \endinternal
         */
        virtual void
        setIdentification(std::string name, int instance = 1);

      };
    }

  }
}

#endif /* SDK_CINTERFACEPROXYIMPL_HPP_ */