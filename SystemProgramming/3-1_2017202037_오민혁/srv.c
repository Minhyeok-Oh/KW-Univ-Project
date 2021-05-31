///////////////////////////////////////////////////////////////////////
// File Name : srv.c //
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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <dirent.h>
#include <arpa/inet.h>

#define BUFFSIZE	1024
#define PORTNO		40000

void client_info(struct sockaddr_in cliaddr){
	printf("==========Client Info==========\n");
	printf("client IP: %s\n\n",inet_ntoa(cliaddr.sin_addr));
	printf("client port: %d\n",cliaddr.sin_port);
	printf("===============================\n");
}
char * cmp_process(char *buff,char *result_buff){
	
	
	
	if(strcmp(buff,"ls")==0) { // ls command
		char *cwd=(char*)malloc(sizeof(char)*1024); // dynamic allocate
		DIR * dir =NULL; // directory pointer
		struct dirent * entry =NULL; // directory struct
		getcwd(cwd,1024); // current working directory
		dir=opendir(cwd);
					
		if(dir==NULL){ // exception handling
			strcat(result_buff,"error");
			
		}
					
					
		while((entry=readdir(dir))!=NULL) // read directory
		{
						
			char *tmp=(char*)malloc(sizeof(char)*1024);
			bzero((char*)&tmp, sizeof(tmp)); // initialize
			tmp=entry->d_name; // directory name
			int length=strlen(tmp);
			
			strcat(result_buff,tmp);
			
			strcat(result_buff,"\n");
			 
		}
					
		free(cwd); // free dynamic allocate memory
		closedir(dir); // close directory
					
	}
	else{
		strcat(result_buff,"input error");
	}
	
	
	return result_buff;
}
int main()
{
	struct sockaddr_in server_addr, client_addr; // socket address struct
	int socket_fd, client_fd; // socket file descriptor, client file descriptor
	int len, len_out; // string length
	char buf[BUFFSIZE]; // buf
	char result_buf[BUFFSIZE];
	bzero(result_buf, sizeof(result_buf));
	if((socket_fd=socket(PF_INET,SOCK_STREAM,0))<0){ // socket open
		printf("Server: Can't openstream socket.");
		return 0;
	}
	
	bzero((char *)&server_addr, sizeof(server_addr)); // server_addr initialize
	//set server address
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(PORTNO);
	// associate an address with a socket
	if(bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
		printf("Server: Can't bind local address.\n"); // exception handling
		return 0;
	}
	
	listen(socket_fd,5); // a server announces that it is willing to accept connect requests
	while(1){
		len=sizeof(client_addr);
		client_fd=accept(socket_fd,(struct sockaddr*)&client_addr,&len); // accept connect request
		if(client_fd<0){ // exception handling
			printf("Server: accept failed.\n");
			return 0;
		}
		/////////// print Client Info //////////
		client_info(client_addr);
		
		bzero(buf,sizeof(buf)); // initialize
		
		// receive command from client file descriptor
		while((len_out=read(client_fd, buf, BUFFSIZE))>0) {			
			write(STDOUT_FILENO, buf, len_out); // print command
			write(STDOUT_FILENO,"\n",1); // line break
			
			if(strcmp(buf,"quit")==0){ // quit command
				write(client_fd,"Program quit!!",14);
				close(client_fd);
				close(socket_fd);
				exit(1);
				
			}
			
			write(client_fd,cmp_process(buf,result_buf),sizeof(result_buf));
			bzero(result_buf,sizeof(result_buf));
			bzero(buf,sizeof(buf)); // initialize
			
		}
		
	}
	close(socket_fd);
	return 0;
}

