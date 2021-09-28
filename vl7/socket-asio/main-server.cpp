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

    const int PORT = 12345;

    try {
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), PORT));

        tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::string message = "Hello Client!";

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