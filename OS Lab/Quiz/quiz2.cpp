#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char*argv[])
{

string str=argv[1];
cout<<"\nThe name is: "<<str;
int count=0;

for(int i=0;str[i]!='\0';i++)
{
count++;
}

cout<<"\nCount of the name is: "<<count;

return 0;
}
