#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hello[] = "Hello";
    char *world = malloc(sizeof(char) * 6);
    strcpy(world, "World");

    printf("%s %s\n", hello, world);

    free(world);
    return 0;
}