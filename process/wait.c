#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int result = fork();

    if (result < 0) {
        printf("Llamada a fork ha fallado\n");
        exit(-1);
    }

    if (result != 0) {
        printf("Esperar al \"ls\" del proceso hijo\n");
        wait(NULL);
        printf("Salida ps:\n");
        execlp("ps", "ps");
    } else {
        printf("Salida ls:\n");
        execlp("ls", "ls");
    }
}