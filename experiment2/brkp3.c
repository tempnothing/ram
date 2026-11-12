#include <stdio.h>
#include <unistd.h>
 
int main()
{
    void *old = sbrk(0);
 
    printf("Before: %p\n", old);
 
    brk(old + 1024);
 
    printf("After: %p\n", sbrk(0));
 
    return 0;
}
