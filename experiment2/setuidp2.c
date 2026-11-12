#include <stdio.h>
#include <unistd.h>
 
int main()
{
    printf("Before: %d\n", getuid());
 
    if (setuid(1000) == 0)
        printf("User ID changed successfully\n");
    else
        perror("setuid");
 
    printf("After: %d\n", getuid());
 
    return 0;
}
