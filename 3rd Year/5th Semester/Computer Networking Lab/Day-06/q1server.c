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
    printf("Socket creation successful\n");
    
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("Socket binding failed");
        close(sockfd);
        exit(1);
    }
    printf("Socket binding successful\n");
    
    if(listen(sockfd, 5) == -1){
        perror("Listen failed");
        close(sockfd);
        exit(1);
    }
    printf("Listening for connections...\n");

    while(1) {
        int acc = accept(sockfd, (struct sockaddr*) &client, &len);
        if(acc < 0){
            perror("Accept failed");
            continue;
        }
        printf("Client connected! IP: %s, Port: %d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        while(1) {
            char buffer[100];
            int n = recv(acc, buffer, sizeof(buffer)-1, 0);
            if(n <= 0) {
                printf("Client disconnected\n");
                close(acc);
                break;
            }
            buffer[n] = '\0';  
            printf("Message from client: %s\n", buffer);

            if(strcmp(buffer, "close") == 0) {
                printf("Client requested to close connection\n");
                close(acc);
                break;
            }

            char reply[100];
            printf("Enter reply to client: ");
            fgets(reply, sizeof(reply), stdin);
            reply[strcspn(reply, "\n")] = '\0';
            send(acc, reply, strlen(reply), 0);
        }
    }

    close(sockfd);
    return 0;
}