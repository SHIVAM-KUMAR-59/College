/*
Types of socket programming:
- Connection Less(UDP)
- Connection Oriented(TCP)

UDP:
	- Must open 2 terminals, client and server, run the server one first using certain functions like socket()
	  bind()
	  
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
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(){
	int socketConn = socket(AF_INET, SOCK_DGRAM, 0);
	if(socketConn == -1) {
		printf("Socket connection failed\n");
	}else {
		printf("Socket connection successfull\n");
	}
	
	return 0;
}
