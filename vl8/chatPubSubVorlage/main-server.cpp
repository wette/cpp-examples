#include "Chat.hpp"

/*
    compile as 
    g++ -std=c++11 main-server.cpp Chat.cpp ChatProtocol.cpp -o server -I /Users/wette/Documents/FHBielefeld/eigeneVorlesungen/ObjektOrientierteProgrammierungInCpp/code/asio/asio/include/
*/
int main2() {
    Chat c(12345);

    c.start();

    return 0;
}