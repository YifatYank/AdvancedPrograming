//
// Created by yifat on 29/12/16.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void sendToSocket(int sock, char* data, struct sockaddr_in &sin) {
    int sent_bytes = sendto(sock, data, strlen(data), 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}

void receiveFromSocket(int sock){
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    memset(&buffer, 0, sizeof(buffer));
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    cout << "The server sent: " << buffer << endl;
}

int main2() {

    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    sendToSocket(sock, "hello", sin);
    receiveFromSocket(sock);

    sendToSocket(sock, "kuku", sin);
    receiveFromSocket(sock);

    sendToSocket(sock, "knock knock", sin);
    receiveFromSocket(sock);

    close(sock);

    return 0;
}