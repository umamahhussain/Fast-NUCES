#include <iostream>
using namespace std;
#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include <string.h>

int main()
{
    char* buffer;

    int semaphore1 = shmget(990, 1024, 0);
    int semaphore2 = shmget(991, 1024, 0);
    int CS_id = shmget(992, 1024, 0);

    sem_t* sem1;
    sem_t* sem2;

    if (semaphore1 == -1 || semaphore2 == -1 || CS_id == -1)
    {
        cout << "ERROR!" << endl;
        return 1;
    }
    sem1 = (sem_t*)shmat(semaphore1, NULL, 0);
    sem2 = (sem_t*)shmat(semaphore2, NULL, 0);

    buffer = (char*)shmat(CS_id, NULL, 0);
    
    bool flag = false;
    while (1)
    {
        sem_wait(sem2);
        sem_wait(sem1);
        for (int i = 0; i < 20; i++)
        {
            if (buffer[i] != '$')
                cout << buffer[i] << endl;
            else
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;

        sem_post(sem1);
        sem_post(sem2);
    }

    shmdt(sem1);
    shmdt(sem2);
    shmdt(buffer);
    return 0;
}
