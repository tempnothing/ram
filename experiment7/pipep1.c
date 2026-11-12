#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
 
int main() {
    int p[2];
    char msg[] = "Hello Child";
    char buf[100];
 
    pipe(p);
    pid_t pid = fork();
 
    if (pid > 0) {
        close(p[0]);
        write(p[1], msg, strlen(msg) + 1);
        close(p[1]);
        wait(NULL);
    } else {
        close(p[1]);
        read(p[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(p[0]);
    }
 
    return 0;
}
