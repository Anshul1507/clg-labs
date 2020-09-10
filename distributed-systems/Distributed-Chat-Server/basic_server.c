//Server Code
#include<stdio.h> //printf
#include<stdlib.h>
#include<string.h>
# include <sys/socket.h>
#include<sys/types.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define PORT 5555

int main()
{
	int sockfd;
	struct sockaddr_in serverAddr;
	int newSocket;
	struct sockaddr_in newAddr;
	socklen_t addr_size;
	char buf[1024];

	sockfd = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	printf("Server Socket Created Successfully...\n");
	
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	bind(sockfd,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	printf("Bind to port number %d \n",4455);
	
	listen(sockfd,6);
	printf("Listening...\n");

	newSocket=accept(sockfd,(struct sockaddr *)&newAddr,&addr_size);
	strcpy(buf,"Hello from Server");
	send(newSocket,buf,strlen(buf),0);
	printf("Closing Connection \n");
}

