#include<stdio.h>
int square(int x)
{
	return x*x;
}
int main()
{
	int x,y,i;
	int p[20];
	int a=10,b=0;
	x=0;
	y=0;
	for(i=0;i<10;i++)
		p[i]=i;
	printf("%d\n",square(24));
	for(i=1;i<a;i++)
	{
		b=b+(4*a/b)+x*y+2*a;
		y=y+y;
		y=y-y;
		y=y*i+24;
		y=square(1);
	}
	y=square(b);
	printf("%d\n",y);
	return 1;
}
