#include<stdio.h>
#include<stdbool.h>

#define SUCCESS 0
#define MAX_SIZE 3

int CQueue[MAX_SIZE];
int front = -1,rear = -1;

bool isFull()
{
	if (rear == MAX_SIZE-1)
	{
		return 1;
	}
	return 0;
}

bool isEmpty()
{
	if (front == -1 && rear == -1)
	{
		return 1;
	}
	return 0;
}

void queue(int data)
{
	//printf("[QUEUE] | front : %d\n",front);
	//printf("[QUEUE] | rear : %d\n",rear);
	if (isFull())
	{
		if (front != -1)
		{
			rear = -1;
		}
		else
		{
			printf("CQueue is full.\n");
			return;
		}
	}
	if (!isEmpty())
	{
		if(rear == front)
		{
			printf("-CQueue is full.\n");
			return;
		}
	}	
	rear += 1;
	CQueue[rear] = data;
	printf("[QUEUE] | queue[%d] : %d\n",rear,CQueue[rear]);
}

void dequeue()
{
	//printf("[DEBUG] ! dequeue | rear : %d\n",rear);
	if (isEmpty())
	{
		printf("CQueue is empty.\n");
		return;
	}
	
	front += 1;
	printf("CDequeue[%d] : %d\n",front,CQueue[front]);
	CQueue[front] = 0;
	if (front == MAX_SIZE-1)
	{
		if (rear == -1 || rear == MAX_SIZE-1)
		{
			front = -1;
			rear = -1;
			printf("CQueue is empty.\n");
			return;
		}
		else
		{
			front = -1;
		}
	}
	if (front == rear)
	{
		front = -1;
		rear = -1;
		printf("[CDEQUEUE] | cleaning up | CQueue is empty.\n");
		return;
	}
}

void print()
{
	int i;
	for(i = 0 ; i <= MAX_SIZE-1 ; i++)
	{
		printf("[PRINT] | CQueue[%d] : %d\n",i,CQueue[i]);
	}
}

int main()
{
	queue(1);
	queue(2);
	queue(3);		// Queue Size = 3

	dequeue();
	dequeue();		// Queue Size = 1

	queue(4);		// Queue Size = 2
	//queue(5);
	dequeue();
	dequeue();		// Queue Size = 0
	//dequeue();

	queue(1);
	queue(2);
	queue(3);
	queue(4);
	
	dequeue();

	queue(5);

	dequeue();

	queue(6);

	queue(7);

	dequeue();
	dequeue();
	queue(8);
	queue(9);

	dequeue();
	dequeue();

	queue(1);	
	
	dequeue();
	dequeue();
	

	//print();
	return SUCCESS;
}
