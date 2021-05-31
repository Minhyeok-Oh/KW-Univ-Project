//////////////////////////////////////////////////////////////////
// File Name : cli.c 						//
// Date : 2020/06/13						//
// Os : Ubuntu 16.04.5 LTS					//
// Author : Oh Min Hyeok					//
// Student ID : 2017202037					//
// ------------------------------------------------------------ //
// Title : Assignment #4-2              			//
// Description : ... 						//
//////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#define MAX_BUF 100


char * convert_addr_to_str(unsigned long ip_addr, unsigned int port);

int main(int argc, char **argv){
	srand(time(NULL));
	char buf[MAX_BUF];
	int sockfd, client_fd,server_fd;
	struct sockaddr_in servaddr, temp,serv_addr;
	char * hostport;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);// PF_INET = IPv4 Internet Protocol, SOCK_STREAM = STREAM(TCP Protocol)
  	memset(&servaddr, 0, sizeof(servaddr)); // initialize
 	servaddr.sin_family=AF_INET; // IPv4
 	servaddr.sin_addr.s_addr=inet_addr(argv[1]); // STORE IP Address
  	servaddr.sin_port=htons(atoi(argv[2])); // STORE PORT Number
  	// server connection  	
	connect(sockfd,(struct sockaddr *)&servaddr, sizeof(servaddr));
	int n;
	write(STDOUT_FILENO, "> ", 2);
	n=read(STDIN_FILENO, buf, sizeof(buf));
	buf[n-1]='\0';
	int randnum=(rand() % 20000) + 10001;
	
	////////////////*************** data connection ***************/////////////////////////////////
	client_fd=socket(AF_INET,SOCK_STREAM,0);			
	memset(&temp,0,sizeof(temp));					
	temp.sin_family=AF_INET;
	temp.sin_addr.s_addr=inet_addr(argv[1]);
	temp.sin_port=randnum;// temporaily port number
	
	
	
	hostport=convert_addr_to_str(temp.sin_addr.s_addr,temp.sin_port);
	printf("converting to %s\n",hostport);		
	write(sockfd,hostport,strlen(hostport));
	
	
   
   	if(bind(client_fd, (struct sockaddr *)&temp, sizeof(temp))<0){
		printf("Client: Can't bind local address.\n"); // exception handling
		return 0;
	}
	
	listen(client_fd, 5);
	int len=sizeof(serv_addr);
	server_fd=accept(client_fd,(struct sockaddr*)&serv_addr,&len); // accept connect request
	
	/////////////////////////////////////////////////////////////////////////////////////////////
	char buffer[MAX_BUF];
	n=read(server_fd,buffer,sizeof(buffer)); // read from data connection
	buffer[n]='\0'; // remove trash value
	printf("%s\n",buffer);
	
	write(sockfd,buf,strlen(buf)); // sent command to control connection
	
	n=read(server_fd,buffer,sizeof(buffer));
	printf("%s\n",buffer);
	size_t length = strlen(buffer); // result byte number.
	
	char message[100]="226 Result is sent successfully.";
	printf("%s\n",message);
	write(server_fd,message,sizeof(message));
	
	printf("OK. %u bytes is received.\n",length-48); // 'length -48' is byte number that remove message byte number.
	
	close(sockfd);
	return 0;
}

char * convert_addr_to_str(unsigned long ip_addr, unsigned int port){
	char * addr=malloc(sizeof(char)*MAX_BUF);
	//////////// network order 32bit big endian --->>> dotted deciman notation ///////////////
	struct in_addr tempaddr;
	tempaddr.s_addr=ip_addr;
	char * ttemp= inet_ntoa(tempaddr);
	char * ptr=strtok(ttemp,".");
	strcpy(addr,"PORT ");
	strcat(addr,ptr);
	strcat(addr,",");
	ptr=strtok(NULL,".");
	strcat(addr,ptr);
	strcat(addr,",");
	ptr=strtok(NULL,".");
	strcat(addr,ptr);
	strcat(addr,",");
	ptr=strtok(NULL,".");
	strcat(addr,ptr);
	strcat(addr,",");
	///////////////////////////////////////////////////////////////////////////////////////
	int arr[16]={0, };
	int n=port,c=0,mok,nmg,i;
	/// ** decimal to binary ** ///
	do{
		mok=n/2;
		nmg=n-mok*2;
		arr[c++]=nmg;
		n=mok;
	}while(mok!=0);
	///////////////////////////////
	/////////// ** binary to decimal ** ////////
	int first=0;
	int decimal=0;
	for(int i=8;i<=15;i++)
	{
		if(arr[i]==1)
			decimal+=1<<first;
		first++;
	}
	char *dec=malloc(sizeof(char)*MAX_BUF);
	sprintf(dec,"%d",decimal);
	strcat(addr,dec);
	strcat(addr,",");
	
	first=0;
	decimal=0;
	for(int i=0;i<=7;i++)
	{
		if(arr[i]==1)
			decimal+=1<<first;
		first++;
	}
	sprintf(dec,"%d",decimal);
	///////////////////////////////////////
	strcat(addr,dec);
	
	return addr;
}


