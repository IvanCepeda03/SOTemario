#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void fin(void) {
    printf("Fin de la ejecución del proceso %d\n", getpid());
    return;
}

int main() {
    if (atexit(fin) != 0) {
        perror("atexit");
        exit(1);
    }
    exit(0); // Provoa la ejecución de la función fin
}