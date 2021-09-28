#pragma once
#include<string>
class Message{
    public:
        Message(std::string s, uint32_t id) :message{s}, msgId{id}{};
        std::string message;
        uint32_t msgId;

};