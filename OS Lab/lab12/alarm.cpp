
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <iostream>
#include <chrono>
#include <sys/wait.h>
using namespace std;
clock_t now1;
clock_t now2;
int now22;

void signalhandler(int sig)
{
    if (sig == SIGCHLD)
    {
        cout<<"\nReceived SIGCHLD\n";
    }
    cout<<"\nTotal Time in Seconds: "<<now22;
}

int main()
{

    clock_t now = clock();
    int pid = fork();

    if (pid > 0)
    {
        cout << "\nParent Process Started\n";
        wait(NULL);
        if(signal(SIGCHLD,signalhandler)==SIG_ERR)
        {
            cout<<"\nCould not catch signal\n";
        }
        float ans = now2 - now;
    }
    else if (pid == 0)
    {
        cout << "\nChild Process Started\n";
        cout << "\nEnter lap seconds: ";
        int lappy = 0;
        cin >> lappy;

        int lappynum = 0;
        cout << "\nEnter Lap Number: ";
        cin >> lappynum;
        int i = 1;

        while (i <= lappynum)
        {
            sleep(lappy);
            cout << "\nLap " << i << " completed";
            i++;
        }
        now22 = lappynum * lappy;
        now2 = clock();
        if(signal(SIGCHLD,signalhandler)==SIG_ERR)
        {
            cout<<"\nCould not catch signal\n";
        }
        signalhandler(SIGCHLD);

    }
}