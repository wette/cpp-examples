/* 
    asio can be downloaded from: https://github.com/chriskohlhoff/asio

    compile as g++ main.cpp -o main -I ../asio/asio/include -std=c++11 
    
*/

#define ASIO_STANDALONE
#define ASIO_DISABLE_IOCP 1
#include "asio.hpp"

#include <ctime>
#include <iostream>
#include <string>

using asio::ip::tcp;

/* Der Kürze halber hier mit minimaler Fehlerbehandlung. Das machen wir im Unternehmen natürlich nicht!!! */
int main() {

    const std::string PORT = "12345";

    try {
        asio::io_context io_context;                /* Kommunikaitonskontext */
        tcp::resolver resolver(io_context);         /* Auflösen von IP-Adresse und Port zu einer System-Resource */

        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", PORT); /* Kommunikationsendpunkt (System-Resource) */

        tcp::socket socket(io_context);             /* socket Objekt erstellen, dass den Kommunikaitonsendpunkt bedient */
        asio::connect(socket, endpoints);           /* socket mit Server berbinden */

        std::string message = "Hello Server!";

        asio::error_code error;
        asio::write(socket, asio::buffer(message), error);  /* Daten über Socket senden */
        if(error) {
            throw new std::runtime_error(error.message());
        }

        const int buflen = 1024;
        char buffer[buflen];
        for(int i = 0; i < buflen; i++) {
            buffer[i] = 0;
        }
        size_t len = socket.read_some(asio::buffer(buffer), error); /* Daten aus dem Socket lesen */
        if(error) {
            throw new std::runtime_error(error.message());
        }


        std::cout << buffer << std::endl;

        socket.close();                             /* verbindung beenden */

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}
