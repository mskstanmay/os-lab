#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *myThread(void *args)
{
    char *name = (char *)args;
    for (int i = 1; i <= 5; i++)
    {
        printf("%s is running, iteration: %d\n", name, i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, myThread, "Thread-1");
    pthread_create(&t2, NULL, myThread, "Thread-2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
