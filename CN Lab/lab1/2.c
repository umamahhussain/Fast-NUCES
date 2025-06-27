#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE* file;
    FILE* f2;

    char arr[20];
    file=fopen("input.txt","r");
    f2=fopen("new.txt","w");

    fscanf(file,"%s",arr);

    for(int i=0;i<20;i++)
    {
        if(arr[i]>='a' && arr[i]<='z' || arr[i]>='A' && arr[i]<='Z')
        continue;
        else 
        fprintf(f2,"%c",arr[i]);
    }

}