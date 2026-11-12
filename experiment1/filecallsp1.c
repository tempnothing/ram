#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
int main()
{
    int fd, n;
    char text[] = "Hello from OS Lab";
    char buffer[100];
 
    fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, text, strlen(text));
    lseek(fd, 0, SEEK_SET);
    n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("File content: %s\n", buffer);
    close(fd);
 
    return 0;
}
