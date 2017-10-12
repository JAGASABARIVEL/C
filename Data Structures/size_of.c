#include <stdio.h>
#include "data_types.h"
#define SUCCESS 0


int main()
{
	printf("size of uint8 is : %ld\n",sizeof(uint8));
	uint8 a,b;
	a = 'A';
	b = 257;                                                            // 1 1 1 1 1 1 1 1 = 255
	printf("Value of a : %c\nValue of b : %d\n",a,b);
	printf("SIZE OF 8-BIT VARIABLE(b) THAT STORE AN INTEGER VALUE : %ld\n",sizeof(b));
	return SUCCESS;
}


/* OUTPUT TO UNDERSTAND THE NEGATIVE RANGES FOR AN DATATYPE

===========
SCENARIO 1:
===========
size of uint8 is : 1
Value of a : A
Value of b : -126
SIZE OF 8-BIT VARIABLE(b) THAT STORE AN INTEGER VALUE : 1

===========
SCENARIO 2:
===========
If we give an value more than 8-bit then we will be shown an warning of memory overflow to store the value and it will continue to store the value in the cycling range.

So it will be good to use only half of the bytes to store an integer value in char datatype and probably same for other datatyper too!!

check it out :)

size_of.c: In function ‘main’:
size_of.c:11:6: warning: overflow in implicit constant conversion [-Woverflow]
  b = 256;                                                            // 1 1 1 1 1 1 1 1 = 255
      ^
jaga@jaga-VirtualBox:~/Desktop/C-CODING-GROUND$ ./size_of.o 
size of uint8 is : 1
Value of a : A
Value of b : 0
SIZE OF 8-BIT VARIABLE(b) THAT STORE AN INTEGER VALUE : 1

*/
