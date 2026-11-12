#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
 
struct message {
    long type;
    char text[100];
};
 
int main() {
    int id = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);
    struct message m;
 
    pid_t pid = fork();
 
    if (pid > 0) {
        m.type = 1;
        strcpy(m.text, "Hello Child");
 
        msgsnd(id, &m, sizeof(m.text), 0);
        wait(NULL);
        msgctl(id, IPC_RMID, NULL);
    } else {
        msgrcv(id, &m, sizeof(m.text), 1, 0);
        printf("Child received: %s\n", m.text);
    }
 
    return 0;
}
