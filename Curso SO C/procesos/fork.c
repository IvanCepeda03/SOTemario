#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int valor = 1;

    for (int i = 0; i < 4; i++) {
        int result = fork();
        if (result != 0) {
            valor++;
            break;
        } else {
            valor += 2;
        }
    }

    printf("Soy el proceso %i, mi padre es %i, el valor es: %i\n", getpid(), getppid, valor);

    return EXIT_SUCCESS;
}