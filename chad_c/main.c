#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Algorithms/algos.h"
#include "Data_Structures/ds.h"
#include "helpers.h"

int main(void)
{
    srand(time(NULL));

    clock_t start_t = clock();
    clock_t end_t = clock();
    double perf_time = 0;

    size_t op_count = 10000000;
    int *arr_data = generate_n_random_ints(op_count);
    int_arr_t *arr = init_int_arr();

    for (size_t i = 0; i < op_count; i++)
    {
        int_arr_push(arr, arr_data[i]);
    }

    // ----- Heap -----

    printf("\n");
    printf("----- MinHeap Test -----\n");

    printf("\n");
    printf("Heapify a random list of ints (size: %zu):\n", op_count);
    printf("\n");

    start_t = clock();
    heapify(arr);
    end_t = clock();

    perf_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    char *heap_validity = is_valid_min_heap(arr) ? "valid" : "invalid";

    printf("The resulting min heap is %s\n", heap_validity);
    printf("Heapify O(n): %lf\n", perf_time);
    printf("\n");

    printf("Pushing %zu elements...\n", op_count);

    start_t = clock();
    for (size_t i = 0; i < op_count; i++)
    {
        heap_push(arr, rand());
    }
    end_t = clock();

    if (!is_valid_min_heap(arr))
    {
        printf("Heap property violated after heap_push\n");
    }

    printf("Pushing %zu elements was successful\n", op_count);

    perf_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Heap push O(logn): %lf\n", perf_time);
    printf("\n");

    op_count = arr->size;

    printf("Popping %zu elements...\n", op_count);

    start_t = clock();
    for (size_t i = 0; i < op_count; i++)
    {
        heap_pop(arr);
    }
    end_t = clock();

    if (!is_valid_min_heap(arr))
    {
        printf("Heap property violated after heap_pop\n");
    }

    printf("Popping %zu elements was successful\n", op_count);

    perf_time = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Heap pop O(logn): %lf\n", perf_time);
    printf("\n");

    printf("----- Passed -----\n");

    reset_globals(&perf_time, &op_count, arr_data, arr);

    // ----- Heap -----

    free(arr_data);
    free_int_arr(arr);

    return 0;
}