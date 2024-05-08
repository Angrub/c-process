#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    unsigned long id;
    unsigned long *array;
    unsigned long array_len;
    unsigned long long result;
    int threads;
} Add_data;

void *add(void *_data);

int main(int argc, char **argv) {
    unsigned long array_size;
    int threads_num = 1;
    // Validate args
    if (argc < 2) {
        printf("Uso:\n");
        printf("%s array-size [threads]\n", argv[0]);
        exit(-1);
    }

    array_size = atoi(argv[1]);
    if (argc == 3) {
        threads_num = atoi(argv[2]);
    }

    // generate array
    unsigned long *num_array = malloc(sizeof(unsigned long) * array_size);

    for (unsigned long i = 0; i < array_size; i++) {
        num_array[i] = i + 1;
    }
    // create threads
    pthread_t *threads = malloc(sizeof(pthread_t) * threads_num);
    Add_data *threads_data = malloc(sizeof(Add_data) * threads_num);

    for (int i = 0; i < threads_num; i++) {
        threads_data[i].id = i;
        threads_data[i].array = num_array;
        threads_data[i].array_len = array_size; 
        threads_data[i].result = 0;
        threads_data[i].threads = threads_num;
        pthread_create(&threads[i], NULL, add, (void*)&threads_data[i]);
    }

    // wait threads result 
    unsigned long long final_add;

    for (int i = 0; i < threads_num; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < threads_num; i++) {
        final_add += threads_data[i].result;
    }

    // print final result
    printf("Resultado final: %llu\n", final_add);

    free(num_array);
    free(threads);
    free(threads_data);

    return 0;
}

void *add(void *_data) {
    unsigned long nums_to_add, start, end;
    Add_data *data = (Add_data*)_data;
    nums_to_add = data->array_len / data->threads;
    start = nums_to_add * data->id;

    if (data->id == data->threads - 1) {
        end = data->array_len;
    } else {
        end = start + nums_to_add;
    }

    for (unsigned long i = start; i < end; i++) {
        data->result += *(data->array + i);
    }

    printf("thread %i, result: %llu\n", data->id, data->result);

    pthread_exit(0);
}