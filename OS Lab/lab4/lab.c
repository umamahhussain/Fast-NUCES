#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
int n,f,f1;

char buf[15];
f=open("lab",O_RDWR);

for(int i=1;i<5;i++)
{
lseek(f,i,SEEK_CUR);
read(f,buf,1);
write(1,buf,15);
}

printf("\n\n");
return 0;
}
