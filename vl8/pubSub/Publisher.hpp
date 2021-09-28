#pragma once
#include "SubscriberIntf.hpp"
#include<vector>
#include<unordered_map>

class Publisher{
    private:
        /*eine Map von Vektoren. Map mapped msgID auf einen Vektor. In dem Vektor stehen alle Subscriber der msgID*/
        std::unordered_map<int, std::vector< std::weak_ptr<SubscriberIntf> > > subscribers; 
    public:
        void subscribe( int msgID, const std::shared_ptr<SubscriberIntf>& sub );
        void newMessage(Message m);
};