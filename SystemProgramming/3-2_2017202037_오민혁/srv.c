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
#include <string.h>

#define BUF_SIZE 256

void client_info(struct sockaddr_in cliaddr){ // print client info
	printf("==========Client Info==========\n");
	printf("client IP: %s\n\n",inet_ntoa(cliaddr.sin_addr));
	printf("client port: %d\n",cliaddr.sin_port);
	printf("===============================\n");
}
void sh_chld(int signum){
	printf("Status of Child process was changed.\n");
	wait(NULL);
}
void sh_alrm(int signum){
	printf("Child Process(PID : %d) will be terminated.\n", getpid());
	exit(1);
}

int main(int argc, char **argv)
{
	char buff[BUF_SIZE];
	int n;
	struct sockaddr_in server_addr, client_addr;
	int server_fd, client_fd;
	int len;
	int port;
	
	signal(SIGCHLD, (void*)sh_chld); // Applying signal handler SIGCHLD
	signal(SIGALRM, (void*)sh_alrm); // Applying signal handler SIGALRM
	
	server_fd = socket(PF_INET, SOCK_STREAM, 0); // open socket
	
	memset(&server_addr, 0, sizeof(server_addr)); // initialize
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(atoi(argv[1]));
	// binding server
	if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
		printf("Server: Can't bind local address.\n"); // exception handling
		return 0;
	}
	listen(server_fd, 5); // listening server_fd signal
	
	while(1)
	{
		pid_t pid;
		len = sizeof(client_addr);
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &len);
		if(client_fd<0){ // exception handling
			printf("Server: accept failed.\n");
			return 0;
		}
		client_info(client_addr); // printf client info
		
		pid=fork(); // making child process
		if(pid==0){
			printf("Child Process ID : %d\n",getpid()); // printf child process information
			while(read(client_fd,buff,BUF_SIZE)>0){ // read buff
				if(strcmp(buff,"QUIT\n")==0)
					alarm(1); // call sh_arlm()
				else{
					write(client_fd,buff,BUF_SIZE); // write at client_fd
					memset(buff,NULL,BUF_SIZE); // initialize
				}
			}		
		}
		close(client_fd); // close
	}
	
	return 0;
}


