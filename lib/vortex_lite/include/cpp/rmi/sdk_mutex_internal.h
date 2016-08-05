#ifndef SDK_MUTEX_INTERNAL_HPP_
#define SDK_MUTEX_INTERNAL_HPP_

#ifndef OS_TIME_H
#ifdef LITE
#include "dds/os/os.h"
typedef struct os_time {
    /** Seconds since the Unix epoch; 1-jan-1970 00:00:00 (UTC) */
#ifdef _WIN32
    INT_PTR tv_sec;
#else
    int tv_sec;
#endif
    /** Number of nanoseconds since the Unix epoch, modulo 10^9. */
    int32_t tv_nsec;
} os_time;
#else
#include "os_time.h"
#endif
#endif

// For Windows build.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#include "WindowsBuild.h"
#else
#define DDS_SERVICE_API
#endif

namespace org
{
  namespace opensplice
  {
    namespace DDS_RMI
    {
      typedef os_time Time;

      class DDS_SERVICE_API SDKMutex
      {
       public:

        SDKMutex() {};

        virtual ~SDKMutex() {};
        virtual int initialize() = 0;
        virtual int lock() = 0;
        virtual int unlock() = 0;
      };


      class DDS_SERVICE_API SDKCondition
      {
       public:

        SDKCondition() {};
        virtual ~SDKCondition() {};
        virtual int destroy() = 0;
        virtual int signal() = 0;
        virtual int broadcast() = 0;
        virtual void wait(SDKMutex & mutex) = 0;
        virtual bool timedWait(SDKMutex & mutex, Time & time) = 0;
      };

      class SDKMutexFactory {
       public:
        static SDKMutex *createSDKMutex();
      };

      class SDKConditionFactory {
       public:
        static SDKCondition *createSDKCondition(SDKMutex &mutex);
      };
    }
  }
}


#endif
