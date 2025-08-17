// Send your name from client and recieve roll number from server
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> // man 7 ip
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<string.h>

int main(){
	//if(count < 3) {
	//	printf("Not enough arguments\n");
	//	return 0;
	//}
	int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1) {
		printf("Socket connection failed\n");
	}else {
		printf("Socket connection successfull\n");
	}
	
	struct sockaddr_in client_addr; // address declaration
	// populating the structure
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(6017); // htons = host to network address
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int bindConn = bind(socketfd, (const struct sockaddr *) (&client_addr), sizeof(client_addr));
	if(bindConn == -1){
		printf("Socket binding unsuccessfull\n");
	}else {
		printf("Socket binding successfull\n");
	}
	
	char charBuffer[100];
	printf("Enter your name\n");
	scanf("%[^\n]s", charBuffer);
	int flags = 0;
	
	struct sockaddr_in server_addr; // address declaration
	// populating the structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5017); // htons = host to network address
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int send = sendto(socketfd, charBuffer, strlen(charBuffer), flags, (const struct sockaddr*) (&server_addr), sizeof(server_addr));
	
	if(send == -1) {
		printf("Error sending the message\n");
		return 1;
	}
	
	printf("Message sent successfully\n");
	
	int temp = sizeof(server_addr);
	char recieveBuffer[100];
	int recieve = recvfrom(socketfd, recieveBuffer, sizeof(recieveBuffer), flags, (struct sockaddr *)(&server_addr), &temp);
	
	if(recieve == -1){
		printf("Message recieve failed\n");
		return 1;
	}
	
	printf("Message recieved successfully: %s\n", recieveBuffer);
	
	return 0;
}



