#include <stdio.h>
#include <string.h>

void sort(int order, int array[],int size)
{
int i=0;
int j=i+1;

for(;i<size-1;i++)
{
for(;j<size;j++)
{

if(order==0) //ascending order
{
if(array[j]<array[i])
{
int temp=array[j];
array[j]=array[i];
array[i]=temp;
}
}

if(order==1) //descending order
{
if(array[j]>array[i])
{
int temp=array[j];
array[j]=array[i];
array[i]=temp;
}
}
}
}
}

void findhighest(int pos, int array[])
{
sort(1,array,10);
printf("\nThe highest element is: %d",array[pos]);

}





void print(int array[],int size)
{
int i=0;
for(;i<size;i++)
{
printf(" %d",array[i]);
}

}
