/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2016 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef ORG_OPENSPLICE_TOPIC_TYPE_HASH_HPP_
#define ORG_OPENSPLICE_TOPIC_TYPE_HASH_HPP_

namespace org { namespace opensplice { namespace topic {

class TypeHash {
public:
    TypeHash() :
        msb_(0), lsb_(0) {}

    TypeHash(uint64_t msb, uint64_t lsb) :
        msb_(msb), lsb_(lsb) {}

    uint64_t msb() {
        return msb_;
    }

    void msb(uint64_t msb) {
        msb_ = msb;
    }

    uint64_t lsb() {
        return lsb_;
    }

    void lsb(uint64_t lsb) {
        lsb_ = lsb;
    }

    bool operator ==(const TypeHash& other) const
    {
        return other.msb_ == msb_ && other.lsb_ == lsb_;
    }

private:
    uint64_t msb_;
    uint64_t lsb_;
};

}}}

#endif /* ORG_OPENSPLICE_TOPIC_TYPE_HASH_HPP_ */
