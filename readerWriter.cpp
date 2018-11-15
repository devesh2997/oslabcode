#include<iostream>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

using namespace std;

sem_t mutex,wrt;
int readerCount=0;

void* writer(void *arg)
{
	while(1)
	{
		sem_wait(&wrt);
		cout<<"Writing...\n";
		sleep(1);
		sem_post(&wrt);
	}
}

void* reader(void *arg)
{
	while(1)
	{
		sem_wait(&mutex);
		readerCount++;
		if(readerCount==1)
			sem_wait(&wrt);
		sem_post(&mutex);
		cout<<"Reading..\n";
		sleep(1);
		sem_wait(&mutex);
		readerCount--;
		if(readerCount==0)
			sem_post(&wrt);
		sem_wait(&mutex);
	}
}

int main()
{
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_t r1,r2,r3,r4,w1,w2;
	pthread_create(&r1,NULL,reader,NULL);
	pthread_create(&w1,NULL,writer,NULL);
	pthread_create(&w2,NULL,writer,NULL);

	pthread_join(w1,NULL);
	pthread_join(w2,NULL);
	pthread_join(r1,NULL);
	
	return 0;
}
