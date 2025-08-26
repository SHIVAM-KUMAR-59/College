#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket failed\n");
        return 1;
    }
    printf("Socket created\n");

    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind successful\n");

    if (listen(sockfd, 2) == -1) {
        perror("Listen failed");
        return 1;
    }
    printf("Server listening...\n");

    socklen_t len = sizeof(client);
    int a = accept(sockfd, (struct sockaddr*)&client, &len);
    if (a == -1) {
        perror("Accept failed");
        return 1;
    }
    printf("Client connected!\n");

    char charBuffer[100];
    int rcv = recv(a, charBuffer, sizeof(charBuffer) - 1, 0);
    if (rcv == -1) {
        perror("Receive failed");
        return 1;
    }

    charBuffer[rcv] = '\0'; 
    printf("Message received: %s\n", charBuffer);

    close(a);
    close(sockfd);
    return 0;
}

