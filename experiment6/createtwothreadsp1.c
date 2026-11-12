#include <stdio.h>
#include <pthread.h>
 
void *function(void *arg)
{
    printf("Thread is executing\n");
 
    for(int i = 1; i <= 5; i++)
        printf("%d\n", i);
 
    return NULL;
}
 
int main()
{
    pthread_t t1, t2;
 
    pthread_create(&t1, NULL, function, NULL);
    pthread_create(&t2, NULL, function, NULL);
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 
    printf("Both threads completed\n");
 
    return 0;
}
