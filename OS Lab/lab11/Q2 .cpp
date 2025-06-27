

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sys/types.h>

using namespace std;

void *rep(void *map)
{
    char space[2] = {' ', '\0'};

    char *ptr = (char *)map;

    for (int i = 0; i < 50; i++)
    {
        if (ptr[i] >= '0' && ptr[i] <= '9')
        {
            ptr[i] = space[0];
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char *map = (char *)mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    cout << "Contents of file: " << map << std::endl;

    pthread_t p1, p2;
    pthread_create(&p1, NULL, rep, (void *)map);

    pthread_join(p1, NULL);

    cout << "The updated content of  for first half the file is:" << map << endl;

    map = map + 50;
    pthread_create(&p2, NULL, rep, (void *)map);

    pthread_join(p2, NULL);
    cout << endl;
    cout << "The updated content for second half of  file is: " << map << endl;

    munmap(map, 50);
    close(fd);
    return 0;
}
