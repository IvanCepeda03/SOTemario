#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **strings = malloc(sizeof(char*) * 2);
    char *msg1 = malloc(sizeof(char) * 8);
    char *msg2 = malloc(sizeof(char) * 8);

    strcpy(msg1, "Hola");
    strcpy(msg2, "Mensaje");

    strings[0] = msg1;
    strings[1] = msg2;


    printf("%s %s\n", strings[0], strings[1]);
    free(strings);
    free(msg1);
    free(msg2);
    return 0;
}