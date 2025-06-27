#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE* file;
    char arr[50];
    file=fopen("input.txt","r");
    fscanf(file,"%s",arr);
    printf(arr,"%s");

}