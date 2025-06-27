#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
int num;

void* sum(void* )
{
cout<<"\nEntering the Thread\n";

cout<<"\nEnter the Number you want to calculate sum of: ";
cin>>num;

int sum=0;
while(num>=0)
{
sum=sum+num;
num--;
}

cout<<"\nThe sum is: "<<sum;

pthread_exit(NULL);
}



int main()
{

pthread_t p1;
pthread_create(&p1,NULL,sum,NULL);
pthread_join(p1,NULL);

return 0;
}

