
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>

void *worker(void *arg)
{
    int *arr= (int *)arg;
    printf("\nEntering the Thread");
    int n = 0;
    int flag = 0;

    printf("\nThe array is: ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        n = arr[i];
        for (int j = 0; j < 10; j++)
        {
            if (n == arr[j])
                flag++;
        }
        if (flag == 2)
        {
            printf("\n\nThe entry repeated twice is: %d", n);
        }
        flag = 0;
    }
}

int main()
{

    int arr[10];
    printf("\nPlease enter the input: ");
    int n = 0;

    for (int i = 0; i < 10;)
    {
        scanf("%d", &n);
        if (n > 0 && n < 10)
        {
            arr[i] = n;
            i++;
        }
    }

    printf("\nThe array is: ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", arr[i]);
    }

    pthread_t p1;
    pthread_create(&p1, NULL, worker, (void *)arr);
    pthread_join(p1, NULL);
}