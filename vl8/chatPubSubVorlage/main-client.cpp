#include "Chat.hpp"
#include<string>

/*
    compile as 
    g++ -std=c++11 main-client.cpp Chat.cpp ChatProtocol.cpp -o client -I /Users/wette/Documents/FHBielefeld/eigeneVorlesungen/ObjektOrientierteProgrammierungInCpp/code/asio/asio/include/
*/
int main() {
    std::string address("localhost");
    std::string port("12345");

    Chat c(address, port);
    c.start();

    return 0;
}