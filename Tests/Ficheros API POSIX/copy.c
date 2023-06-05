#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 
#include <fcntl.h>

int copy(char* src, char* dst);

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage %s src dst\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    if (copy(argv[1], argv[2]) != 0)
        exit(EXIT_FAILURE);

    return 0;
}

int copy(char* src, char* dst) {
    int fd_src, fd_dst;

    fd_src = open(src, O_RDONLY);
    fd_dst = open(dst, O_WRONLY|O_CREAT|O_TRUNC, 0660);

    if (fd_src == -1) {
        perror("Error opening src");
        return -1;
    }
    if (fd_dst == -1) {
        perror("Error opening dst");
        return -1;
    }

    ssize_t n;
    char c;
    do {
        n = read(fd_src, &c, 1);
        if (n > 0) 
            n = write(fd_dst, &c, 1);
    } while (n > 0);

    close(fd_src);
    close(fd_dst);

    if (n < 0) {
        perror("Error in the copy");
        return -1;
    }

    return 0;
}