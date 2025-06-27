#include <iostream>
using namespace std;
#include <fstream>
#include <semaphore.h>
#include <sys/shm.h>
#include <queue>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "File name not provided!" << endl;
        return 1;
    }
    char* buffer;

    int semaphore1 = shmget(990, 1024, 0666 | IPC_CREAT | IPC_EXCL);
    int semaphore2 = shmget(991, 1024, 0666 | IPC_CREAT | IPC_EXCL);
    int CS_id = shmget(992, 1024, 0666 | IPC_CREAT | IPC_EXCL);
    
    sem_t* sem1;
    sem_t* sem2;
    if (semaphore1 == -1 || semaphore2 == -1 || CS_id == 1)
    {
        cout << "ERROR!" << endl;       
        return 1;
    }
    

    sem1 = (sem_t*)shmat(semaphore1, NULL, 0);
    sem2 = (sem_t*)shmat(semaphore2, NULL, 0);
    buffer = (char*)shmat(CS_id, NULL, 0);

    sem_init(sem2, 1, 0); 
    sem_init(sem1, 1, 1); //1 means semaphore is used for process synchronization
    ifstream fin(argv[1]);
    if (!fin.is_open())
    {
        cout << "Cannot open file" << endl;
        return 1;
    }
    char c;

    while (1)
    {
        sem_post(sem2);
        sem_wait(sem1);
        if (fin.eof())
        {
            fin.close();
            buffer[0] = '$';
            break;
        }

        for (int i = 0; i < 20 && !fin.eof(); i++)
        {
            fin >> c;
            buffer[i] = c;
        }
        sem_post(sem1);
        sem_wait(sem2);
    }



    sem_destroy(sem1);
    shmdt(sem2);
    sem_destroy(sem2);
    shmdt(sem1);
    shmdt(buffer);
    shmctl(semaphore1, IPC_RMID, NULL);
    shmctl(semaphore2, IPC_RMID, NULL);
    shmctl(CS_id, IPC_RMID, NULL);
    return 0;
}
