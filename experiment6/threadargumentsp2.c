#include <stdio.h>
#include <pthread.h>
 
void *function(void *arg)
{
    int num = *(int *)arg;
 
    printf("Thread %d is executing\n", num);
 
    for(int i = 1; i <= 5; i++)
        printf("Thread %d: %d\n", num, i);
 
    return NULL;
}
 
int main()
{
    pthread_t t1, t2;
    int a = 1, b = 2;
 
    pthread_create(&t1, NULL, function, &a);
    pthread_create(&t2, NULL, function, &b);
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 
    printf("Both threads completed\n");
 
    return 0;
}
