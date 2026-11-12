#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main()
{
    int pid = fork();
 
    if (pid == 0)
        printf("Child Process: %d\n", getpid());
    else
    {
        wait(NULL);
        printf("Parent Process: %d\n", getpid());
    }
 
    return 0;
}
