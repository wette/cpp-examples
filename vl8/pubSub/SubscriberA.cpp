#include "SubscriberA.hpp"
#include "Message.hpp"
#include<iostream>

void SubscriberA::process(Message &m){
    std::cout << "Subscriber " << name << " from Class SubscriberA processing msg " << m.getContent() << " with msgID " << m.getID() << std::endl;
}
SubscriberA::SubscriberA(std::string n){
    name = n;
}