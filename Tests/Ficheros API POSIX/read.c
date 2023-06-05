#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/*
Programa que lee un fichero dado como parámetro usando la API POSIX para ficheros
Y lo escribe en la salida estandar
*/

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s pahtname\n", argv[0]);
        exit(-1);
    }

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        perror("open file");
        exit(EXIT_FAILURE);
    }
    
    char c;
    ssize_t bytesRead;
    while ((bytesRead = read(fd, &c, 1)) > 0) {
        printf("%c", c);
    }

    if (bytesRead == -1) {
        perror("read file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    return EXIT_SUCCESS;
}
