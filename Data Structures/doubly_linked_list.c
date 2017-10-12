#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0

/*
		----------------------------	 	-------------------------------
	 ----->	|NULL| data  |address    |	<---	| address	| data	|NULL  |
	|	----------------------------	 	-------------------------------
	|	    last insert		    	   		New Node
	|
      root	

*/

struct node
{
	int data;
	struct node* link_address_previous;
	struct node* link_address_next;
};

struct node* root = NULL;

int insert(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node* temp_previous;
		temp_previous = root;
		while(temp_previous->link_address_next != NULL)
		{
			temp_previous = temp_previous->link_address_next;
		}
		temp_previous->link_address_next = temp;
		temp->link_address_previous = temp_previous;
		//temp->link_address_next = root;
	}
}

void print()
{
	struct node* temp;
	temp = root;
	while(temp != NULL)
	{
		printf("NOde's data 		            : %d\n",temp->data);
		printf("NOde's link of previous address     : %p\n",temp->link_address_previous);
		printf("Node's link of next address         : %p\n",temp->link_address_next);
		printf("Node's address 		            : %p\n",temp);
		temp = temp->link_address_next;
	}
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	print();
	return SUCCESS;
}
