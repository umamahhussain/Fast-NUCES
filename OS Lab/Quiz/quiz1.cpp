#include <iostream>
using namespace std;
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

int arr[5][5]={500, 200, 12, 13, 15,140, 15, 160, 170, 20,20, 40, 700, 1000, 11,10, 20, 20, 20, 20,20, 10, 12, 10, 1000};

pid_t p1 = fork();

if( p1 == 0 ) //child
{
int arr2[25];
int k=0;

for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
arr2[k]=arr[i][j];
k++;
}
}

int count=0;
int num=0;

int bpid=0;
bpid=getpid();
int pid=getppid();

cout<<"\nI am child having ID: "<<bpid;
cout<<"\nMy parent has ID: "<<pid<<endl;
int temp=0;

for(int i=0;i<25;i++)
cout<<arr2[i]<<" ";

for(int i=0;i<25;i++)
{
for(int j=0;j<25;j++)
{
if(arr2[i]==arr2[j])
{
count++;
temp=arr2[i];
}
}
cout<<"\nThe frequency of num "<<temp<<" is: "<<count;
count=0;
}
}

else //parent
{
wait(NULL);

int num=getpid();
cout<<"\nParent has been entered and my ID is: \n"<<num;
int n=5;
int lowsum=0;
int j=0;

for(int row=0; row<n; row++)
{
  for(int col=0; col<5; col++)
  {
     if(col<row)
     {
      lowsum += arr[row][col];
  }
}
}
cout<<"\nThe sum of lower triangle is: "<<lowsum;
}



}








