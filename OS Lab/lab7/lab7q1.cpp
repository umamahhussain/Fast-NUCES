#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
int N=5;

void* worker(void* arg )
{
cout<<"\nEntering the Thread\n";
printf("This is worker thread #%ld\n",(long)arg);

pthread_exit(NULL);
}



int main()
{

pthread_t p1[N];
long id;

for(id=1;id<=N;id++)
{
pthread_create(&p1[id],NULL,worker,(void*)id);
sleep(1);
}

return 0;
}

