#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>

int main()
{
    FILE* file;
    FILE* f2;
    int start=0;
    int temp=0;
    int tempend=0;
    int end=0;

    char arr[30];
    file=fopen("input.txt","r");
    f2=fopen("new4.txt","w");
    fgets(arr,30,file);


    for(int i=0;i<strlen(arr);i++)
    {
        if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u')
        {
        while(arr[i+1]!=' ')
        {
            i++;
        }

         end=i;
         tempend=end;
         while(start<=end)
        {            
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
         }

         start=tempend+2;
            
        }
        else
            continue;
     }


 printf("Modified array is: %s",arr);
 fprintf(f2,"%s",arr);
 }

           