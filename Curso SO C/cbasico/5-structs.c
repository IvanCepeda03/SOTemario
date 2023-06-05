#include <stdio.h>
#include <stdlib.h>

struct Point {
    double x;
    double y;
};

int main() {
    struct Point *point = malloc(sizeof(struct Point));
    point->x = 6.4;
    point->y = 7.9;

    printf("x: %f, y: %f\n", point->x, point->y);
    free(point);
    return 0;
}