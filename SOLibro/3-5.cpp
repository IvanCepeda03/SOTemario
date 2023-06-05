#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    switch (pid)
    {
    case -1:
        perror("fork");
        break;
    case 0:
        printf("Este es el hijo: Proceso %d; padre = %d\n", getpid(), getppid());
        break;
    default:
        printf("Este es el padre: Proceso %d; padre = %d\n", getpid(), getppid());
        break;
    }
}