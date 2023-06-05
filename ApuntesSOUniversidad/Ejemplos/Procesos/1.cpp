#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        execlp("ls", "ls", "-l", NULL);
        perror("");
        return -1;
    } else {
        while(pid != wait(&status));
    }

    return 0;
}