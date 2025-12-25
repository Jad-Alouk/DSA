#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Algorithms/algos.h"
#include "Data_Structures/ds.h"
#include "helpers.h"

int heap_tester(globals_t *globals);
int sll_tester(globals_t *globals);
int dll_tester(globals_t *globals);
int sorting_algos_tester(globals_t *globals);
int binary_search_tester(globals_t *globals);

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
        {
            return -1;
        }

        if (sll_tester(globals) == -1)
        {
            return -1;
        }

        if (dll_tester(globals) == -1)
        {
            return -1;
        }

        if (sorting_algos_tester(globals) == -1)
        {
            return -1;
        }

        if (binary_search_tester(globals) == -1)
        {
            return -1;
        }

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

        else if (strncmp("dll", choice, 3) == 0)
        {
            if (dll_tester(globals) == -1)
                return -1;
        }

        else if (strncmp("sorting_algos", choice, 13) == 0)
        {
            if (sorting_algos_tester(globals) == -1)
                return -1;
        }

        else if (strncmp("bs", choice, 2) == 0)
        {
            if (binary_search_tester(globals) == -1)
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

    printf("\n----- MinHeap Test -----\n");

    printf("\nHeapify a random list of ints (size: %zu):\n\n", globals->op_count);

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
    printf("Heapify O(n): %lf\n\n", globals->perf_time);

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

    printf("Heap push O(logn): %lf\n\n", globals->perf_time);

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

    printf("Heap pop O(logn): %lf\n\n", globals->perf_time);

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

    printf("\n----- Singly Linked List Test -----\n");

    printf("\nCreating %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        single_node_t node = {.data = i, .next = NULL};
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Creating %zu nodes O(1): %lf\n\n", globals->op_count, globals->perf_time);

    singly_linked_list_t *sll = init_sll();

    printf("Prepending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        prepend_sll(sll, rand());
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Prepending nodes O(1): %lf\n\n", globals->perf_time);

    printf("Appending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        append_sll(sll, rand());
    }
    globals->end_t = clock();

    printf("Appending %zu nodes O(1): %lf\n\n", globals->op_count, globals->perf_time);

    printf("Inserting %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        insert_node_sll(sll, i, (size_t)(rand() % sll->size));
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\nInserting %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n\n", globals->perf_time);

    printf("Removing %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        remove_node_sll(sll, i);
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\nRemoving %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n\n", globals->perf_time);

    printf("----- Passed -----\n");

    free_sll(sll);
    reset_globals(globals);

    return 0;
}

int dll_tester(globals_t *globals)
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

    printf("\n----- Doubly Linked List Test -----\n");

    printf("\nCreating %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        double_node_t node = {.prev = NULL, .data = i, .next = NULL};
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Creating %zu nodes O(1): %lf\n\n", globals->op_count, globals->perf_time);

    doubly_linked_list_t *dll = init_dll();

    printf("Prepending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        prepend_dll(dll, rand());
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Prepending nodes O(1): %lf\n\n", globals->perf_time);

    printf("Appending %zu nodes...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        append_dll(dll, rand());
    }
    globals->end_t = clock();

    printf("Appending %zu nodes O(1): %lf\n\n", globals->op_count, globals->perf_time);

    printf("Inserting %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        insert_node_dll(dll, i, (size_t)(rand() % dll->size));
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\nInserting %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n\n", globals->perf_time);

    printf("Removing %zu nodes in random spots...\n", globals->op_count);

    globals->start_t = clock();
    for (size_t i = 0; i < globals->op_count; i++)
    {
        remove_node_dll(dll, i);
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("\nRemoving %zu nodes O(1)\n", globals->op_count);
    printf("Traversing %zu nodes O(n)\n", globals->op_count);
    printf("Total time: %lf\n\n", globals->perf_time);

    printf("----- Passed -----\n");

    free_dll(dll);
    reset_globals(globals);

    return 0;
}

int sorting_algos_tester(globals_t *globals)
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

    printf("\n----- Sorting Algorithms Test -----\n");

    printf("\n----- Bubble Sort Test -----\n\n");

    printf("Generating %zu random numbers...\n\n", globals->op_count);

    int *arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    bubble_sort(arr, globals->op_count);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    bool is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Bubble sort O(n^2): %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Selection Sort Test -----\n\n");

    printf("Generating %zu random numbers...\n\n", globals->op_count);

    arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    selection_sort(arr, globals->op_count);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Selection sort O(n^2): %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Insertion Sort Test -----\n\n");

    printf("Generating %zu random numbers...\n\n", globals->op_count);

    arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    insertion_sort(arr, globals->op_count);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Insertion sort O(n^2): %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Merge Sort Test -----\n\n");

    globals->op_count = 100000000;
    int *temp = malloc(sizeof(int) * globals->op_count);

    if (temp == NULL)
    {
        printf("Failed to allocate memory for the temp arr\n");
        return -1;
    }

    printf("Generating %zu random numbers...\n\n", globals->op_count);

    arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    merge_sort(arr, temp, 0, globals->op_count - 1);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Merge sort O(nlogn): %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Quick Sort Test -----\n\n");

    globals->op_count = 10000000;

    printf("Generating %zu random numbers...\n\n", globals->op_count);

    arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    quick_sort(arr, 0, globals->op_count - 1);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Quick sort O(nlogn): %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Bucket Sort Test -----\n\n");

    printf("Generating %zu uniformly distributed numbers...\n\n", globals->op_count);

    arr = generate_n_random_ints(globals->op_count);

    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }

    printf("Sorting...\n\n");

    globals->start_t = clock();
    bucket_sort(arr, globals->op_count, insertion_sort);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Checking if the arr is sorted...\n");
    is_sorted = is_arr_sorted(arr, globals->op_count, true);
    printf("The arr is sorted: %s\n\n", is_sorted ? "True" : "False");

    printf("Bucket sort O(n + k) with uniformly distributed data: %lf\n\n", globals->perf_time);

    if (!is_sorted)
    {
        printf("The arr is not sorted\n");
        return -1;
    }

    printf("----- Passed -----\n\n");

    reset_globals(globals);
    free(arr);
    free(temp);

    return 0;
}

int binary_search_tester(globals_t *globals)
{
    printf("\n----- Binary Search Test -----\n");

    if (globals == NULL)
    {
        printf("Global variables are not initialized\n");
        return -1;
    }

    globals->start_t = clock();
    globals->end_t = clock();
    globals->perf_time = 0;
    globals->op_count = 1000000000;

    printf("\nGenerating %zu consecutive numbers...\n", globals->op_count);

    globals->start_t = clock();
    int *arr = malloc(sizeof(int) * globals->op_count);
    if (arr == NULL)
    {
        printf("Failed to allocate memory for the arr\n");
        return -1;
    }
    for (size_t i = 0; i < globals->op_count; i++)
    {
        arr[i] = i;
    }
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    printf("Generating %zu consecutive numbers took: %lf\n\n", globals->op_count, globals->perf_time);

    int t = arr[globals->op_count - 1];

    globals->start_t = clock();
    int res = binary_search(arr, globals->op_count, t);
    globals->end_t = clock();

    globals->perf_time = (double)(globals->end_t - globals->start_t) / CLOCKS_PER_SEC;

    if (res == -1)
    {
        printf("Value was not found\n");
        return -1;
    }

    printf("Binary search O(logn): %lf\n\n", globals->perf_time);

    printf("----- Passed -----\n");

    reset_globals(globals);
    free(arr);

    return 0;
}
