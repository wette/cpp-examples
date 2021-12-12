#include "SubscriberB.hpp"
#include "Message.hpp"
#include<iostream>

void SubscriberB::process(Message &m){
    std::cout << "Subscriber " << name << " from Class SubscriberB processing msg " << m.getContent() << " with msgID " << m.getID() << std::endl;
}
SubscriberB::SubscriberB(std::string n){
    name = n;
}