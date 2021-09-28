#include<iostream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>


int main() {
    const int PORT = 12345;
    const char IP_ADDR[] = "127.0.0.1";   //127.0.0.1 --> "virtuelle" IP Adresse, die immer dem eigenen Rechner gehört

    // wir legen IP Adresse und Port fest
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  //Internet Protokol
    addr.sin_port = htons(PORT); //htons konvertiert nach Network Byte Order (Big Endian)
    addr.sin_addr.s_addr = inet_addr(IP_ADDR);

    //erstellen des Sockets
    int sock = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);  //hier wählen wir TCP als Transportprotokoll
    if (sock == -1) {
        std::cout << "Fehler beim Erstellen des Socket" << std::endl;
        return EXIT_FAILURE;
    }

    //Anrufen des Servers
    if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        std::cout << "Fehler beim Initiieren einer Verbindung mit dem Server" << std::endl;
        close(sock);
        return EXIT_FAILURE;
    }

    //wenn wir diesen Code hier erreichen, sind wir mit dem Server verbunden!

    //nun kann etwas in den socket geschrieben werden
    char payload[] = "Hello, Server!";
    if (send(sock, payload, sizeof(payload), 0) == -1) {
        std::cout << "Fehler beim Senden von Daten über das Socket" << std::endl;
        close(sock);
        return EXIT_FAILURE;
    }

    //und auch etwas herausgelesen werden

    const int BUFFER_SIZE = 1024;
    char buf[BUFFER_SIZE]; //buffer, um aus dem socket zu lesen
    for(int i = 0; i<BUFFER_SIZE; i++) {
        buf[i] = 0;
    }

    //achtung: wir lesen hier nur die ersten paar Byte! Da aus dem Socket ein Stream herauskommt,
    //muss der folgende Code in einem echten Programm natürlich in einer Schleife aufgerufen werden!
    ssize_t num_bytes_read = recv(sock, buf, BUFFER_SIZE, 0);
    if (num_bytes_read < 0) {
        std::cout << "Fehler beim Empfangen von Daten." << std::endl;
        close(sock);
        return EXIT_FAILURE;
    }
    if (num_bytes_read == 0) {
        std::cout << "Der Server hat die Verbindung beendet." << std::endl;
    }
    if (num_bytes_read > 0) {
        //wir haben num_bytes_read viele Bytes vom Server erhalten.
        std::string received(buf);
        std::cout << "vom Server: " << received << std::endl;
    }

    //wir sind nun fertig und schließen den socket.
    close(sock);

    return 0;

}