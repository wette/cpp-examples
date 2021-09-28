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

int main() {

    const std::string PORT = "12345";

    try {
        asio::io_context io_context;
        tcp::resolver resolver(io_context);

        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", PORT);

        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);

        std::string message = "Hello Server!";

        asio::error_code ignored_error;
        asio::write(socket, asio::buffer(message), ignored_error);

        char buffer[1024];
        size_t len = socket.read_some(asio::buffer(buffer), ignored_error);
        std::cout << buffer << std::endl;

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}