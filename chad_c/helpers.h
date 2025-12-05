#ifndef HELPERS_H
#define HELPERS_H

#include <time.h>

typedef struct IntArray
{
    int *data;
    size_t size;
    size_t cap;
} int_arr_t;

typedef struct Globals
{
    clock_t start_t;
    clock_t end_t;
    double perf_time;
    size_t op_count;
} globals_t;

globals_t *init_globals();
void reset_globals(globals_t *globals);

void swap(int *num1, int *num2);
int *generate_n_random_ints(size_t n);
void print_num_arr(int arr[], size_t n);

int_arr_t *init_int_arr();
void free_int_arr(int_arr_t *arr);
void int_arr_push(int_arr_t *arr, int val);
int int_arr_pop(int_arr_t *arr);

bool is_valid_min_heap(int_arr_t *heap);

#endif