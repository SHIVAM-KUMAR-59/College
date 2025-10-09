#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
printf("Name: Shivam Kumar\n");
printf("Roll No: 23052753\n");
if (argc != 2) {
printf("Usage: %s <port>\n", argv[0]);
return 1;
}
int sockfd, newsockfd;
struct sockaddr_in server_addr, client_addr;
socklen_t client_len;
char buffer[1024];
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) {
perror("Socket creation failed");
exit(1);
}
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(atoi(argv[1]));
if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
perror("Bind failed");
close(sockfd);
exit(1);
}
listen(sockfd, 5);
printf("Server listening on port %s...\n", argv[1]);
while (1) {
client_len = sizeof(client_addr);
newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
if (newsockfd < 0) {
perror("Accept failed");
continue;
}
printf("Connected to client: %s:%d\n", inet_ntoa(client_addr.sin_addr),
ntohs(client_addr.sin_port));
if (fork() == 0) {
close(sockfd);
while (1) {
memset(buffer, 0, sizeof(buffer));
int n = recv(newsockfd, buffer, sizeof(buffer), 0);
if (n <= 0) {
printf("Client disconnected.\n");
break;
}
buffer[n] = '\0';
printf("Client [%s:%d]: %s\n", inet_ntoa(client_addr.sin_addr),
ntohs(client_addr.sin_port), buffer);
if (strcmp(buffer, "logout") == 0) {
printf("Client %s:%d logged out.\n", inet_ntoa(client_addr.sin_addr),
ntohs(client_addr.sin_port));
break;
}
send(newsockfd, buffer, strlen(buffer), 0);
}
close(newsockfd);
exit(0);
} else {
close(newsockfd);
}
}
close(sockfd);
return 0;
}
