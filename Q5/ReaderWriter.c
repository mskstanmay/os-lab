#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> 

sem_t mutex, wrt;
int readcount = 0;
int data = 1;

void* reader(void* args) {
    int f = *(int*) args;
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("Reader %d: read data = %d\n", f, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);
    return NULL;
}

void* writer(void* args) {
    int f = *(int*)args;
    sem_wait(&wrt);
    data ++;; 
    printf("Writer %d: wrote data = %d\n", f, data);
    sleep(1);
    sem_post(&wrt);
    return NULL;
}

int main() {
    pthread_t r[5], w[5];
    int id[5];
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < 5; i++) {
    id[i]=i;
        pthread_create(&r[i], NULL, reader, &id[i]);
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}

