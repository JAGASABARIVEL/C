#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define SUCCESS 0

void* processingUnit(void* message)
{
	printf("Message : %s started...\n",message);
	sleep(1);
}

int main()
{
	pthread_t thread_1,thread_2;
	int th_1,th_2;
	char* message_1 = "Thread 1";
	char* message_2 = "Thread 2";

	th_1 = pthread_create(&thread_1,NULL,processingUnit,(void*)message_1);
	th_2 = pthread_create(&thread_2,NULL,processingUnit,(void*)message_2);

	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);

	printf("Both the threads completed\n");

	return SUCCESS;
}
