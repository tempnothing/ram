#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
 
int shared = 1;
sem_t s;
 
void *update(void *arg) {
    int change = *(int *)arg;
 
    sem_wait(&s);
    shared += change;
    printf("Shared value = %d\n", shared);
    sem_post(&s);
 
    return NULL;
}
 
int main() {
    pthread_t t1, t2;
    int a = 1, b = -1;
 
    sem_init(&s, 0, 1);
 
    pthread_create(&t1, NULL, update, &a);
    pthread_create(&t2, NULL, update, &b);
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 
    printf("Final value = %d\n", shared);
 
    sem_destroy(&s);
    return 0;
}
