#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int a_to_b[2],b_to_c[2],c_to_a[2];
main()
{
	pipe(a_to_b);
	pipe(b_to_c);
	pipe(c_to_a);
	if(fork()==0)
	{
		processA();
	}
	if(fork()==0)
	{
		processB();
	}
	if(fork()==0)
	{
		processC();
	}
	wait();
	wait();
	wait();
}
processA()
{
	int a,b,c;
	printf("Process A\nEnter two numbers \n");
	scanf("%d %d",&a,&b);
	write(a_to_b[1],&a,sizeof(a));
	//sleep(1);
	write(a_to_b[1],&b,sizeof(b));
	sleep(1);
	read(c_to_a[0],&c,sizeof(int));
	printf("The number written by process c is %d\n",c);
	exit(0);
}
processB()
{
	int p,q,r;
	read(a_to_b[0],&p,sizeof(int));
	read(a_to_b[0],&q,sizeof(int));
	r=p+q;
	printf("Process B:The sum of two numbers is %d\n",r);
	write(b_to_c[1],&r,sizeof(int));
	exit(0);
}
processC()
{
	int w,x;
	read(b_to_c[0],&w,sizeof(int));
	x=w*w;
	printf("Process C: The square of the number is %d\n",x);
	write(c_to_a[1],&x,sizeof(int));
	exit(0);
}
