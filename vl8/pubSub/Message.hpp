#pragma once
#include<string>
class Message{
    public:
        Message(int id, std::string s);
        int getID();
        std::string getContent();
    private:
        int msgId;
        std::string content;
};