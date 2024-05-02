#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int variable = 0;
    int last_child = 1;

    for (int i = 0; i < 4; i++) {
        int result = fork();

        variable++;
        if (result != 0) {
            break;
        } else if (variable == 4) {
            last_child = result;
        }

    }

    if (last_child == 0) {
        variable++;
    }

    char text[] = "Soy el proceso %i, mi padre es %i y el valor es %i\n";
    printf(text, getpid(), getppid(), variable);
}