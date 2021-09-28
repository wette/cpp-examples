#include<string>
#include "Message.hpp"

Message::Message(int id, std::string s) {
    msgId = id;
    content = s;
}
int Message::getID() { 
    return msgId; 
}
std::string Message::getContent() { 
    return content; 
};