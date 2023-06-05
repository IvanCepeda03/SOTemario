#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    int n = 10;

    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }
    
    printf("El padre del proceso %d es %d\n", getpid(), getppid());
}