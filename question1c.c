#include<stdio.h>
#include<unistd.h>
main()
{
	int fd;
	char msg[20];
	//mknod("fifo","S_IFIFO",0);
	fd=open("fifo","r");
	while(1)
	{
		read(fd,msg,10);
		printf("the message is %s\n",msg);
		sleep(3);
	}
}
