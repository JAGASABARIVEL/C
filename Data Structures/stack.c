#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define SUCCESS 0
#define MAX_SIZE 5
int top = -1;
int stack[MAX_SIZE];

int isFull()
{
	if(top == MAX_SIZE-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int data)
{
	if(isFull())
	{
		printf("STACK IS FULL...\n");
		return;
	}
	else
	{
		printf("Pushing...\n");
		top += 1;
		stack[top] = data;
		printf("[PUSH] top = %d\n",top);
	}
}

void pop()
{
	if(isEmpty())
	{
		printf("STACK IS EMPTY...\n");
		return;
	}
	else
	{
		printf("Popping...\n");
		printf("[POP] stack[%d] : %d\n",top,stack[top]);
		stack[top] = 0;
		top -= 1;
		printf("[POP] top = %d\n",top);	
	}
}

void print()
{
	int i;
	for(i=top;i >= 0;i--)
	{
		printf("[PRINT] stack[%d] : %d\n",i,stack[i]);
	}
}

void switchCase(int choice,bool* __choice)
{
	printf("Address choice pointing to choice -> %p\n",__choice);
	int data;
	switch(choice)
	{
		case 1:
			printf("Enter the data you want to push to stack...\n");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			print();
			break;
		case 0:
			printf("Cleaning up and exiting...\n");
			break;
		default:
			printf("Invalid choice...\n");
			*__choice = 0;
			break;
	}
}

int main()
{
	bool* choice= (bool*)malloc(sizeof(bool));
	*choice = 1;
	int* _choice = (int*)malloc(sizeof(int));
	while(*choice != 0)
	{
		printf("Please select the option for an appropriate stack operation you want to perform...\n");
		printf("\t1. PUSH \n");
		printf("\t2. POP \n");
		printf("\t3. PRINT \n");
		printf("\t0. QUIT \n");
		scanf("%d",_choice);
		*choice = *_choice;
		printf("Address choice pointing to choice -> %p\n",choice);
		printf("Value of choice pointing to choice -> %d\n",*choice);
		switchCase(*_choice,choice);
	}
	free(_choice);
	return SUCCESS;
}
