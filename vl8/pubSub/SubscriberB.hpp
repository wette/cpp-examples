#pragma once
#include "SubscriberIntf.hpp"

class SubscriberB : public SubscriberIntf{
    public:
        void process(Message &m);
        SubscriberB(std::string n);
    private:
        std::string name;
};