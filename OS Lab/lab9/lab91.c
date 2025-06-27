#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>

#define KEY 1234
#define BUFFER_SIZE 4096


int main(int argc, char* argv[])
{
    int id;
    int count;
    int unlink;
    int* arr;
    int *cpy;
    int file; 

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    file = open(argv[1], O_RDONLY);
    if (file == -1) {
        perror("open");
        return 2;
    }

int size=0;
size = lseek(file, 0, SEEK_END);
    arr = malloc(size);

    lseek(file, 0, SEEK_SET);

    read(file, arr, size);
   
    close(file);

    id = shmget(KEY, BUFFER_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if (id == -1) {
        perror("shmget");
        return 3;
    }

    cpy = shmat(id, NULL, 0);
    if (cpy == (void*)-1) {
        perror("shmat");
        return 3;
    }

    char *one = (char *)arr;
    char *two = (char *)cpy;

    strncpy(two, one, size-1);
  
    sleep(10);
    
    shmctl(id, IPC_RMID, NULL);

    if (shmdt(cpy) == -1) {
        printf("SHMDT FAILED");
        return 3;
    }


    return 0;
}















