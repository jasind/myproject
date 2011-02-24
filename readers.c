#include<sys/types.h>
#include<sys/sem.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<unistd.h>
int rdblock, wtblock, mutex, i, value, val1=1, val3=3;
void reader(int),writer(int);
main()
{
	mutex=semget(621,1,0666|IPC_CREAT);
	rdblock=semget(622,1,0666|IPC_CREAT);	
	wtblock=semget(623,1,0666|IPC_CREAT);
	semctl(mutex,1,SETALL,&val1);
	semctl(rdblock,1,SETALL,&val3);
	semctl(wtblock,1,SETALL,&val1);
	for(i=1;i<=3;i++)
	{
		if(fork()==0)
		reader(i);
	}
	for(i=1;i<=3;i++)
	{
		if(fork()==0)
		writer(i);
		getchar();
		kill(0,9);
	}
}
void p(int sem)
{
	struct sembuf op={0, -1, 0};
	semop(sem,&op,1);
}
void v(int sem)
{
	struct sembuf op={0, 1, 0};
	semop(sem,&op,1);
}
void reader(int id)
{
	while(1)
	{
		p(rdblock);
		p(mutex);
		if((semctl(rdblock,1,GETALL,&val1,value)==2))
			p(wtblock);
		v(mutex);
		for(i=0;i<3;i++,sleep(1))
			printf("reader %d reads data-%c\n ",id,88+i);
		v(rdblock);
		if((semctl(rdblock,1,GETALL,&val1,value)==3))
			v(wtblock);
		sleep(0);
	}
}
void writer(int id)
{
	while(1)
	{
		p(wtblock);
		for(i=0;i<3;i++,sleep(1))
			printf("writer %d writes; data-%c \n", id,80+i);
		v(wtblock);
		sleep(0);
	}
}
