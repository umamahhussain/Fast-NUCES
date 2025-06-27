#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
int n,f,f1;
int fd[2];
pipe(fd);
int fd2[2];
pipe(fd2);

char buf[15];
char buf2[30];

f=open("lab",O_RDWR);
lseek(f,0,SEEK_CUR);
read(f,buf,15);
write(15,buf,15);

int pid=fork();

if(pid>0)
{
printf("\nEnter Parent Process\n");
write(fd[1],&buf,15);
wait(NULL);
printf("Back in Parent Process");
char final[15];
read(fd2[0],&final,15);
printf("\nAnswer: %s",final);

}
else
{
printf("\nEnter Child Process\n");
read(fd[0],&buf2,15);
printf("\n%s",buf2);

for(int i=0;i<15;i++)
{
if(buf2[i]>='0' && buf2[i]<='9' || buf2[i]>='a' && buf2[i]<='z')
{
continue;
}
else
buf2[i]=' ';
}

write(fd2[1],&buf2,15);
printf("\nExitting Child Process\n");
}


printf("\n\n");
return 0;
}
