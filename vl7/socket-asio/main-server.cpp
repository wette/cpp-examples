/* 
    asio can be downloaded from: https://github.com/chriskohlhoff/asio

    compile client as g++ main-client.cpp -o client -I ../asio/asio/include -std=c++11 
    compile server as g++ main-server.cpp -o server -I ../asio/asio/include -std=c++11 

    In Windows, you need to add your local path to the downloaded asio directory to the include directory of your C++ program 
    This is a header-only library, so no need to tell the linker anything.
    
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

    const int PORT = 12345;

    try {
        asio::io_context io_context;                                            /* Kommunikaitonskontext */
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), PORT));     /* Aceptor "nimmt den Hörer ab", wenn jemand anruft */

        tcp::socket socket(io_context);
        acceptor.accept(socket);                                                /* Eingehende Verbindung des Clients akzektieren (Hörer abnehmen) */

        std::string message = "Hello Client!";

        asio::error_code error;
        asio::write(socket, asio::buffer(message), error);              /* Daten schreiben */
        if(error) {
            throw new std::runtime_error(error.message());
        }

        const int buflen = 1024;
        char buffer[buflen];
        for(int i = 0; i < buflen; i++) {
            buffer[i] = 0;
        }
        size_t len = socket.read_some(asio::buffer(buffer), error);     /* Daten lesen */
        if(error) {
            throw new std::runtime_error(error.message());
        }
        std::cout << buffer << std::endl;

        socket.close();                                                         /* Verbindung beenden. */

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}
