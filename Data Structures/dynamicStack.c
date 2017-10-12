#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0

/*
		 -------
		|	|      top
		 -------		
		    |
		    |
		
		|	|
		|  	|
		 -------
		|	|
		|	|
		 -------
		|	|
		|	|
		 -------
		|	|
		|	|
		 -------

*/

struct node
{
	int data;
	struct node* link_address;
};

struct node* top = NULL;

void push(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (top == NULL)
	{
		printf("[PUSH] stack[%p] : %d\n",temp,temp->data);
		temp->link_address = NULL;
		top = temp;
	}
	else
	{
		printf("[PUSH] stack[%p] : %d\n",temp,temp->data);
		temp->link_address = top;
		top = temp;
	}
}

void pop()
{
	struct node* temp;
	temp = top;
	printf("[POP] stack[%p] : %d\n",temp,temp->data);
	top = temp->link_address;
}

void print()
{
	struct node* temp = top;
	if (temp != NULL)
	{
		while(temp->link_address != NULL)
		{
			printf("stack[%p] : %d\n",temp,temp->data);
			temp = temp->link_address;
		}
		printf("stack[%p] : %d\n",temp,temp->data);
	}
	else
	{
		printf("STACK IS EMPTY...\n");
	}
}

int main()
{
	push(1);
	push(2);
	pop();
	pop();
	print();
	
	return SUCCESS;
}
