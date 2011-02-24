#include<stdio.h>
main()
{
	printf("Hello\n");
	if(fork()==0)
	{
		printf("form child world\n");
	}
}
