#include "Publisher.hpp"
#include "SubscriberIntf.hpp"
void Publisher::subscribe( int msgId, const std::shared_ptr<SubscriberIntf>& sub ){
    std::weak_ptr<SubscriberIntf> wp = sub;
    subscribers[msgId].push_back(wp);
}

void Publisher::newMessage(Message m){
    if(subscribers.find(m.getID()) != subscribers.end()) {
        for(auto wp : subscribers[m.getID()]){
            if(auto s = wp.lock()) {
                s->process(m);
            }
        }
    }
}
