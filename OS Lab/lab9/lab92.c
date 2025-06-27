#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 1234
#define BUFFER_SIZE 4096
#define SIZE 256

int main(int argc, char* argv[]) 
{
    int id;
    char* cpy;
    char* output;
  
    id = shmget(KEY, BUFFER_SIZE, IPC_CREAT | 0666);
    if (id < 0) {
        printf("SHMGET FAILED");
        return 2;
    }

    
    cpy = shmat(id, NULL, 0);
    if (cpy == (char*) -1) {
        printf("SHMAT FAILED");
        return 3;
    }

    output = (char*) malloc(SIZE * sizeof(char));
    strncpy(output, cpy, SIZE-1);
    output[SIZE-1] = '\0';

    int count = 0;
    int buffer[SIZE];
    for(int i=0; output[i] >= '0' && output[i] <= '9'; i++) {
        buffer[i] = (int) output[i] - '0';
        count++;
    }
    
    printf("Count: %d\n", count);
    
    for (int i = 0; i < count; i++) 
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    
    int sum=0;
    
    for(int i=0;i<count;i++)
    {
    sum=sum+buffer[i];
    }
    
    printf("Sum = %d \n",sum);
    float avg=sum/count;
    printf("Average = %f \n",avg);

  
    if (shmdt(cpy) == -1) {
        printf("SHMDT FAILED");
        return 3;
    }

    return 0;
}
