#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
 
int main() {
    int id = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *p = (char *)shmat(id, NULL, 0);
 
    strcpy(p, "Hello Child");
 
    pid_t pid = fork();
 
    if (pid == 0) {
        printf("Child received: %s\n", p);
    } else {
        wait(NULL);
        shmdt(p);
        shmctl(id, IPC_RMID, NULL);
    }
 
    return 0;
}
