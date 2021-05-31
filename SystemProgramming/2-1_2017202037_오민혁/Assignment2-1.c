///////////////////////////////////////////////////////////////////////
// File Name : Assignment2-1.c //
// Date : 2020/05/04 //
// Os : Ubuntu 16.04.5 LTS 64bits //
// Author : Oh Min Hyeok //
// Student ID : 2017202037 //
// ----------------------------------------------------------------- //
// Title : System Programming Assignment #2-1 ( ftp server ) //
// Description : ... //
///////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
int main (int argc, char **argv) // argument count, argument vector
{
	int aflag = 0, bflag = 0; // a flag, b flag
	char *cvalue = NULL;
	int index, c;
	opterr = 0;
	while ((c = getopt (argc, argv, "abc:")) != -1)
	{
		switch (c){
			case 'a':
				aflag=1; // aflag on
				break;
			case 'b':
				bflag=1; // bflag on
				break;
			case 'c':
				cvalue=optarg; // input optarg to cvalue
				break;
			
		}
	}
	printf("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);
	for (index = optind; index < argc; index++)
		printf("Non-option argument %s\n", argv[index]);
	return 0;
}
