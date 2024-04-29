#include <stdio.h>

int main() {
    int a = 12;
    int *a_pointer = &a;
    int *pointer_pointer = &a;
    int value_pointer_pointer = *pointer_pointer;

    printf("Valor a: %i\n", a);
    printf("Valor a_pointer: %p\n", a_pointer);
    printf("Valor pointer_pointer: %p\n", pointer_pointer);
    printf("Valor value_pointer_pointer: %i\n", value_pointer_pointer);
    return 0;
}