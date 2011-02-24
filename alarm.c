#include<sys/types.h>
#include<sys/stat.h>
#include<sys/signal.h>
#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	struct stat statbuf;
	time_t axtime;
	extern void wakeup();
	if(argc!=2)
	{
		printf("only 1 arg\n");
		exit(0);
	}
	axtime=(time_t) 0;
	for(;;)
	{
		if(stat(argv[1],&statbuf)==-1)
		{
			printf("file %s not there\n",argv[1]);
			exit(0);
		}
		if(axtime!=statbuf.st_atime)
		{
			printf("file %s accessed \n",argv[1]);
			axtime=statbuf.st_atime;
		}
		signal(SIGALRM,wakeup);
		alarm(60);
		pause();
	}
}
void wakeup()
{
}
