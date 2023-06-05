#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* Programa que crea un proceso en background
*/


int main(int argc, char **argv) {
    pid_t pid;
    
    pid = fork();
    switch (pid)
    {
    case -1: // Error del fork
        exit(-1);
        break;
    case 0:
        if (execvp(argv[1], &argv[1]) < 0)
            perror("exec");
    default:
        exit(0);
    }
}