#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdio.h>
sem_t mutex,writeBlock,readBlock;
int readCount=0,data;
void *reader(void *p)
{
	int j=0,q;
	q=(*(int *)p);
	while(j<3)
	{
		sem_wait(&readBlock);
			sem_wait(&mutex);
				readCount++;
				if(readCount==1)
					sem_wait(&writeBlock);
			sem_post(&mutex);
			printf("Reader %d = %d\n",q,data);
		//sleep(1);
			sem_wait(&mutex);
				readCount--;
				if(readCount==0)
					sem_post(&writeBlock);
			sem_post(&mutex);
		//sleep(3);
		j++;
		sleep(3);
	}
}
void *writer(void *q)
{
	int j=0,p,i;
	p=(*(int *)q);
	while(j<3)
	{
		sem_wait(&writeBlock);
			j++;
			data++;
			printf("Writer %d = %d\n",p,data);
		sem_post(&writeBlock);
		for(i=0;i<4;i++)
			sem_post(&readBlock);
		sleep(5);
	}
}
main()
{
	pthread_t t1,t2,t3,t4,t5,t6;
	void *res;
	int a=1,b=2,c=3,d=4;
	sem_init(&mutex,0,1);
	sem_init(&readBlock,0,0);
	sem_init(&writeBlock,0,1);
	pthread_create(&t4,NULL,writer,&b);
	pthread_create(&t1,NULL,reader,&a);
	pthread_create(&t2,NULL,reader,&b);
	//printf("this is main\n");
	pthread_create(&t3,NULL,writer,&a);
	pthread_create(&t5,NULL,reader,&c);
	pthread_create(&t6,NULL,reader,&d);
	pthread_join(t1,&res);
	pthread_join(t2,&res);
	pthread_join(t3,&res);
	pthread_join(t4,&res);
	pthread_join(t5,&res);
	pthread_join(t6,&res);
}
