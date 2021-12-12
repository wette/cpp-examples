#include "Publisher.hpp"
#include<memory>
#include<iostream>
#include "SubscriberIntf.hpp"
#include "SubscriberA.hpp"
#include "SubscriberB.hpp"
#include "SubscriberC.hpp"
int main() {
    Publisher pub;

    std::shared_ptr<SubscriberA> s1 = std::make_shared<SubscriberA>("s1");
    std::shared_ptr<SubscriberB> s2 = std::make_shared<SubscriberB>("s2");
    std::shared_ptr<SubscriberC> s3 = std::make_shared<SubscriberC>("s3");

    /* s1 subscribes to messages of type 1 and 2 */
    pub.subscribe(1, s1);
    pub.subscribe(2, s1);

    /* s2 subscribes to messages of type 2 */
    pub.subscribe(2, s2);

    /* s3 subscribes to messages of type 2 */
    pub.subscribe(3, s3);

    /* add new messages to the system. --> they will be processed by the subscribers automatically! */
    std::cout << "------ adding new message with ID 1 ------" << std::endl;
    pub.newMessage( Message(1, "test1") );
    std::cout << "------ adding new message with ID 2 ------" << std::endl;
    pub.newMessage( Message(2, "test2") );
    std::cout << "------ adding new message with ID 1 ------" << std::endl;
    pub.newMessage( Message(1, "test3") );
    std::cout << "------ adding new message with ID 3 ------" << std::endl;
    pub.newMessage( Message(3, "test4") );


    return 0;
}