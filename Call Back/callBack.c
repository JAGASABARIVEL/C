#include<stdio.h>

#define SUCCESS 0

void calculator(int* call_back(int,int),int a,int b)
{
	int Value = call_back(a,b);
	printf("Value : %ld\n",Value);
}

int* add(int a,int b)
{
	return a+b;
}

int* sub(int a,int b)
{
	return a-b;
}

int main()
{
	calculator(add,1,2);
	return SUCCESS;
}
