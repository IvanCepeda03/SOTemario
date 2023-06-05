#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    char *argumentos[3];

    argumentos[0] = "ls";
    argumentos[1] = "-l";
    argumentos[2] = NULL;

    pid = fork();
    switch (pid)
    {
    case -1: // Error del fork
        exit(-1);
    case 0:
        execvp(argumentos[0], argumentos);
        perror("exec");
    default:
        printf("Proceso padre\n");
    }

}