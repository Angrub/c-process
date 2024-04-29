#include <stdio.h>
#include <stdlib.h>

int main() {
    int length = 4;
    int *array = malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]); 
    }

    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]); 
    }

    free(array);
    return 0;
}