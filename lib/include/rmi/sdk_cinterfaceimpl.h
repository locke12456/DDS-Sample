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


#ifndef SDK_CINTERFACEIMPL_HPP_
#define SDK_CINTERFACEIMPL_HPP_

// For Windows build.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#include "WindowsBuild.h"
#else
#define DDS_SERVICE_API
#endif

#include "sdk_cruntimeimpl.h"
#include "ccpp_dds_dcps.h"
#include "sdk_mutex.h"

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {

      /**
       * @brief This class provides the internal mechanisms used to set up the RMI
       *        server. the abstract methods should be implemented by generated code.
       */
      class DDS_SERVICE_API CInterfaceImpl : public virtual CInterface
      {
      public:
        /**
         * @brief Constructor
         */
        CInterfaceImpl(bool diffusion = false);

        /**
         * @brief Destructor
         */
        virtual
        ~CInterfaceImpl();

        virtual bool
        isDiffusion()
        {
          return m_bDiffusion;
        }

        /**
         * \internal
         * @brief To indicate the instance number of this interface
         * \endinternal
         */
        virtual void
        setInstanceNumber(int num)
        {
          m_Ident.server_instance = num;
        }

        /**
         * \internal
         * @brief To setup the different DDS entities needed by this interface
         * \endinternal
         */
        virtual void
        setupDDSEntities();

        /**
         * \internal
         * @brief To remove the different DDS entities already created.
         * \endinternal
         */
        virtual void
        removeDDSEntities();

        virtual ::DDS_RMI::Identification
        getIdent()
        {
          return m_Ident;
        }

        /**
         * \internal
         * @brief sets the identification of this interface
         * \endinternal
         */
        virtual void
        setIdent(::DDS_RMI::Identification ident)
        {
          m_Ident.server_class = ident.server_class;
          m_Ident.server_impl = ident.server_impl;
          m_Partition[0] = std::string("RMI.REQ.") + m_Ident.server_impl.in();
          m_Partition[1] = std::string("RMI.REP.") + m_Ident.server_impl.in(); //+ ".*";
          // server_instance is set by setInstanceNumber
        }

        /**
         * \internal
         * @brief To check if the given ident corresponds to this interface
         * \endinternal
         */
        virtual bool
        isMyIdent(::DDS_RMI::Identification ident);

        /**
         * \internal
         * @brief To suspend an interface
         *
         * After suspending the internal mechanism of the interface,
         * it calls the suspend operation of the interface
         * \endinternal
         */
        virtual void
        doSuspend();

        /**
         * \internal
         * @brief To resume an interface
         *
         * It calls the resume operation of the interface
         * And it resumes the internal mechanism of the interface,
         * \endinternal
         */
        virtual void
        doResume(int millis = -1);

        virtual bool
        isRunning();

        virtual bool
        setFilter(int operation_index, std::string expr, std::vector<
            std::string> params);

        virtual bool
            changeFilterParams(int operation_index,
                std::vector<std::string> params);

        /**
         * \internal
         * @brief Internal call to wait and handle the request
         * \endinternal
         */
        virtual bool
        waitAndHandleRequest();

        /**
         * \internal
         * @brief Request handling which is implemented by the derived class
         * generated by the code generator
         * \endinternal
         */
        virtual void
        handleRequest(int opIndex) = 0;

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
         * @brief Interface class name which is implemented by the derived class
         * generated by the code generator
         */
        virtual const std::string&
        getClass() = 0;

        /**
         * @brief Gets the Publisher of this interface
         */
        virtual DDS::Publisher_var
        getPublisher()
        {
          return m_Publisher;
        }

        /**
         * @brief Gets the Subscriber of this interface
         */
        virtual DDS::Subscriber_var
        getSubscriber()
        {
          return m_Subscriber;
        }

        /**
         * \internal
         * @brief Gets the DataReader of the requests of this interface
         * for the given operation index
         * \endinternal
         */
        virtual DDS::DataReader_var
        getRequestReader(int opIndex)
        {
          return m_RequestReader[opIndex];
        }

        /**
         * \internal
         * @brief Gets the DataWriter of the replies of this interface
         * for the given operation index
         * \endinternal
         */
        virtual DDS::DataWriter_var
        getReplyWriter(int opIndex)
        {
          return m_ReplyWriter[opIndex];
        }

        /**
         * \internal
         * @brief Gets the filter conditions of the replies of this interface
         * for the given operation index
         * \endinternal
         */
        virtual DDS::QueryCondition_var
        getFilter(int opIndex);

        void
        waitForRequests(long millis);

        bool
        getListeningMode();

        virtual void
        setPartition(std::string partition[2]);

      private:
        ::DDS_RMI::Identification m_Ident;
        std::string * m_Partition;
        DDS::Publisher_var m_Publisher;
        DDS::Subscriber_var m_Subscriber;
        DDS::DataReader_var * m_RequestReader;
        DDS::DataWriter_var * m_ReplyWriter;
        DDS::StatusCondition_var * m_StatusCondition;
        DDS::GuardCondition * m_StopWaiting;
        DDS::WaitSet * m_RequestWaitset;
        std::string * Filter_Expr;
        DDS::QueryCondition_var * Filters;
        Mutex m_Mutex;

      protected:
        bool m_bDiffusion;
        bool m_bPaused;
        DDS::StringSeq * Filter_Params;
      };

    }
  }
}

#endif /* SDK_CINTERFACEIMPL_HPP_ */