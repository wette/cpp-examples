#include<iostream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>


int main() {
    const int PORT = 12345;
    const char IP_ADDR[] = "0.0.0.0";   //0.0.0.0 --> alle IP Adressen des Rechners

    // wir legen IP Adresse und Port fest
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  //Ip Protokol
    addr.sin_port = htons(PORT); //htons konvertiert nach Network Byte Order (Big Endian)
    addr.sin_addr.s_addr = inet_addr(IP_ADDR);

    //erstellen des Sockets
    int listen_socket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);  //hier wählen wir TCP als Transportprotokoll
    if (listen_socket == -1) {
        std::cout << "Fehler beim Erstellen des Socket" << std::endl;
        return EXIT_FAILURE;
    }

    //Binden des Sockets an die vorher festgelegte IP Adresse und Port
    if (bind(listen_socket, (struct sockaddr*) &addr, sizeof(addr)) == -1) {
        std::cout << "Fehler beim Binden des Sockets an die IP Adresse und Port" << std::endl;
        close(listen_socket);
        return EXIT_FAILURE;
    }

    //konfigurieren des Sockets als Server - wir warten (lauschen) auf eingehende Verbindungen
    if (listen(listen_socket, 1) == -1) {
        std::cout << "Fehler beim Lauschen auf das Socket" << std::endl;
        close(listen_socket);
        return EXIT_FAILURE;
    }

    //wenn ein client eine verbindung initiiert, akzeptieren wir diese.
    //an dieser stelle bekommen wir ein ZWEITES Socket, das wir für die Kommunikaiton mit dem client nutzen können.
    //das erste socket lauscht weiterhin auf eingehende Verbindungen.

    //dieser Code-Block wartet auf eine eingehende Verbindung (blockiert bis sich ein Client verbindet)
    socklen_t socklen = sizeof addr;
    int sock = accept(listen_socket, 0, &socklen);
    if (sock == -1) {
        std::cout << "Fehler beim Akzeptieren einer eingegenden Verbindung" << std::endl;
        close(listen_socket);
        return EXIT_FAILURE;
    }

    //wenn wir diesen Code hier erreichen, haben wir einen verbundenen client!
    const int BUFFER_SIZE = 1024;
    char buf[BUFFER_SIZE]; //buffer, um aus dem socket zu lesen
    for(int i = 0; i<BUFFER_SIZE; i++) {
        buf[i] = 0;
    }

    //nun kann etwas in den socket geschrieben werden
    char payload[] = "Hello, Client!";
    if (send(sock, payload, sizeof(payload), 0) == -1) {
        std::cout << "Fehler beim Senden von Daten über das Socket" << std::endl;
        close(sock);
        close(listen_socket);
        return EXIT_FAILURE;
    }

    //und auch etwas herausgelesen werden
    //achtung: wir lesen hier nur die ersten paar Byte! Da aus dem Socket ein Stream herauskommt,
    //muss der folgende Code in einem echten Programm natürlich in einer Schleife aufgerufen werden!
    ssize_t num_bytes_read = recv(sock, buf, BUFFER_SIZE, 0);
    if (num_bytes_read < 0) {
        std::cout << "Fehler beim Empfangen von Daten." << std::endl;
        close(sock);
        close(listen_socket);
        return EXIT_FAILURE;
    }
    if (num_bytes_read == 0) {
        std::cout << "Der Client hat die Verbindung beendet." << std::endl;
    }
    if (num_bytes_read > 0) {
        //wir haben num_bytes_read viele Bytes vom Client erhalten.
        std::string received(buf);
        std::cout << "vom Client: " << received << std::endl;
    }

    //wir sind nun fertig und schließen den socket.
    close(listen_socket);
    close(sock);

    return 0;

}