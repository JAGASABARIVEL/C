#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0

/*

	==========================================================
	 -------	 -------	 -------	 -------
	| data	|	| data	|	| data	|	| data	|
	|	|	|	|	|	|	|	|
	| 1004	|	| 1008	|	| 1012	|	| 1000	|
	 -------	 -------	 -------	 -------
	  1000		  1004		  1008		  1012
	==========================================================

	
		 -------
		|	|
   root	 ---->  | 1000	|
		|	|
		 -------


*/

struct node
{
	int data;
	struct node* link_address;
};

struct node* root = NULL;
struct node* _root = NULL;

void insert(int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	if (root == NULL)
	{
		root = temp;
		_root = temp;
	}
	else
	{
		struct node* temp_link;
		temp_link = root;
		if (temp_link->link_address == NULL)
		{
			_root->link_address = temp;
			temp->link_address = _root;
			root = temp;
		}
		else
		{
			while (temp_link->link_address != _root)
			{
				temp_link = temp_link->link_address;
			}
			temp_link->link_address = temp;
			temp->link_address = _root;
			root = temp;
		}	
	}
}

void print()
{
	struct node* temp;
	temp = _root;
	printf("[PRINT] root : %p\n",_root);
	while (temp->link_address != _root)
	{
		printf("[PRINT-INSIDE] cLL[%p] : %d\n",temp,temp->data);
		temp = temp->link_address;	
	}
	printf("[PRINT-OUTSIDE] cLL[%p] : %d\n",temp,temp->data);
}

int main()
{
	insert(1);
	insert(2);
	insert(3);
	print();
	return SUCCESS;
}
