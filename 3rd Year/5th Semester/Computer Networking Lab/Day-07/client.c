#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
printf("Name: Shivam Kumar\n");
printf("Roll No: 23052753\n\n");
if(argc != 3) {
printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
return 1;
}
char *serverIP = argv[1];
int port = atoi(argv[2]);
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if(sockfd == -1) { printf("Socket creation failed\n"); return 1; }
printf("Socket created successfully\n");
struct sockaddr_in server;
memset(&server, 0, sizeof(server));
server.sin_family = AF_INET;
server.sin_port = htons(port);
server.sin_addr.s_addr = inet_addr(serverIP);
if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
printf("Connection failed\n");
close(sockfd);
return 1;
}
printf("Connected to server successfully\n");
char buffer[100];
while(1) {
printf("Enter message: ");
fflush(stdout);
if(fgets(buffer, sizeof(buffer), stdin) == NULL) break;
buffer[strcspn(buffer, "\n")] = '\0';
send(sockfd, buffer, strlen(buffer), 0);
if(strcmp(buffer, "close") == 0) {
printf("Disconnected from server.\n");
break;
}
int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
if(n <= 0) { printf("Server closed connection\n"); break; }
buffer[n] = '\0';
printf("Server: %s\n", buffer);
}
close(sockfd);
return 0;
}
