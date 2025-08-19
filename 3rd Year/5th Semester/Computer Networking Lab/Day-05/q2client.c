#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    printf("Name: Shivam Kumar\nRoll no: 23052753\nSection: CSE-10\n");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed");
        exit(1);
    }

    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(6017);
    client.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (const struct sockaddr*) &client, sizeof(client)) == -1) {
        printf("Bind failed");
        close(sockfd);
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct Student students[5];
    printf("Enter info of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    socklen_t len = sizeof(server);

    int sendres = sendto(sockfd, students, sizeof(students), 0,(const struct sockaddr*) &server, len);
    if (sendres == -1) {
        printf("Send failed");
        close(sockfd);
        exit(1);
    }
    printf("Sent all 5 students info to server.\n");

    struct Student top;
    int rec = recvfrom(sockfd, &top, sizeof(top), 0, (struct sockaddr*) &server, &len);
    if (rec == -1) {
        printf("Receive failed");
        close(sockfd);
        exit(1);
    }

    printf("\nHighest Scorer received from server:\n");
    printf("Name: %s\nRoll: %d\nMarks: %d\n", top.name, top.roll, top.marks);

    close(sockfd);
    return 0;
}

