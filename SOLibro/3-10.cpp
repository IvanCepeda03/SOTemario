#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    pid_t pid;

    pid = fork();
    abort;

    switch (pid)
    {
    case -1: // Error del fork() 
        exit(-1);
        break;
    case 0: // Proceso hijo
        execvp(argv[1], &argv[1]);
        perror("exec");
        break;
    default:
        printf("Proceso padre\n");
        break;
    }
}