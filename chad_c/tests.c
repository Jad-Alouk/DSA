#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Algorithms/algos.h"
#include "Data_Structures/ds.h"
#include "helpers.h"

int heap_tester(globals_t *globals);
int sll_tester(globals_t *globals);

int test_runner(int argc, char **argv)
{
    // Arg parser
    if (argc == 1)
    {
        printf("No args provided. Try \"all\" to run all tests\n");
        return 0;
    }

    globals_t *globals = init_globals();
    if (globals == NULL)
    {
        printf("Execution is terminated due to uninitialized global variables\n");
        return -1;
    }

    if (argc == 2 && (strncmp("all", argv[1], 3) == 0))
    {
        if (heap_tester(globals) == -1)
            return -1;
        if (sll_tester(globals) == -1)
            return -1;

        return 0;
    }

    for (size_t i = 1; i < argc; i++)
    {
        char *choice = argv[i];

        if (strncmp("heap", choice, 4) == 0)
        {
            if (heap_tester(globals) == -1)
                return -1;
        }

        else if (strncmp("sll", choice, 3) == 0)
        {
            if (sll_tester(globals) == -1)
                return -1;
        }

        else
        {
            printf("Invalid command line arg");
            return -1;
        }
    }

    free(globals);

    return 0;
}

int heap_tester(globals_t *globals)
{
    if (globals == NULL)
    {
        printf("Global variables are not initialized\n");
        return -1;
    }

    globals->start_t = clock();
    globals->end_t = clock();
    globals->perf_time = 0;
    globals->op_count = 10000000;

    int *arr_data = generate_n_random_ints(globals->op_count);
    int_arr_t *arr = init_int_arr();

    if (arr_data == NULL || arr == NULL)
    {
        printf("Failed to allocate memory for the heap\n");
        return -1;
    }

    for (size_t i = 0; i < globals->op_count; i++)
    {
        int_arr_push(arr, arr_data[i]);
    }

    printf("\n");
    printf("----- MinHeap Test -----\n");

    printf("\n");
    printf("Heapify a random list of ints (size: %zu):\n", globals->op_count);
    printf("\n");

    globals->start_t = clock();
    heapify(arr);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    if (!is_valid_min_heap(arr))
    {
        printf("The resulting min heap is invalid\n");
        return -1;
    }

    printf("The resulting min heap is valid\n");
    printf("Heapify O(n): %lf\n", globals->perf_time);
    printf("\n");

    printf("Pushing %zu elements...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        heap_push(arr, rand());
    }
    globals->end_t = clock();

    if (!is_valid_min_heap(arr))
    {
        printf("Heap property violated after heap_push\n");
        return -1;
    }

    printf("Pushing %zu elements was successful\n", globals->op_count);

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Heap push O(logn): %lf\n", globals->perf_time);
    printf("\n");

    globals->op_count = arr->size;

    printf("Popping %zu elements...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        heap_pop(arr);
    }
    globals->end_t = clock();

    if (!is_valid_min_heap(arr))
    {
        printf("Heap property violated after heap_pop\n");
        return -1;
    }

    printf("Popping %zu elements was successful\n", globals->op_count);

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Heap pop O(logn): %lf\n", globals->perf_time);
    printf("\n");

    printf("----- Passed -----\n");

    reset_globals(globals);
    free_int_arr(arr);

    return 0;
}

int sll_tester(globals_t *globals)
{
    if (globals == NULL)
    {
        printf("Global variables are not initialized\n");
        return -1;
    }

    globals->start_t = clock();
    globals->end_t = clock();
    globals->perf_time = 0;
    globals->op_count = 100000;

    printf("\n");
    printf("----- Singly Linked List Test -----\n");

    printf("\n");
    printf("Creating %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        single_node_t node = {.data = i, .next = NULL};
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Creating %zu nodes O(1): %lf\n", globals->op_count, globals->perf_time);
    printf("\n");

    singly_linked_list_t *sll = init_sll();

    printf("Prepending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        prepend_sll(sll, rand());
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Prepending nodes O(1): %lf\n", globals->perf_time);
    printf("\n");

    printf("Appending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        append_sll(sll, rand());
    }
    globals->end_t = clock();

    printf("Appending %zu nodes O(1): %lf\n", globals->op_count, globals->perf_time);
    printf("\n");

    printf("Inserting %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        insert_node_sll(sll, i, (size_t)(rand() % sll->size));
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Inserting %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n", globals->perf_time);
    printf("\n");

    printf("Removing %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        remove_node_sll(sll, i);
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Removing %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n", globals->perf_time);
    printf("\n");

    printf("----- Passed -----\n");
    printf("\n");

    free_sll(sll);
    reset_globals(globals);

    return 0;
}
