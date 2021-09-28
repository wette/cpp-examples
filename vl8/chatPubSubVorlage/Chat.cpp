#include "Chat.hpp"
#include "ChatProtocol.hpp"
#include "Message.hpp"
#include<iostream>
#include <thread>
#include<exception>
#include <sstream>

/* creates a thread and starts the Chat by reading from keyboard and listening for new messages */
void Chat::start() {
    std::thread t( &Chat::tastaturLesenUndVersenden, this );

    empfangenUndAusgeben();

    t.join();
}

void Chat::empfangenUndAusgeben() {
    while(protocol.isConnected()){
        try {
            Message msg = protocol.receiveMsg();
            std::cout << "Received msg of type " << msg.msgId << ": " << msg.message << std::endl;
        } catch(std::string e) {
            std::cout << e << std::endl;
            return;
        }
    }
}
void Chat::tastaturLesenUndVersenden() {
    while(protocol.isConnected()){
        try{
            std::string msg;
            std::string msgId_str;
            std::getline(std::cin, msgId_str);
            std::getline(std::cin, msg);

            u_int32_t msgId;
            msgId = std::stol(msgId_str);   //convert std::string to int
            protocol.sendMsg(msg, msgId);
        } catch(std::string e) {
            std::cout << e << std::endl;
            return;
        } catch(...){
            std::cout << "You may have entered the wrong parameters. MsgId\\nMessage\\n is the correct format." << std::endl;
        }
    }
}