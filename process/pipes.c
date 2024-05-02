#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int pipe_1[2];
    pipe(pipe_1);
    char c;

    int pid = fork();

    if (pid < 0) {
        printf("Llamada a fork ha fallado\n");
        exit(-1);
    }

    if (pid) {
        close(pipe_1[1]);
        read(pipe_1[0], &c, sizeof(char));
        close(pipe_1[0]);
        printf("Soy el padre, he leído \"%c\". Descriptor: %i\n", c, pipe_1[0]);

    } else {
        c = 'A';
        close(pipe_1[0]);
        write(pipe_1[1], &c, sizeof(char));
        close(pipe_1[1]);
        printf("Soy el hijo, he escrito \"%c\". Descriptor: %i\n", c, pipe_1[1]);
    }


    return 0;
}