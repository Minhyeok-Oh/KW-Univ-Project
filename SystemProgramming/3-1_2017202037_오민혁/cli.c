///////////////////////////////////////////////////////////////////////
// File Name : cli.c //
// Date : 2020/05/21 //
// Os : Ubuntu 16.04.5 LTS 64bits //
// Author : Oh Min Hyeok //
// Student ID : 2017202037 //
// ----------------------------------------------------------------- //
// Title : System Programming Assignment #3-1 ( socket programming ) //
// Description : ... //
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <stdlib.h>

#define BUFFSIZE	1024
#define PORTNO		40000


int main()
{
	int socket_fd, len; // socket file descriptor
	struct sockaddr_in server_addr; // socket address struct
	char haddr[]="127.0.0.1"; // address
	char buf[BUFFSIZE]; // buffer
	
	
	if((socket_fd=socket(PF_INET, SOCK_STREAM, 0))<0){ // socket open and exception handling
		printf("can't create socket.\n");
		return -1;
	}
	// set server address
	bzero(buf, sizeof(buf)); // initialize
	bzero((char*)&server_addr, sizeof(server_addr)); // initialize
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=inet_addr(haddr);
	server_addr.sin_port=htons(PORTNO);
	
	if(connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){ // request a connection to server
		printf("can't connect.\n"); // exception handling
		return -1;
	}
	
	write(STDOUT_FILENO, "> ",2);
	while((len=read(STDIN_FILENO, buf, sizeof(buf)))>0){ // input command
		char *ptr=strtok(buf,"\n"); // erase newline
		
		if(strcmp(ptr,"quit")==0){ // if command is quit
			write(socket_fd,ptr,strlen(ptr)); // send command to server
			len=read(socket_fd,buf,sizeof(buf)); // receive result from server
			write(STDOUT_FILENO, buf, strlen(buf)); // print buf
			write(STDOUT_FILENO,"\n",1); // newline
			exit(1); // program exit
				
		}
		
		
		if(write(socket_fd,ptr, strlen(ptr))>0){ // send command to server
									
			bzero(buf,sizeof(buf)); // initialize
			if((len=read(socket_fd,buf,sizeof(buf)))>0){ // receive result from server				
				write(STDOUT_FILENO, buf, strlen(buf)); // print buf
				write(STDOUT_FILENO,"\n",1); // newline
				
				
				bzero(buf,sizeof(buf)); // initialize
			}
			bzero(buf,sizeof(buf));// initialize
		}
		write(STDOUT_FILENO, "> ", 2);
	}
	close(socket_fd);
	return 0;
}
