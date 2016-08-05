/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef LITE_TOPIC_BUILTIN_TOPIC_KEY_DELEGATE_HPP_
#define LITE_TOPIC_BUILTIN_TOPIC_KEY_DELEGATE_HPP_

namespace org
{
namespace opensplice
{
namespace topic
{

class BuiltinTopicKeyDelegate
{
public:
    typedef uint32_t VALUE_T;
public:
    BuiltinTopicKeyDelegate() { }
    BuiltinTopicKeyDelegate(int32_t v[])
    {
        key_[0] = v[0];
        key_[1] = v[1];
        key_[2] = v[2];
    }
public:
    const int32_t* value() const
    {
        return key_;
    }

    void value(int32_t v[])
    {
        key_[0] = v[0];
        key_[1] = v[1];
        key_[2] = v[2];
    }
#if 0
    void value(const v_builtinTopicKey& key)
    {
        key_[0] = key.systemId;
        key_[1] = key.localId;
        key_[2] = key.serial;
    }
#endif
    bool operator ==(const BuiltinTopicKeyDelegate& other) const
    {
        return other.key_[0] == key_[0]
                 && other.key_[1] == key_[1]
                 && other.key_[2] == key_[2];
    }

private:
    int32_t key_[3];
};

}
}
}

#endif /* LITE_TOPIC_BUILTIN_TOPIC_KEY_DELEGATE_HPP_ */
