#pragma once

#define ASIO_STANDALONE
#define ASIO_DISABLE_IOCP 1
#include "../../asio/asio/include/asio.hpp"
#include<string>
#include "Message.hpp"
using asio::ip::tcp;

class ChatProtocol {
    public:
        ChatProtocol();
        ChatProtocol(int port);
        ChatProtocol(std::string &address, std::string &port);

        Message receiveMsg();
        void sendMsg(std::string &message, u_int32_t msgId);
        bool isConnected();

    private: 
        const int MAX_MSG_LEN = 10240;  //max. length of a chat message
        tcp::socket sock;
        tcp::socket waitForClientToConnect(int port);
        tcp::socket connectToServer(std::string &address, std::string &port);
        void write(asio::mutable_buffer buf);

};
