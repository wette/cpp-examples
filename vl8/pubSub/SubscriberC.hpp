#pragma once
#include "SubscriberIntf.hpp"

class SubscriberC : public SubscriberIntf{
    public:
        void process(Message &m);
        SubscriberC(std::string n);
    private:
        std::string name;
};