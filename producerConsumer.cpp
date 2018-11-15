#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

using namespace std;

sem_t mutex,full,empty;
void *producer(void* arg)
{
	while(1)
	{
		sem_wait(&empty);
		cout<<"To Produce..\n";
		sem_wait(&mutex);
		cout<<"Produceing...\n";
		sleep(2);
		sem_post(&mutex);
		sem_post(&full);
	}
}

void *consumer(void* arg)
{
	while(1)
	{
		sem_wait(&full);
		cout<<"To Consume:\n";
		sem_wait(&mutex);
		cout<<"Consuming ..\n";
		sleep(2);
		sem_post(&mutex);
		sem_post(&empty);
	}
}
int main()
{
	cout<<"Enter Buffer:";
	int buffer;
	cin>>buffer;
	sem_init(&mutex,0,1);
	sem_init(&empty,0,buffer);
	sem_init(&full,0,0);
	pthread_t p1,c1;
	pthread_create(&p1,NULL,producer,NULL);
	pthread_create(&c1,NULL,consumer,NULL);
	pthread_join(c1,NULL);
	pthread_join(p1,NULL);
}
