#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
int num;

void* fibo(void* )
{
cout<<"\nEntering the Thread\n";
cout<<"Thread ID: "<<pthread_self()<<endl;
fstream f;
f.open("fibo.txt",ios::app);

int i=0;
int fib=0;
int term1=0;
int term2=0;

while(i<num)
{
if(i==0)
{
fib=0;
f<<fib<<" ";
}
else
if(i==1)
{
fib=1;
f<<fib<<" ";
term2=fib;
}
else
{
fib=term1+term2;
term1=term2;
term2=fib;
f<<fib<<" ";
}
cout<<fib<<" ";
i++;
}

f.close();

pthread_exit(NULL);
}

void*even(void*)
{
cout<<"\nEntering the Even Thread\n";
cout<<"Thread ID: "<<pthread_self()<<endl;

fstream f;
f.open("fibo.txt",ios::in);
int array[num];
int i=0;
int x=0;

while(i<num && f>>x)
{
array[i]=x;
i++;
}

int count=0;

for(int i=0;i<num;i++)
{
if(array[i]%2==0)
{
cout<<array[i]<<" ";
count++;
}
}

cout<<"\nThe Count of even numbers is: "<<count;
pthread_exit(NULL);
}

void*odd(void*)
{
cout<<"\nEntering the Odd Thread\n";
cout<<"Thread ID: "<<pthread_self()<<endl;

fstream f;
f.open("fibo.txt",ios::in);
int array[num];
int i=0;
int x=0;

while(i<num && f>>x)
{
array[i]=x;
i++;
}

int count=0;

for(int i=0;i<num;i++)
{
if(array[i]%2!=0)
{
cout<<array[i]<<" ";
count++;
}
}

cout<<"\nThe Count of odd numbers is: "<<count;
pthread_exit(NULL);
}



void* sum(void* )
{
cout<<"\nEntering the Sum Thread\n";
cout<<"Thread ID: "<<pthread_self()<<endl;

fstream f;
f.open("fibo.txt",ios::in);
int array[num];
int i=0;
int x=0;

while(i<num && f>>x)
{
array[i]=x;
i++;
}

int sum=0;

for(int i=0;i<num;i++)
{
sum=sum+array[i];
}

cout<<"\nThe sum is: "<<sum;

fstream f2;
f2.open("sum.txt",ios::app);
f2>>sum;


pthread_exit(NULL);
}











int main()
{

cout<<"\nEnter the Number you want to calculate series of: ";
cin>>num;

cout<<"\n*************************************************\n";
pthread_t p1;
pthread_create(&p1,NULL,fibo,NULL);
pthread_join(p1,NULL);

cout<<"\n*************************************************\n";
pthread_t p2;
pthread_create(&p2,NULL,even,NULL);
pthread_join(p2,NULL);

cout<<"\n*************************************************\n";
pthread_t p3;
pthread_create(&p3,NULL,odd,NULL);
pthread_join(p3,NULL);

cout<<"\n*************************************************\n";
pthread_t p4;
pthread_create(&p4,NULL,sum,NULL);
pthread_join(p4,NULL);



return 0;
}

