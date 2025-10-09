/*
Q1. Write a connection-oriented client and server program in C using command line
arguments. At the server side, pass the port number (to whom the server will bind to)
in the command line. At the client side, pass the IP address and the port number of
the server (to whom the client will connect to) as command line argument and carry
out
the following tasks.
◦ After establishment of connection print the IP Address and port number of the client
to whom the server is connected now.
◦ Then exchange messages.
◦ After message exchange is over then the client sends a “close” message to the
server
to tear down the connection.
*/
//Server
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
if(argc != 2) {
printf("Usage: %s <port>\n", argv[0]);
return 1;
}
int port = atoi(argv[1]);
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if(sockfd == -1) { printf("Socket creation failed\n"); return 1; }
printf("Socket created successfully\n");
// allow quick rebinding during testing
int opt = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
struct sockaddr_in server, client;
memset(&server, 0, sizeof(server));
memset(&client, 0, sizeof(client));
server.sin_family = AF_INET;
server.sin_port = htons(port);
server.sin_addr.s_addr = INADDR_ANY;
if(bind(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) {
printf("Binding failed\n");
close(sockfd);
return 1;
}
printf("Binding successful\n");
if(listen(sockfd, 5) == -1) {
printf("Listen failed\n");
close(sockfd);
return 1;
}
printf("Server listening on port %d...\n", port);
socklen_t len = sizeof(client);
int newSock = accept(sockfd, (struct sockaddr*)&client, &len);
if(newSock < 0) {
printf("Accept failed\n");
close(sockfd);
return 1;
}
printf("Connected to client: %s:%d\n",
inet_ntoa(client.sin_addr), ntohs(client.sin_port));
char buffer[100];
while(1) {
int n = recv(newSock, buffer, sizeof(buffer) - 1, 0);
if(n <= 0) { printf("Client closed connection\n"); break; }
buffer[n] = '\0';
printf("Client: %s\n", buffer);
if(strcmp(buffer, "close") == 0) {
printf("Client requested to close. Disconnecting...\n");
break;
}
printf("Enter reply: ");
fflush(stdout);
if(fgets(buffer, sizeof(buffer), stdin) == NULL) { break; }
buffer[strcspn(buffer, "\n")] = '\0';
send(newSock, buffer, strlen(buffer), 0);
}
close(newSock);
close(sockfd);
return 0;
}
