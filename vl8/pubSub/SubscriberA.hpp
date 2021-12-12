#pragma once
#include "SubscriberIntf.hpp"

class SubscriberA : public SubscriberIntf{
    public:
        void process(Message &m);
        SubscriberA(std::string n);
    private:
        std::string name;
};