#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if(sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Socket created successfully\n");

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("Connection to server failed");
        close(sockfd);
        exit(1);
    }
    printf("Connected to server successfully\n");

    while(1) {
        char msg[100];
        printf("Enter message for server: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';

        send(sockfd, msg, strlen(msg), 0);

        if(strcmp(msg, "close") == 0) {
            printf("Disconnected from server\n");
            break;
        }

        char buffer[100];
        int n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
        if(n <= 0) {
            printf("Server closed connection\n");
            break;
        }
        buffer[n] = '\0';
        printf("Reply from server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}