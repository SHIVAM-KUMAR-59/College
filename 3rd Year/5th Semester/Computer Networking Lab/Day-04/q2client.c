#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>  // for close()

int main() {
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    printf("Socket created successfully\n");

    struct sockaddr_in client_addr, server_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(6017);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socketfd, (const struct sockaddr *)&client_addr, sizeof(client_addr)) == -1) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind successful\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5017);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {
        char charBuffer[100];
        printf("Enter your message: ");
        getchar(); // clear newline from previous input
        fgets(charBuffer, sizeof(charBuffer), stdin);
        charBuffer[strcspn(charBuffer, "\n")] = 0; // remove trailing newline

        int send = sendto(socketfd, charBuffer, strlen(charBuffer), 0,
                          (const struct sockaddr *)&server_addr, sizeof(server_addr));

        if (send == -1) {
            perror("Send failed");
            break;
        }

        if (strcmp(charBuffer, "exit") == 0) {
            printf("Exiting chat...\n");
            break;
        }

        char recvBuffer[100];
        socklen_t len = sizeof(server_addr);
        int recv = recvfrom(socketfd, recvBuffer, sizeof(recvBuffer) - 1, 0,
                            (struct sockaddr *)&server_addr, &len);

        if (recv == -1) {
            perror("Receive failed");
            break;
        }
        recvBuffer[recv] = '\0'; // null terminate
        printf("Server: %s\n", recvBuffer);

        if (strcmp(recvBuffer, "exit") == 0) {
            printf("Server ended the chat.\n");
            break;
        }
    }

    close(socketfd);
    return 0;
}

