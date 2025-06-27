#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>
#include <sys/wait.h>
#define size 5
using namespace std;

int main()
{
cout<<"\nEnter the Array: ";
int*arr=new int[size];

for(int i=0;i<size;i++)
{
cin>>arr[i];
} 

int fd[2];
pipe(fd);
int fd2[2];
pipe(fd2);
int pid=fork();

if(pid>1)
{
cout<<"\nIn Parent Process\n";
write(fd[1],&arr,size);
wait(NULL);
int ans=0;
read(fd2[0],&ans,sizeof(int));
cout<<"\nThe final sum is: "<<ans;

}
else
{
cout<<"\nIn Child Process\n";
int sum=0;
for(int i=0;i<size;i++)
{
sum=sum+arr[i];
}

write(fd2[1],&sum,sizeof(int));
}

return 0;
}
