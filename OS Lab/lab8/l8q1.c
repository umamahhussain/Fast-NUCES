#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int f = 0;
    char arr[20];
    f = open("1.txt", O_RDWR);
    lseek(f, 0, SEEK_CUR);
    read(f, arr, 10);

    dup2(f,1);
    printf("\nI am being printed thru dup2 woohoo");
}