/* 
    asio can be downloaded from: https://github.com/chriskohlhoff/asio

    compile as g++ main.cpp -o main -I ../asio/asio/include -std=c++11 
    
*/

#define ASIO_STANDALONE
#include "../asio/asio/include/asio.hpp"

#include <ctime>
#include <iostream>
#include <string>

using asio::ip::tcp;

/* Der Kürze halber hier ohne Fehlerbehandlung. Das machen wir im Unternehmen natürlich nicht!!! */
int main() {

    const std::string PORT = "12345";

    try {
        asio::io_context io_context;                /* Kommunikaitonskontext */
        tcp::resolver resolver(io_context);         /* Auflösen von IP-Adresse und Port zu einer System-Resource */

        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", PORT); /* Kommunikationsendpunkt (System-Resource) */

        tcp::socket socket(io_context);             /* socket Objekt erstellen, dass den Kommunikaitonsendpunkt bedient */
        asio::connect(socket, endpoints);           /* socket mit Server berbinden */

        std::string message = "Hello Server!";

        asio::error_code ignored_error;
        asio::write(socket, asio::buffer(message), ignored_error);  /* Daten über Socket senden */

        char buffer[1024];
        size_t len = socket.read_some(asio::buffer(buffer), ignored_error); /* Daten aus dem Socket lesen */
        std::cout << buffer << std::endl;

        socket.close();                             /* verbindung beenden */

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}