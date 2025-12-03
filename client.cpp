#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    const char* server_ip = "127.0.0.1";   // server address
    int server_port = 8080;                // server port

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    // server address struct
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server.sin_addr);

    // connect
    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connection failed\n";
        close(sock);
        return 1;
    }

    // send message
    const char* msg = "GET / HTTP/1.1\r\n"
    "Host: example.com\r\n"
    "Connection: close\r\n"
    "\r\n";
    ssize_t sent = send(sock, msg, strlen(msg), 0);
    if (sent < 0) {
        std::cerr << "Send failed\n";
    }

    std::cout << "Sent: " << msg << std::endl;

    close(sock);
    return 0;
}
