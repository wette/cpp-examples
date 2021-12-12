#include "SubscriberC.hpp"
#include "Message.hpp"
#include<iostream>

void SubscriberC::process(Message &m){
    std::cout << "Subscriber " << name << " from Class SubscriberC processing msg " << m.getContent() << " with msgID " << m.getID() << std::endl;
}
SubscriberC::SubscriberC(std::string n){
    name = n;
}