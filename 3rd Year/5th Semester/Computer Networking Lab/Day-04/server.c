/*
Types of socket programming:
- Connection Less(UDP)
- Connection Oriented(TCP)

UDP:
	- Must open 2 terminals, client and server, run the server one first using certain functions like:
	  
	  Client				Server
	  				
	  						socket()
	  socket()				   |
	  	 |					   |
	  bind()				bind()
	     |                     |
	  sendto()      --->   	recvfrom()
	  
	  recvfrom()	<---	sendto()
	  	 |                     |
	  close()				close()
	  
	- int socket(int domain, int type, int protocol); 
	domain = AF_INET IPv4
	type = type of connection (UDP/TCP) SOCK_SCREAM is for TCP(connection-oriented), SOCK_DGRAM for UDP
	protocol = default value 0
	- int socket(AF_INET, SOCK_DGRAM, 0);
	- if error then it returns -1
	- #include<sys/types.h>, #include<sys/socket.h>
	
	- bind(): bind a name to a socket
		- int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
		- struct sockaddr {
			sa_family_t sa_family; // AF_INET
			char sa_data[14]; // contains IP address and port number
		}
		- struct sockaddr {
			sa_family_t sin_family; // AF_INET
			in_port_t sin_port; // port in network byte order
			struct in_addr sin_addr; // internet address
		}
		- struct in_addr {
			uint32_t s_addr; // adress in network byte order
		}
	
	- recvfrom(): Recieve a message from a socket
		- ssize_t recvfrom(int sockfd, void *buff, size_t len, int flags, struct sockaddr *_Nullable restrict src_addr, socklen_t *_Nullable restrict addrlen);
	 
	- sendto(): Send a message on a scoket
	 	- ssize_t sendto(int sockfd, const void buff[.len], size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
		 
*/

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
	
	printf("Message recieved successfully: %s\n", charBuffer);
	
	return 0;
}



