#include <stdlib.h>
// Code for TCP client

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		printf("Socket failed\n");
		return 0;
	}
	
	printf("Socket connected\n");
	
	struct sockaddr_in client, server;
	client.sin_family = AF_INET;
	client.sin_port = htons(6017);
	client.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	server.sin_family = AF_INET;
	server.sin_port = htons(5017);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sockfd, (const struct sockaddr*) &server, sizeof(server)) == -1){
		printf("Connection failed\n");
		return 0;
	}
	printf("Connection successfull\n");
	
	char charBuffer[100];
	printf("Enter message:\n");
	fgets(charBuffer, sizeof(charBuffer), stdin);
	
	int scv = send(sockfd, charBuffer, strlen(charBuffer), 0);
	if(scv == 1){
		printf("Error sending\n");
		return 0;
	}
	
	printf("Message sent\n");
	
	close(sockfd);
	
	return 0;
}
