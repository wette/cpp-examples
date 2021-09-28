#include "SubscriberExample.hpp"
#include "Publisher.hpp"
#include<memory>
#include "SubscriberIntf.hpp"

int main() {
    Publisher pub;

    std::shared_ptr<SubscriberExample> s1 = std::make_shared<SubscriberExample>("s1");
    std::shared_ptr<SubscriberExample> s2 = std::make_shared<SubscriberExample>("s2");
    std::shared_ptr<SubscriberExample> s3 = std::make_shared<SubscriberExample>("s3");

    pub.subscribe(1, s1);
    pub.subscribe(2, s2);
    pub.subscribe(2, s3);

    Message m1(1, "test1");
    Message m2(2, "test2");

    pub.newMessage(m1);
    pub.newMessage(m2);


    return 0;
}