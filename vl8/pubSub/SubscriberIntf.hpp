#pragma once
#include "Message.hpp"
class SubscriberIntf {
    public:
        virtual void process(Message &m) = 0;
};