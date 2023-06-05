#include <stdio.h>
#include <stdlib.h>

const int DIM_ARRAY = 8;

int main() {
    int *array = malloc(sizeof(int) * DIM_ARRAY); // Declaracion de array de ints de tamaño DIM_ARRAY
    for (int i = 0; i < DIM_ARRAY; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < DIM_ARRAY; i++) {
        printf("array[%i] = %i\n", i, array[i]);
    }

    free(array);
}