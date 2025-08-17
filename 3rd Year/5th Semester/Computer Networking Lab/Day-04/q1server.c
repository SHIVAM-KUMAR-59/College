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
	// if(count < 3) {
	//	printf("Not enough arguments\n");
	//	return 0;
	// }
	int socketfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketfd == -1) {
		printf("Socket connection failed\n");
	}else {
		printf("Socket connection successfull\n");
	}
	
	struct sockaddr_in server_addr; // address declaration
	// populating the structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5017); // htons = host to network address
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int bindConn = bind(socketfd, (const struct sockaddr *) (&server_addr), sizeof(server_addr));
	if(bindConn == -1){
		printf("Socketinding unsuccessfull\n");
	}else {
		printf("Socket binding successfull\n");
	}
	
	struct sockaddr_in client_addr; // client address declaration
	
	char charBuffer[100];
	int flags = 0;
	int temp = sizeof(client_addr);
	int recieve = recvfrom(socketfd, charBuffer, sizeof(charBuffer), flags, (struct sockaddr *)(&client_addr), &temp);
	
	if(recieve == -1){
		printf("Message recieve failed\n");
		return 1;
	}
	
	printf("Name recieved successfully: %s\n", charBuffer);

	char sendBuffer[100];
	printf("Enter roll number to send: ");
	scanf("%[^\n]s", sendBuffer);
	
	int send = sendto(socketfd, sendBuffer, strlen(sendBuffer), flags, (const struct sockaddr*) (&client_addr), sizeof(client_addr));
	if(send == -1){
		printf("Send failed\n");
	}
	
	printf("Message sent successfully\n");
	
	return 0;
}



