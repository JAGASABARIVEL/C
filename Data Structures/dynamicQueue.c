#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0

/*

	==========================================================
	 -------	 -------	 -------	 -------
	| data	|	| data	|	| data	|	| data	|
	|	|	|	|	|	|	|	|
	| 1004	|	| 1008	|	| 1012	|	| NULL	|
	 -------	 -------	 -------	 -------
	  1000		  1004		  1008		  1012
	==========================================================
				Queue

	 -------	 -------
	| 1000	|	| 1012	|
	|	|	|	|
	 -------	 -------
	  Front		   Rear
*/

struct node
{
	int data;
	struct node* link_address;
};

struct node* front = NULL;
struct node* rear = NULL;


void queue(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (rear == NULL)
	{
		front =temp;
		rear = temp;
		//printf("[QUEUE] fron : %p\n",front);
	}
	else
	{
		rear->link_address = temp;
		rear = temp;
	}
}

void dequeue()
{
	printf("[DEQUEUE] deQueue[%p] : %d\n",front,front->data);
	front = front->link_address;
}

void print()
{
	struct node* temp = front;
	//printf("[PRINT] temp : %p\n",temp);
	while(temp->link_address != NULL)
	{
		printf("[PRINT] Queue[%p] : %d\n",temp,temp->data);
		temp = temp->link_address;
	}
	printf("[PRINT] Queue[%p] : %d\n",temp,temp->data);
}

void length()
{
	struct node* temp;
	int len;
	temp = front;
	while(temp->link_address != NULL)
	{
		len += 1;
		temp = temp->link_address;
	}
	len += 1;	// For considering the last node which has the link_address as NULL
	printf("Length of queue : %d\n",len);
}

int main()
{
	queue(1);
	queue(2);
	print();
	printf("Going to dequeue the above queue...\n");
	dequeue();
	print();
	length();
	return SUCCESS;
}
