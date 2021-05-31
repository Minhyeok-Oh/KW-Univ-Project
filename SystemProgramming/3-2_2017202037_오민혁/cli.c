///////////////////////////////////////////////////////////////////////
// File Name : cli.c //
// Date : 2020/05/27 //
// Os : Ubuntu 16.04.5 LTS 64bits //
// Author : Oh Min Hyeok //
// Student ID : 2017202037 //
// ----------------------------------------------------------------- //
// Title : System Programming Assignment #3-2 ( socket programming ) //
// Description : ... //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <signal.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
	char buff[BUF_SIZE];
	int n;
	int sockfd;
	struct sockaddr_in serv_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // socket open
	
	memset(&serv_addr, 0, sizeof(serv_addr)); // initialize
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	connect(sockfd,(struct sockaddr*)&serv_addr, sizeof(serv_addr)); // connecting with server
	while(1){
		write(STDOUT_FILENO, "> ", 2);
		read(STDIN_FILENO, buff, BUF_SIZE);
		
		if(write(sockfd, buff, BUF_SIZE) > 0){
			if(read(sockfd, buff, BUF_SIZE)>0){				
				printf("from server:%s", buff);				
				memset(buff,NULL,BUF_SIZE);
			}
			else				
				break;
						
		}else
			break;
	}
	close(sockfd);
	return 0;
}
