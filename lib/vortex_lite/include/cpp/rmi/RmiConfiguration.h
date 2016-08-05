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

#ifndef RMICONFIGURATION_H_
#define RMICONFIGURATION_H_

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {

      /**
       * @brief Threading model enum values
       */
      enum ThreadingModel
      {
        ST, //SingleThreaded
        MT  //Multithreaded
      };

      enum RequestInstancesManagementStrategy
      {
        instance_per_client,
        instance_per_request // FT-enabled
      };

      /**
       * @brief Holder class for RMI runtime configuration
       */
      class RmiConfiguration
      {
      public:
        RmiConfiguration();
        virtual
        ~RmiConfiguration();

        void
        init(int argc, const char *argv[]);
        void
        reset();

        /**
         * To get the threading model of the client
         * @return 'ST' if single threaded, 'MT' if multithreaded.
         */
        inline ThreadingModel
        getRMIClientThreadingModel()
        {
          return RMIClientThreadingModel;
        }

        /**
         * To get the max time duration (in seconds) a client application may wait to find services
         * @return the timeout duration in seconds
         */
        inline int
        getServiceDiscoveryTimeout()
        {
          return ServiceDiscoveryTimeout;
        }

        /**
         *
         */
        inline bool
        isDurabilityEnabled(){
          return durability;
        }

      private:
        static const int optionsLength = 3;
        static const char * optionsLabels[optionsLength];
        static const char * ST_OPTION;
        static const char * MT_OPTION;
        static const char * YES_OPTION;
        static const char * NO_OPTION;

        void
        validateClientThreadingModel(const char * optionValue);

        void
        validateServiceDiscoveryTimeout (const char * optionValue);

        void
        validateDurabilitySupport(const char * optionValue);

        void
            (org::opensplice::DDS_RMI::RmiConfiguration::* optionsValidators[optionsLength])(
                const char *);

        ThreadingModel RMIClientThreadingModel;
        RequestInstancesManagementStrategy RequestInstancesStrategy; // Not supported yet
        int ServiceDiscoveryTimeout;
        bool durability;

      };

    }
  }
}

#endif /* RMICONFIGURATION_H_ */
