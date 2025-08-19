#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

struct send {
    int a, b;
    char op;
};

int main() {
    printf("Name: Shivam Kumar\nRoll no: 23052753\nSection: CSE-10\n");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    printf("Socket created successfully.\n");

    // Client address
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(6017);  // arbitrary client port
    client.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (const struct sockaddr*) &client, sizeof(client)) == -1) {
        perror("Bind failed");
        close(sockfd);
        exit(1);
    }
    printf("Bind successful.\n");

    // Server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);  // server port
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct send msg;
    printf("Enter first number: ");
    scanf("%d", &msg.a);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &msg.op); // note space before %c to skip newline
    printf("Enter second number: ");
    scanf("%d", &msg.b);

    socklen_t len = sizeof(server);

    // Send struct to server
    int sendres = sendto(sockfd, &msg, sizeof(msg), 0,
                         (const struct sockaddr*) &server, len);
    if (sendres == -1) {
        perror("Send failed");
        close(sockfd);
        exit(1);
    }
    printf("Sent: %d %c %d\n", msg.a, msg.op, msg.b);

    // Receive result from server
    int ans;
    int rec = recvfrom(sockfd, &ans, sizeof(ans), 0,
                       (struct sockaddr*) &server, &len);
    if (rec == -1) {
        perror("Receive failed");
        close(sockfd);
        exit(1);
    }

    printf("Result received from server: %d\n", ans);

    close(sockfd);
    return 0;
}

