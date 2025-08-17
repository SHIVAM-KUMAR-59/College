#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> // for close()

int main() {
    int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd == -1) {
        perror("Socket creation failed");
        return 1;
    }
    printf("Socket created successfully\n");

    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5017);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socketfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind successful\n");

    socklen_t len = sizeof(client_addr);

    while (1) {
        char recvBuffer[100];
        int recv = recvfrom(socketfd, recvBuffer, sizeof(recvBuffer) - 1, 0,
                            (struct sockaddr *)&client_addr, &len);

        if (recv == -1) {
            perror("Receive failed");
            break;
        }
        recvBuffer[recv] = '\0'; // null terminate
        printf("Client: %s\n", recvBuffer);

        if (strcmp(recvBuffer, "exit") == 0) {
            printf("Client ended the chat.\n");
            break;
        }

        char sendBuffer[100];
        printf("Enter your reply: ");
        fgets(sendBuffer, sizeof(sendBuffer), stdin);
        sendBuffer[strcspn(sendBuffer, "\n")] = 0;

        int send = sendto(socketfd, sendBuffer, strlen(sendBuffer), 0,
                          (const struct sockaddr *)&client_addr, len);
        if (send == -1) {
            perror("Send failed");
            break;
        }

        if (strcmp(sendBuffer, "exit") == 0) {
            printf("You ended the chat.\n");
            break;
        }
    }

    close(socketfd);
    return 0;
}

