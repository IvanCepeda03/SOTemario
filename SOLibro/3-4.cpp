#include <stdio.h>
#include <stdlib.h>

int main() {
    char *home = NULL;

    home = getenv("HOME");

    if (home == NULL) {
        fprintf(stderr, "La variable HOME no se encuentra definida\n");
    }
    else {
        printf("El valor de HOME es %s\n", home);
    }
}