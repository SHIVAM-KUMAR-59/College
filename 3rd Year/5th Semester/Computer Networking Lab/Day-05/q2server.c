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

    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(5017);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (const struct sockaddr*) &server, sizeof(server)) == -1) {
        printf("Bind failed");
        close(sockfd);
        exit(1);
    }
    printf("Server waiting for student info...\n");

    struct Student students[5];
    int len = sizeof(client);

    int rec = recvfrom(sockfd, students, sizeof(students), 0, (struct sockaddr*) &client, &len);
    if (rec == -1) {
        printf("Receive failed");
        close(sockfd);
        exit(1);
    }

    printf("Received 5 students from client:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s | Roll: %d | Marks: %d\n", students[i].name, students[i].roll, students[i].marks);
    }

    struct Student top = students[0];
    for (int i = 1; i < 5; i++) {
        if (students[i].marks > top.marks) {
            top = students[i];
        }
    }

    int sendres = sendto(sockfd, &top, sizeof(top), 0, (const struct sockaddr*) &client, len);
    if (sendres == -1) {
        printf("Send failed");
        close(sockfd);
        exit(1);
    }

    printf("\nSent highest scorer back to client:\n");
    printf("Name: %s | Roll: %d | Marks: %d\n", top.name, top.roll, top.marks);

    close(sockfd);
    return 0;
}

