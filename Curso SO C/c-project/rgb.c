#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RGB {
    int r;
    int g;
    int b;
    int last;
};

int set_rgb(struct RGB* rgb, int r, int g, int b); // 1 Format error, 0 Success
void invert_rgb(struct RGB* rgb);
void invert_rgbs(struct RGB* rgbs);
char *rgb_str(struct RGB *rgb);
struct RGB* read_rgbs(char* file);

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s fichero", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct RGB *rgbs = read_rgbs(argv[1]);

    printf("RGBs sin invertir:\n");
    for (int i = 0; !rgbs[i].last; i++) {
        char *s = rgb_str(&rgbs[i]);
        printf("%s\n", s);
        free(s);
    }

    invert_rgbs(rgbs);
    printf("RGBs invertidos:\n");
    for (int i = 0; !rgbs[i].last; i++) {
        char *s = rgb_str(&rgbs[i]);
        printf("%s\n", s);
        free(s);
    }

    return EXIT_SUCCESS;
}

int set_rgb(struct RGB* rgb, int r, int g, int b) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return 1; // Returns format error
    }

    rgb->r = r;
    rgb->b = b;
    rgb->g = g;

    return 0; // Returns Success
}

void invert_rgb(struct RGB* rgb) {
    rgb->r = 255 - rgb->r;
    rgb->g = 255 - rgb->g;
    rgb->b = 255 - rgb->b;
}

void invert_rgbs(struct RGB* rgbs) {
    for (int i = 0; !rgbs[i].last; i++) {
        invert_rgb(&rgbs[i]);
    }
}

char *rgb_str(struct RGB *rgb) {
    char *str = malloc(sizeof(char) * 64);

    sprintf(
        str, "RGB: (%i, %i, %i)\nHEX: 0x%02x%02x%02x\n",
        rgb->r, rgb->g, rgb->b,
        rgb->r, rgb->g, rgb->b
    );

    return str;
}

struct RGB *read_rgbs(char* file) {
    int limit = 4;
    struct RGB *rgbs = malloc(sizeof(struct RGB) * limit);

    int line_size = 16;
    char *line = malloc(sizeof(char) * line_size);

    FILE *f = fopen(file, "r");
    if (f == NULL) {
        fprintf(stderr, "El archivo %s no existe", file);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(line, line_size, f)) {
        if (i >= limit - 1) {
            limit *= 2;
            rgbs = realloc(rgbs, sizeof(struct RGB) * limit);
        }

        int values[3];
        char *split = strdup(line);

        for (int j = 0; j < 3; j++) {
            values[j] = atoi(strsep(&split, " "));
        }

        free(split);

        if (set_rgb(&rgbs[i], values[0], values[1], values[2])) {
            fprintf(stderr, "El formato del color de la linea %i del fichero %s es incorrecto\n", i + 1, file);
            exit(EXIT_FAILURE);
        }
        rgbs[i].last = 0;

        i++;
    }

    rgbs[i].last = 1;

    free(line);
    fclose(f);

    return rgbs;
}