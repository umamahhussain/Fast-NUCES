#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE* file;
    FILE* f2;

    char arr[30];
    file=fopen("input.txt","r");
    f2=fopen("new3.txt","w");

    fgets(arr,30,file);
    printf("%s",arr);

    for(int i=0;arr[i]!='\0';i++)
    {
        if(arr[i]>='a' && arr[i]<='z' || arr[i]>='A' && arr[i]<='Z')
        {
            while(arr[i]!=' ')
            {
            i++;
            }
        }
        else
        {
            fprintf(f2,"%c",arr[i]);
        }
    }

}