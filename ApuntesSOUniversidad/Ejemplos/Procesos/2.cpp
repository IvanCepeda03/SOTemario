#include <stdio.h>
#include <pthread.h>
#define NTH 10

struct tharg {
    int i;
    char *msg;
};

void *foo(void *arg) {
    struct tharg *tharg = (struct tharg *) arg;
    printf("Thread %d with pthread id %ld says %s\n", tharg->i, (long)pthread_self(), tharg->msg);
    pthread_exit(0);
}

int main(void) {
    int j;
    pthread_attr_t attr;
    struct tharg args[NTH];
    pthread_t thid[NTH];

    pthread_attr_init(&attr);
    for (j = 0; j < NTH; j++) {
        args[j].i = j;
        args[j].msg = "Hello!";
        pthread_create(&thid[j], &attr, foo, &args[j]);
    }

    for (j = 0; j < NTH; j++) {
        pthread_join(thid[j], NULL);
    }

    return 0;
}