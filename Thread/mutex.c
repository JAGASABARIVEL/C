#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define SUCCESS 0;

struct packet
{
	int option;
	char* message;
	struct packet* link_address;
};

struct packet* root = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counter(struct packet* roo)
{
	//int count = 0;
	int count = roo->option;
	static int counter = 0;
	printf("Message %s entered the counter\n",roo->message);
	sleep(2);
	pthread_mutex_lock(&mutex);
	printf("Locked and entering critical section by the thread %s\n",roo->message);
	sleep(1);
	if (count == 0)
	{
		counter += 1;
	}
	else
	{
		counter += 2;
	}
	pthread_mutex_unlock(&mutex);
	printf("Released the lock and leaving critical section by the thread %s\n",roo->message);
}

void load_queue(int option,char* message)
{
	struct packet* temp;
	temp = (struct packet*)malloc(sizeof(struct packet));
	temp->option = option;
	temp->message = message;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		struct packet* temp_link;
		temp_link = root;
		while(temp_link->link_address != NULL)
		{
			temp_link = temp_link->link_address;
		}
	//	temp_link = temp_link->link_address;
		temp_link->link_address = temp;
		root = temp_link;
	}
}

int main()
{
	pthread_t thread_1,thread_2;
	
	load_queue(0,"Thread 1");
	load_queue(1,"Thread 2");
	struct packet* temp = root;
	struct packet* var1;
	struct packet* var2;


	while(temp->link_address != NULL)
	{
		var1 = temp;
		temp = temp->link_address;
	}
	var2 = temp;
	

	pthread_create(&thread_1,NULL,counter,(struct packet*)var1);
	pthread_create(&thread_2,NULL,counter,(struct packet*)var2);
	
	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);

	printf("Threads completed their jobs...\n");

	return SUCCESS;
}
