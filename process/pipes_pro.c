#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Falta la dirección del fichero");
        exit(-1);
    }

    int pipe_1[2], pipe_2[2];
    pipe(pipe_2);

    int pid = fork();

    if (pid < 0) {
        printf("Llamada a fork 1 ha fallado\n");
        exit(-1);
    }

    if (pid) {
        close(pipe_2[1]);
        close(0);
        dup(pipe_2[0]);
        close(pipe_2[0]);

        close(1);
        open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);

        execlp("sort", "sort", "-u", NULL);
        printf("Error sort");
    } else {
        pipe(pipe_1);
        int pid_2 = fork();

        if (pid_2 < 0) {
            printf("Llamada a fork 2 ha fallado\n");
            exit(-1);
        }

        if (pid_2) {
            // stdout
            close(pipe_2[0]);
            close(1);
            dup(pipe_2[1]);
            close(pipe_2[1]);

            // stdin
            close(pipe_1[1]);
            close(0);
            dup(pipe_1[0]);
            close(pipe_1[0]);

            execlp("cut", "cut", "-c5-12", NULL);
            printf("Error cut");

        } else {
            close(pipe_2[0]);
            close(pipe_2[1]);

            close(pipe_1[0]);
            close(1);
            dup(pipe_1[1]);
            close(pipe_1[1]);

            execlp("ps", "ps", "-efl", NULL);
            printf("Error ps");
        }
    }

    return 0;
}