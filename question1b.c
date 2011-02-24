#include<stdio.h>
#include<string.h>
#include<unistd.h>
main()
{
	int fd;
	char msg[20]="c3";
	mknod("fifo","S_IFIFO",0);
	fd=open("fifo","w");
	while(1)
	{
		gets(msg);
		write(fd,msg,strlen(msg));
	}
	//sleep(5);
	close(fd);
	return(0);
}
		
