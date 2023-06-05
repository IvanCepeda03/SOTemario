#include <stdio.h>

int main() {
    int a = 5;
    int* a_ptr = &a;
    *a_ptr = 12;

    printf("El valor de a es: %i\n", *a_ptr);
    printf("El valor del puntero es: %p\n", a_ptr);

    return 0;
}