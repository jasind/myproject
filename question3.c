#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
void *funA(void *);
void *funB(void *);
sem_t s1,s2;
int x[10]={0,1,2,3,4,5,6,7,8,9};
int i=0;
int main()
{
	int res1,res2;
	pthread_t t1,t2;
	void *t1_result;
	res1=sem_init(&s1,0,1);
	res2=sem_init(&s2,0,0);
	if(res1!=0||res2!=0)
	{
		perror("Semaphore initilization failed\n");
		exit(EXIT_FAILURE);
	}
	res1=pthread_create(&t1,NULL,funA,(void *)("A"));
	res2=pthread_create(&t2,NULL,funB,(void *)("B"));
	if(res1!=0||res2!=0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	pthread_join(t2,t1_result);
	pthread_join(t1,t1_result);
	//printf("\nThread joined it returned",(char *)t1_result);
	exit(EXIT_SUCCESS);
}
void *funA(void *arg)
{
	int j=0;
	while(j<5)
	{
		sem_wait(&s1);
		printf("Thread %s printing x[%d]= %d\n",(char *)arg,i,x[i]);
		++i;
		++j;
		sem_post(&s2);
		//sleep(1);
	}
}
void *funB(void *arg)
{
	int j=0;
	while(j<5)
	{
		sem_wait(&s2);
		printf("Thread %s printing x[%d]= %d\n",(char *)arg,i,x[i]);
		++i;
		++j;
		sem_post(&s1);
		//sleep(1);
	}
}
