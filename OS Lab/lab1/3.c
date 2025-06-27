#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char*argv[])
{

FILE* f1;
FILE* f2;
char c;

f1=fopen(argv[1],"r");
f2=fopen(argv[2],"w");

if(f1==NULL)
{
printf("\nCan not open file");
}
else
{
printf("\nReading the contents of the file:\n");
do
{
c=fgetc(f1);

if(c>='0' && c<='9')
fputc(c,f2);

}
while(c!=EOF);

}


return 0;

}
