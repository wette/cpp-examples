#pragma once
#include "ChatProtocol.hpp"
#include<string>

class Chat {
    private:
        ChatProtocol protocol;
        void empfangenUndAusgeben();
        void tastaturLesenUndVersenden();
    public:
        /* Konstruktor für den Server */
        Chat(int port): protocol{ChatProtocol(port)}{};

        /* Konstruktor für den Client */
        Chat(std::string &address, std::string &port): protocol{ChatProtocol(address, port)}{};

        void start();
};