//////////////////////////////////////////////////////////////////
// File Name : srv.c 						//
// Date : 2020/06/13 						//
// Os : Ubuntu 16.04.5 LTS					//
// Author : Oh Min Hyeok					//
// Student ID : 2017202037					//
// ------------------------------------------------------------ //
// Title : Assignment #4-2			                //
// Description : ... 						//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUF 100
char * cmp_process(char *buff,char *result_buff);
char * convert_str_to_addr(char*str, unsigned int *port);

int main(int argc, char **argv) {
	char result_buff[MAX_BUF]; // RESULT BUFF
	bzero(result_buff, sizeof(result_buff));
	char buf[MAX_BUF]; // buf
	char temp[25];
	char *host_ip=NULL;
	unsigned int port_num;
	int n;
	int server_fd, client_fd;
	struct sockaddr_in servaddr, cliaddr;
	
	server_fd = socket(PF_INET, SOCK_STREAM, 0); // PF_INET = IPv4 Internet Protocol, SOCK_STREAM = STREAM(TCP Protocol)
   
   	memset(&servaddr, 0, sizeof(servaddr)); // initialize
   	servaddr.sin_family=AF_INET; // IPv4
   	servaddr.sin_addr.s_addr=htonl(INADDR_ANY); // SET IP Address automatically 
   	servaddr.sin_port=htons(atoi(argv[1]));
   	
   	if(bind(server_fd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0){
		printf("Server: Can't bind local address.\n"); // exception handling
		return 0;
	}
	
	listen(server_fd, 5);
	int len=sizeof(cliaddr);
	client_fd=accept(server_fd,(struct sockaddr*)&cliaddr,&len); // accept connect request
	
	n=read(client_fd,temp,sizeof(temp));
	temp[n]='\0';
	printf("%s\n",temp);
	host_ip=convert_str_to_addr(temp,(unsigned int*)&port_num);
	//////////////////////////// ***** data connection ***** //////////////////////////////////////
	int sockfd;
	struct sockaddr_in sockaddr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);// PF_INET = IPv4 Internet Protocol, SOCK_STREAM = STREAM(TCP Protocol)
  	memset(&sockaddr, 0, sizeof(sockaddr)); // initialize
 	sockaddr.sin_family=AF_INET; // IPv4
 	sockaddr.sin_addr.s_addr=inet_addr(host_ip); // STORE IP Address
  	sockaddr.sin_port=port_num; // STORE PORT Number
  	// server connection  	
	connect(sockfd,(struct sockaddr *)&sockaddr, sizeof(sockaddr));
	////////////////////////////////////////////////////////////////////////////////////////////////
	char message[100]="200 Port command successful";
	printf("%s\n",message);
	write(sockfd,message,strlen(message));
	n=read(client_fd,temp,sizeof(temp));
	temp[n]='\0'; /// remove trash value
	printf("%s\n",temp);
	
	strcpy(message,"226 Result is sent successfully.");
	write(sockfd,cmp_process(temp,result_buff),sizeof(result_buff));
		
	n=read(sockfd,message,sizeof(message));
	printf("%s\n",message);
	
	
		
		
	
	
	
	
	close(client_fd);
	
}
char * convert_str_to_addr(char*str, unsigned int *port)
{
	//////////// ***** Separate PORT Command ***** ////////////////////
	char * addr=malloc(sizeof(char)*20);
	char * ptr=strtok(str," ");
	
	ptr=strtok(NULL,",");
	////////////////////// IP Address //////////////////////////////
	strcpy(addr,ptr);
	
	strcat(addr,".");
	
	ptr=strtok(NULL,",");
	strcat(addr,ptr);
	strcat(addr,".");
	ptr=strtok(NULL,",");
	strcat(addr,ptr);
	strcat(addr,".");
	ptr=strtok(NULL,",");
	strcat(addr,ptr);
	
	/////////////////////////////////////////////////////////////////
	////////////////////////// PORT //////////////////////////////
	ptr=strtok(NULL,",");
	unsigned int tmp=atoi(ptr)*256;
	ptr=strtok(NULL,",");
	tmp=tmp+atoi(ptr);
	*port=tmp;
	///////////////////////////////////////////////////////////////
	return addr;
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
		printf("%s\n","150 Opening data connection for directory list.");			
		strcpy(result_buff,"150 Opening data connection for directory list.");
		strcat(result_buff,"\n");			
		while((entry=readdir(dir))!=NULL) // read directory
		{
						
			char *tmp=(char*)malloc(sizeof(char)*1024);
			bzero((char*)&tmp, sizeof(tmp)); // initialize
			tmp=entry->d_name; // directory name
			int length=strlen(tmp);
			
			strcat(result_buff,tmp);
			
			strcat(result_buff,"\n");
			 
		}
		result_buff[strlen(result_buff)-1]='\0';			
		free(cwd); // free dynamic allocate memory
		closedir(dir); // close directory
					
	}
	else{
		strcat(result_buff,"input error");
	}
	
	
	return result_buff;
}
