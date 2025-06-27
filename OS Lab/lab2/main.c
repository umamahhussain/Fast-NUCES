#include <stdio.h>
#include <string.h>

int main(int argc, char* arg[])
{

int size=argc-3;
int temp[size];
int option=0;
int i=0;
int j=3;

while(i<size)
{
temp[i]=atoi(arg[j]);
i++;
j++;
}

while(option!=-1)
{
printf("\n1.)Enter 1 for sorting\n2.)Enter 2 for highest\n3.)Enter 3 for display\n");
scanf("%d",&option);

if(option==1)
{
if(arg[1]==0)
{
sort(0,temp,10);
}
else
sort(1,temp,10);
}

if(option==2)
{
;
}

if(option==3)
{
print(temp,10);
}

}







return 0;
}
