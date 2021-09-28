#pragma once
#include "SubscriberIntf.hpp"

class SubscriberExample : public SubscriberIntf{
    public:
        void process(Message &m);
        SubscriberExample(std::string n);
    private:
        std::string name;
};