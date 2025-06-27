#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{

int sum=0;
int i=1;

for(;i<argc;i++)
{
int a=atoi(argv[i]);
sum=sum+a;

}

printf("\nThe Sum is: %d",sum);

int av=sum/(argc-1);
printf("\nThe Average is: %d",av);


return 0;

}
