///////////////////////////////////////////////////////////////////////
// File Name : Assignment2-2.c //
// Date : 2020/05/04 //
// Os : Ubuntu 16.04.5 LTS 64bits //
// Author : Oh Min Hyeok //
// Student ID : 2017202037 //
// ----------------------------------------------------------------- //
// Title : System Programming Assignment #2-2 ( ls ) //
// Description : ... //
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h> // for struct dirent

int main(int argc, char *argv[]) {
	DIR *dp; // for opendir
	struct dirent *dirp; // for readdir
	
	if(argc==1){
		printf("No input\n"); // no argument
		return 0;
	}
	
	if(opendir(argv[1])==NULL){ // exception handling
		printf("can't open %s\n", argv[1]);
		return 0;
	}
	else{
		dp=opendir(argv[1]);
	}
	while((dirp=readdir(dp)) != NULL){		
		printf("%s\n", dirp->d_name);				
	}
	
	closedir(dp);
}
