#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func_thread(void *arg) {
    int value = *(int*)arg;
    printf("Desde el hilo 2 el valor es %i\n", value);
    pthread_exit(0);
}

int main() {
    pthread_t thread;
    int value = 10;
    pthread_create(&thread, NULL, func_thread, &value);
    pthread_join(thread, NULL);
    printf("Este es el hilo 1\n");
    return 0;
}
