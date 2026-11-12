#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
#define N 5
 
sem_t fork[N], room;
 
void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id, right = (id + 1) % N;
 
    printf("%d is thinking\n", id);
    sleep(1);
 
    sem_wait(&room);
    sem_wait(&fork[left]);
    sem_wait(&fork[right]);
 
    printf("%d is eating\n", id);
    sleep(2);
 
    sem_post(&fork[right]);
    sem_post(&fork[left]);
    sem_post(&room);
 
    return NULL;
}
 
int main()
{
    pthread_t t[N];
    int id[N];
 
    for (int i = 0; i < N; i++)
        sem_init(&fork[i], 0, 1);
 
    sem_init(&room, 0, N - 1);
 
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&t[i], NULL, philosopher, &id[i]);
    }
 
    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);
 
    for (int i = 0; i < N; i++)
        sem_destroy(&fork[i]);
 
    sem_destroy(&room);
    return 0;
}
