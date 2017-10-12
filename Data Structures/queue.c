#include<stdio.h>
#include<stdbool.h>

//MACROS

#define SUCCESS 0
#define MAX_SIZE 10

//GLOBAL VARIABLES

int front = 0,rear = 0;
int Queue[MAX_SIZE];

//CODE

bool isFull()
{
	if(rear == MAX_SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool isEmpty()
{
	if(rear == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void queue(int data)
{
	if (isFull())
	{
		printf("QUEUE IS FULL...\n");
		return;
	}
	else
	{
		Queue[rear] = data;
		rear += 1;
		return;
	}
}

void dequeue()
{
	if (isEmpty())
	{
		printf("QUEUE IS EMPTY...\n");
		return;
	}
	else
	{
		printf("[DEQUEUE] Queue[%d] : %d\n",front,Queue[front]);
		int i;
		for(i = front ; i < rear ; i++)
		{
			Queue[i] = Queue[i+1];
		}
		rear -= 1;
		return;
	}
}

void print()
{
	int i;
	for(i = front ; i < rear ; i++)
	{
		printf("[PRINT] Queue[%d] : %d\n",i,Queue[i]);
	}
}

int main()
{
	queue(1);
	queue(2);
	queue(3);
	dequeue();
	print();
	return SUCCESS;
}
