//Client Program
#include<stdio.h> //printf
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 5555

int main()
{
	int clientsocket;
	struct sockaddr_in serverAddr;
	char buf[1024];

	clientsocket = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	printf("Client Socket Created Successfully...\n");
	
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	connect(clientsocket,(struct sockaddr *) &serverAddr,sizeof(serverAddr));
	printf("Connect to Server Successfully ... \n");
	
	recv(clientsocket,buf,1024,0);
	printf("Data recieved %s...\n",buf);
	printf("Closing Connection \n");
}

