#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();
    switch (pid)
    {
    case -1: // Error del fork
        exit(-1);
        break;
    case 0: // Proceso hijo
        execlp("ls", "ls", "-l", NULL);
        perror("exec");
        break;
    default:
        printf("Proceso padre\n");
        break;
    }
}