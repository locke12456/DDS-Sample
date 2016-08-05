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
 * @file
 *
 * @brief Templates for the server side generated code.
 *
 * @author Bernard MAUDRY
 *
 *
 * Module   : RMI
 * Class   : many
 *
 *
 */
#include <iostream>
#include "dds_service_sdk.h"

#define DIFFUSION_RECEIVER_CODE(scope,interface,operation) \
  org::opensplice::DDS_RMI::ReceiverCode<interface##Interface, \
  ::DDS_RMI::scope::interface::operation##_request, \
  ::DDS_RMI::scope::interface::operation##_requestSeq, \
  ::DDS_RMI::scope::interface::operation##_requestDataReader, \
  ::DDS_RMI::scope::interface::operation##_requestDataReader_var>::handleDiffusion \
     (_intf, "::" #scope "::" #interface "::" #operation, _op_##operation, interface##Interface_##operation##_call_, interface##Interface_##operation##_dispose_)

#define REQUEST_SERVER_CODE(scope,interface,operation) \
  org::opensplice::DDS_RMI::ServerCode<interface##Interface, \
  ::DDS_RMI::scope::interface::operation##_request, \
  ::DDS_RMI::scope::interface::operation##_requestSeq, \
  ::DDS_RMI::scope::interface::operation##_requestDataReader, \
  ::DDS_RMI::scope::interface::operation##_requestDataReader_var, \
  ::DDS_RMI::scope::interface::operation##_reply, \
  ::DDS_RMI::scope::interface::operation##_replyDataWriter, \
  ::DDS_RMI::scope::interface::operation##_replyDataWriter_var>::handleRequest \
     (_intf, "::" #scope "::" #interface "::" #operation, _op_##operation, interface##Interface_##operation##_call_)

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {
      template<class Interface, class Request, class RequestSeq, class Reader,
          class Reader_var, class Reply, class Writer, class Writer_var>
        class ServerCode
        {
        public:
          typedef void
          (*ImplCall)(Interface* _intf, Request& in, Reply& out);

          static void
          handleRequest(Interface* _intf, const char * method_name,
              int op_code, ImplCall Call)
          {
            // Declare in topic for the method
            RequestSeq _inSeq;
            DDS::SampleInfoSeq _infoSeq;

            // Receive the request topic
            Reader_var _dr = Reader::_narrow(_intf->getRequestReader(op_code));

            // Wait reply at max timeout and throw exception in case of timeout expired
#ifndef LITE
            DDS::ReturnCode_t status = _dr->take(_inSeq, _infoSeq,
                DDS::LENGTH_UNLIMITED, DDS::ANY_SAMPLE_STATE,
                DDS::ANY_VIEW_STATE, DDS::ANY_INSTANCE_STATE);
#else
            DDS::ReturnCode_t status = _dr->take(_inSeq, _infoSeq,
                1, DDS::ANY_SAMPLE_STATE,
                DDS::ANY_VIEW_STATE, DDS::ANY_INSTANCE_STATE);
#endif
            if (status != DDS::RETCODE_OK && status != DDS::RETCODE_NO_DATA)
              {
                // If status not OK throw Receive_Exception (todo)
                std::cout << "Failed to take requests for method " << method_name
                    << " status= " << status << " seq length= "
                    << _inSeq.length() << std::endl;
              }

            if (_inSeq.length() < 1)
              {
                // If no sample retrieved throw Receive_Exception (todo)
                //std::cout << "seq length nul for method " << method_name << std::endl;
                status = _dr->return_loan(_inSeq, _infoSeq);
                return;
              }

            // loop on valid samples
            for (unsigned int each_sample = 0; each_sample < _inSeq.length(); each_sample++)
              {
                // if this sample is not for us , then skip it
                if (!(_infoSeq[each_sample].valid_data) ||
                        (!_intf->isMyIdent(_inSeq[each_sample].req_info.service_id)))
                  {
                    continue;
                  }

                // Declare out topic for the method
                Reply _out;
                // Fill the header
                _out.req_info = _inSeq[each_sample].req_info;
                Writer_var _dw = Writer::_narrow(_intf->getReplyWriter(op_code));

                if(_infoSeq[each_sample].instance_state == DDS::NOT_ALIVE_DISPOSED_INSTANCE_STATE)
                  {
                    // disposing and unregistering the reply instance
                    status = _dw->dispose(_out, DDS::HANDLE_NIL);
                    Sync_Print::checkStatus(status,
                        (std::string("Reply disposal of method") + method_name).c_str());
                    status = _dw->unregister_instance(_out, DDS::HANDLE_NIL);
                    Sync_Print::checkStatus(status,
                        (std::string("Reply unregistering of method") + method_name).c_str());
                  }
                else
                  {
                    // Call the actual method
                    Call(_intf, _inSeq[each_sample], _out);
                    // Publish the reply
                    status = _dw->write(_out, DDS::HANDLE_NIL);
                    Sync_Print::checkStatus(status,
                        (std::string("Sending the reply of method") + method_name).c_str());
                  }
              }

            // Memory management
            status = _dr->return_loan(_inSeq, _infoSeq);
            Sync_Print::checkStatus(status,
                    (std::string("return_loan of method ") + method_name).c_str());
          }

        };

      template<class Interface, class Request, class RequestSeq, class Reader,
          class Reader_var>
        class ReceiverCode
        {
        public:
          typedef void
          (*ImplCall)(Interface* _intf, Request& in);

          static void
          handleDiffusion(Interface* _intf, const char * method_name,
              int op_code, ImplCall Call, ImplCall Dispose)
          {
            // Declare in topic for the method
            RequestSeq _inSeq;
            DDS::SampleInfoSeq _infoSeq;
            DDS::ReturnCode_t status = DDS::RETCODE_OK;

            // Receive the request topic
            Reader_var _dr = Reader::_narrow(_intf->getRequestReader(op_code));

            DDS::QueryCondition_var Filter = _intf->getFilter(op_code);
            if (NULL != Filter.in())
              {
                // Receive the filtered samples
#ifndef LITE
                status = _dr->take_w_condition(_inSeq, _infoSeq,
                    DDS::LENGTH_UNLIMITED, Filter.in());
#else
                status = _dr->take_w_condition(_inSeq, _infoSeq,
                    1, Filter.in());
#endif
              }
            else
              {
                // Wait request
#ifndef LITE
                status = _dr->take(_inSeq, _infoSeq, DDS::LENGTH_UNLIMITED,
                    DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
                    DDS::ANY_INSTANCE_STATE);
#else
                status = _dr->take(_inSeq, _infoSeq, 1,
                    DDS::ANY_SAMPLE_STATE, DDS::ANY_VIEW_STATE,
                    DDS::ANY_INSTANCE_STATE);
#endif
              }

            if (status != DDS::RETCODE_OK && status != DDS::RETCODE_NO_DATA)
              {
                std::cout << "Failed to take requests of method " << method_name
                    << " status= " << status << " seq length= "
                    << _inSeq.length() << std::endl;
              }

            if (_inSeq.length() < 1)
              {
                status = _dr->return_loan(_inSeq, _infoSeq);
                Sync_Print::checkStatus(status,
                    (std::string("return_loan of method ") + method_name).c_str());
                return;
              }

            // loop on valid samples
            for (unsigned int each_sample = 0; each_sample < _inSeq.length(); each_sample++)
              {

                if (DDS::NOT_ALIVE_DISPOSED_INSTANCE_STATE
                    == _infoSeq[each_sample].instance_state)
                  {
                    Dispose(_intf, _inSeq[each_sample]);
                    continue;
                  }

                if (!_infoSeq[each_sample].valid_data)
                  {
                    continue;
                  }
                // Call the actual method
                Call(_intf, _inSeq[each_sample]);
              }

            // Memory management
            status = _dr->return_loan(_inSeq, _infoSeq);
            Sync_Print::checkStatus(status,
                     (std::string("return_loan of method ") + method_name).c_str());
          }
        };

    }
  }
}
