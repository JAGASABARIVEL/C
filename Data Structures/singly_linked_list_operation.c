#include<stdio.h>

#define SUCCESS 0

/*

		----------------	 ----------------
	 ----->	|address| data  |  <---	| NULL	| data	|
	|	----------------	 ----------------
	|	    last insert		    New Node
	|
      root
*/

struct node
{
	int data;
	struct node* address;
};

struct node* root = NULL;

void append(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (root == NULL)
	{
		root = temp;				// Fresh node with link->address = NULL
	}
	else
	{
		struct node* link_address;
		link_address = root;			// The fresh node's address that created was assigned to a temporary pointer.
		while(link_address->address != NULL)
		{
			link_address = link_address->address;
		}
		link_address->address = temp;
	}
}

void delete(int data)
{
	struct node* temp;
	struct node* previous_node;
	int flag = 0;
	temp = root;
	while(temp != NULL)
	{
		if(flag == 1)
		{
			previous_node->address = temp;
			//printf()
			break;
		}
		else
		{
			if (temp->data == data)
			{
				printf("Found the data %d at address %p with the link address %p \n",data,temp,temp->address);
				flag = 1;
				printf("Now root points to : %p \nNow temp points to : %p\n",root,temp);
				if(temp == root)
				{	
					printf("Found the data is present at root node %p",root);
					root = temp->address;
					break;
				}
				else
				{
					temp = temp->address;
					if(temp == NULL)
					{
						previous_node->address = NULL;
						break;
					}
					continue;
				}
			}
			else
			{
				printf("continuing to search %d...\n",data);
			}
			//previous_node = temp;
		}
		previous_node = temp;
		temp = temp->address;
	}
	
}

void print()
{
	struct node* temp;
	temp = root;
	while(temp != NULL)
	{
		printf("\n Nodes address      : %p",temp);
		printf("\n Nodes link address : %p\n",temp->address);
		printf(" \n Node's data       : %d\n",temp->data);
		temp = temp->address;
	}
	return SUCCESS;
}
int main()
{
	append(1);
	append(2);
	append(3);
	append(4);
	print();
	delete(1);
	delete(4);
	//delete(1);
	printf("After deleteing 4 and 1 the linked list will look like...\n");
	print();
	return SUCCESS;
}
