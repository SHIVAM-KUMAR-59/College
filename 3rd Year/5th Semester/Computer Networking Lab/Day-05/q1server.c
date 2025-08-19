#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

struct rec {
    int a, b;
    char op;
};

int calc(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else {
        if (b == 0) {
            printf("Division by zero attempted!\n");
            return 0;
        }
        return a / b;
    }
}

int main() {
    printf("Name: Shivam Kumar\nRoll no: 23052753\nSection: CSE-10\n");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Socket created successfully.\n");

    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (const struct sockaddr*) &server, sizeof(server)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(1);
    }
    printf("Bind successful. Waiting for client...\n");

    struct rec recStruct;
    socklen_t len = sizeof(client);

    int recieve = recvfrom(sockfd, &recStruct, sizeof(recStruct), 0,
                           (struct sockaddr*) &client, &len);
    if (recieve == -1) {
        perror("Receive failed");
        close(sockfd);
        exit(1);
    }

    printf("Received from client: %d %c %d\n", recStruct.a, recStruct.op, recStruct.b);

    int ans = calc(recStruct.a, recStruct.b, recStruct.op);

    int sendres = sendto(sockfd, &ans, sizeof(ans), 0, (const struct sockaddr*) &client, len);
    if (sendres == -1) {
        perror("Send failed");
        close(sockfd);
        exit(1);
    }

    printf("Result %d sent to client.\n", ans);

    close(sockfd);
    return 0;
}

