#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    switch (pid)
    {
    case -1: // Error en fork
        exit(-1);
    case 0: // Proceso hijo
        if (execvp(argv[1], &argv[1]) < 0)
            perror("exec");
        break;
    default: // Padre
        while (wait(&status) != pid);

        if (status == 0)
            printf("El mandato se ejecuto de forma normal\n");
        else {
            if (WIFEXITED(status)) 
                printf("El hijo termino normalemte y su valor devuelto fue %d\n", WEXITSTATUS(status));

            if (WIFSIGNALED(status))
                printf("El hijo termino al recibir la señal %d\n", WTERMSIG(status));
        }
        break;
    }
}