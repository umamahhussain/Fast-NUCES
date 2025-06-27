#include <sys/types.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
int fd[2];
pipe(fd);
int fd2[2];
pipe(fd2);

char buf[30];
char buf2[30];
printf("Enter String: ");
scanf("%s",buf);

int pid=fork();

if(pid>0)
{
printf("\nEnter Parent Process\n");
write(fd[1],&buf,30);
wait(NULL);
printf("Back in Parent Process");
char final[30];
read(fd2[0],&final,30);
printf("\nAnswer: %s",final);

}
else
{
printf("\nEnter Child Process\n");
read(fd[0],&buf2,30);
printf("\n%s",buf2);

for(int i=0;buf2[i]!='\0';i++)
{
if(buf2[i]>='a' && buf2[i]<='z')
{
buf2[i]=buf2[i]-32;
}
else
buf2[i]=buf2[i]+32;
}

printf("\nAnswer: %s",buf2);
write(fd2[1],&buf2,30);
printf("\nExitting Child Process\n");
}

printf("\n\n");
return 0;
}
