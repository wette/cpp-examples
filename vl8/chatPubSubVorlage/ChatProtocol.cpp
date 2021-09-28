#include "ChatProtocol.hpp"
#include "Message.hpp"
#include<iostream>

ChatProtocol::ChatProtocol(int port) : sock{waitForClientToConnect(port)} {

}

ChatProtocol::ChatProtocol(std::string &address, std::string &port) : sock{connectToServer(address, port)} {
    
}

/* blocks until a client connects */
tcp::socket ChatProtocol::waitForClientToConnect(int port) {
    asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

    tcp::socket s = tcp::socket(io_context);
    acceptor.accept(s);

    std::cout << "Client connected!" << std::endl;

    return s;
}

/* blocks until connected to client */
tcp::socket ChatProtocol::connectToServer(std::string &address, std::string &port){
    asio::io_context io_context;
    tcp::resolver resolver(io_context);

    tcp::resolver::results_type endpoints = resolver.resolve(address, port);

    tcp::socket s = tcp::socket(io_context);
    asio::connect(s, endpoints);

    std::cout << "Connected to Server!" << std::endl;

    return s;
}

/* blocks until new message is received */
Message ChatProtocol::receiveMsg(){
    u_int32_t msg_len;
    u_int32_t msg_id;

    /* read exactly 4 Bytes */
    asio::read(sock, asio::buffer((void*) &msg_len, 4));
    msg_len = ntohl(msg_len);

    /* read exactly 4 Bytes */
    asio::read(sock, asio::buffer((void*) &msg_id, 4));
    msg_id = ntohl(msg_id);

    /* check msg len*/
    if(msg_len > MAX_MSG_LEN){
        std::string err = "Error: msg received was too long:" + std::to_string((int)msg_len);
        throw err;
    }
    /* read exactly msg_len Bytes */
    char buf_msg[msg_len+1];
    for(int i = 0; i < msg_len+1; i++) {
        buf_msg[i] = 0;
    }
    asio::read(sock, asio::buffer(buf_msg, msg_len));

    return Message(std::string(buf_msg), msg_id);
}

/* is the socket currently connected (ready to receive messages) */
bool ChatProtocol::isConnected() {
    return sock.is_open();
}

void ChatProtocol::write(asio::mutable_buffer buf){
    asio::error_code error;
    asio::write(sock, buf, error);
    if(error.value() != 0) {
        throw std::string("Error writing to socket");
    }
}

void ChatProtocol::sendMsg(std::string &message, u_int32_t msgId){
    u_int32_t msg_len = htonl(message.length());
    u_int32_t msg_id = htonl(msgId);

    write(asio::buffer((char*)&msg_len, 4));
    write(asio::buffer((char*)&msg_id, 4));
    write(asio::buffer(message));
}