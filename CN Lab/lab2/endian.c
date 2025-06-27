#include <stdio.h>

int main()
{
	short number = 0x1234;
	char *address = (char*) &number;
	
	if (*address== 0x34)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
		
	return 0;
}
