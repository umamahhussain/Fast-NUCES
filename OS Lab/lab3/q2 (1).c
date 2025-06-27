#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{

if (fork()== 0)
{
printf("\nHello from child\n");

FILE* f=fopen("f.txt","r");
char c;

do
{
c=fgetc(f);
if(c==',' || c=='.'||c==';' || c==':')
{
printf("\n%c",c);
}

}
while(c!=EOF);

}


else
{
printf("\nHello from parent\n");
wait(NULL);
printf("\nChild has terminated\n");
}
printf("\nBye\n");
return 0;
}
