/* 
    asio can be downloaded from: https://github.com/chriskohlhoff/asio

    compile client as g++ main-client.cpp -o client -I ../asio/asio/include -std=c++11 
    compile server as g++ main-server.cpp -o server -I ../asio/asio/include -std=c++11 

    In Windows, you need to add your local path to the downloaded asio directory to the include directory of your C++ program 
    This is a header-only library, so no need to tell the linker anything.
    
*/

#define ASIO_STANDALONE
#include "../asio/asio/include/asio.hpp"

#include <ctime>
#include <iostream>
#include <string>

using asio::ip::tcp;

/* Der Kürze halber hier ohne Fehlerbehandlung. Das machen wir im Unternehmen natürlich nicht!!! */
int main() {

    const int PORT = 12345;

    try {
        asio::io_context io_context;                                            /* Kommunikaitonskontext */
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), PORT));     /* Aceptor "nimmt den Hörer ab", wenn jemand anruft */

        tcp::socket socket(io_context);
        acceptor.accept(socket);                                                /* Eingehende Verbindung des Clients akzektieren (Hörer abnehmen) */

        std::string message = "Hello Client!";

        asio::error_code ignored_error;
        asio::write(socket, asio::buffer(message), ignored_error);              /* Daten schreiben */

        char buffer[1024];
        size_t len = socket.read_some(asio::buffer(buffer), ignored_error);     /* Daten lesen */
        std::cout << buffer << std::endl;

        socket.close();                                                         /* Verbindung beenden. */

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}