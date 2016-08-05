/*
 * BuiltinTopicTypes.hpp
 *
 *  Created on: Oct 23, 2012
 *      Author: angelo
 */

#ifndef OMG_DDS_CORE_DELEGATE_BUILTIN_TOPIC_TYPES_HPP_
#define OMG_DDS_CORE_DELEGATE_BUILTIN_TOPIC_TYPES_HPP_

#if defined (OMG_DDS_X_TYPES_BUILTIN_TOPIC_TYPES_SUPPORT)
namespace dds {
  namespace core {
    namespace detail {

      class BytesTopicType { };
      class StringTopicType { };
      class KeyedBytesTopicType { };
      class KeyedStringTopicType { };
    }
  }
}
#endif

#endif /* OMG_DDS_CORE_DELEGATE_BUILTIN_TOPIC_TYPES_HPP_ */
