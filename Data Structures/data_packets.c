#include<stdio.h>

#define SUCCESS 0;

struct packet_template
{
	int data;
	struct packet_template* address;
};

struct packet_template* root = NULL;

void load_packet(int data)
{
	struct packet_template* temp;
	temp = (struct packet_template*)malloc(sizeof(struct packet_template));
	temp->data = data;
	if (root == NULL)
	{
		root = temp;
		printf("SUCCESSFULLY STORED DATA AND ASSIGNED THE TEMP POINTER TO MAIN POINTER\n");
	}
	else
	{
		struct packet_template* traverse_node;
		traverse_node = root;
		while(traverse_node->address != NULL)
		{
			traverse_node = traverse_node->address;
		}
		traverse_node->address = temp;
	}
}

int main()
{
	printf("\nADDRESS OF NODE IN MAIN : %p\n",&root);
	load_packet(2);
	load_packet(4);
	load_packet(6);
	struct packet_template* temp = root;
	while(root!=NULL)
	{
		printf("\nVALUE OF A NODE's REAL DATA    : %d\n",root->data);
		printf("\nVALUE OF A NODE's CONTROL DATA : %p\n",root->address);
		root = root->address;
	}
	return SUCCESS;
}
