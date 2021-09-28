#include "SubscriberExample.hpp"
#include "Message.hpp"
#include<iostream>

void SubscriberExample::process(Message &m){
    std::cout << "Subscriber " << name << " processing msg " << m.getContent() << std::endl;
}
SubscriberExample::SubscriberExample(std::string n){
    name = n;
}