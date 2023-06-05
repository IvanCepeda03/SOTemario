#include <pthread.h>
#include <stdio.h>

void *func(void *arg) {
    printf("Thread %d\n", pthread_self());
    pthread_exit(0);
}

// Crea 2 proceso ligeros no independientes

int main() {
    pthread_t th1, th2;

    pthread_create(&th1, NULL, &func, NULL);
    pthread_create(&th2, NULL, &func, NULL);
}