
#include<stdio.h>

#define SUCCESS 0;

void wrapper(char*,int);
void set_customized(char*);
int __init__0(char*);

void wrapper(char* wrapper_pointer,int select)
{
	printf("\n[wrapper] | ADDRESS OF THE POINTER NOW : %p\n",wrapper_pointer);
	//printf("\n[wrapper] | ADDRESS OF THE POINTER NOW : %p\n",&WRAPPER_TEXT);
        int index = 0;
        if (select == 0)
        {
                printf("TYPE : [DEBUG] | FUNCTION : [wrapper] | Inside select == 0\n");
                printf("*******************************************************************************************************\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                  WELCOME TO DISTRIBUTED OSY MANAGEMENT CONSOLE                                      *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*******************************************************************************************************\n");
        }
        else
        {
                set_customized_wrapper(wrapper_pointer);
                printf("*******************************************************************************************************\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
		printf("*                        \n");
		
                for(index = 0;wrapper_pointer[index] != '\0';index++)
                {
                        printf("%c",wrapper_pointer[index]);
                }
		printf("                        *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*                                                                                                     *\n");
                printf("*******************************************************************************************************\n");
        }
}

void set_customized_wrapper(char* wrapper_pointer)
{
	printf("\n[set_customized] | ADDRESS OF THE POINTER NOW : %p\n",wrapper_pointer);
	//printf("\n[set_customized] | ADDRESS OF THE POINTER NOW : %p\n",WRAPPER_TEXT);
        char text[100];
        int index = 0;
        printf("PLEASE ENTER THE TEXT THAT YOU WANT TO DISPLAY IT ON THE WRAPPER\n");
	scanf("%s",text);	

        //scanf("%c",&text);
        //printf("TYPE : [DEBUG] | FUNCTION : [set_customized_wrapper] %s\n",text);
      
        //*WRAPPER_TEXT = text;


	//if(WRAPPER_TEXT == wrapper_pointer)
	//{
	//	printf("pointer and the global variable are the same\n");
	//}

	for(index = 0;text[index] != '\0';index++)
	{
		*(wrapper_pointer + index) = text[index];
		//	printf("%c\n",WRAPPER_TEXT[index]);	
	}
	*(wrapper_pointer + index) = '\0';
}

int __init__0(char* wrapper_pointer)
{
	printf("\n[__init__0] | ADDRESS OF THE POINTER NOW : %p\n",wrapper_pointer);
	//printf("\n[__init__0] | ADDRESS OF THE POINTER NOW : %p\n",WRAPPER_TEXT);
        char select;
        printf("PLEASE LET US KNOW IF YOU NEED TO CUSTOMIZE THE DEFAULT WRAPPER OF THE MANAGEMENT CONSOLE(Y/N)\n");
        scanf("%c",&select);
        printf("TYPE : [DEBUG] | FUNCTION : [__init__0] %c\n",select);
        if(select == 'Y')
        {
                wrapper(wrapper_pointer,1);
                //printf("TYPE : [DEBUG] | FUNCTION : [__init__0] 1\n");
        }
        if(select == 'N')
        {
                wrapper(wrapper_pointer,0);
                //printf("TYPE : [DEBUG] | FUNCTION : [__init__0] 0\n");
        }
        return SUCCESS;
}

int main()
{
        char WRAPPER_TEXT[100];
        char* wrapper_text;
	printf("\n[main()] | ADDRESS OF THE POINTER NOW : %p\n",&WRAPPER_TEXT);
        __init__0(WRAPPER_TEXT);
        return SUCCESS;
}

