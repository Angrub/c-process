#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->value = 2;

    printf("Dirección head %p\n", head);
    printf("Valor head %i\n", head->value);
    printf("Dirección next %p\n", head->next);
    printf("Value next %i\n", head->next->value);

    return 0;
}