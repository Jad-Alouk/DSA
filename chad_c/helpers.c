#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int *generate_n_random_ints(size_t n)
{
    if (n == 0)
    {
        printf("Bruh\n");
        return NULL;
    }

    int *arr = malloc(sizeof(int) * n);

    if (arr == NULL)
    {
        printf("Failed to allocate memory\n");
        return NULL;
    }

    // Use srand() in main once

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    return arr;
}

void print_num_arr(int arr[], size_t n)
{
    if (arr == NULL || n == 0)
    {
        printf("Bruh\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d]\n", arr[i]);
        }

        else
        {
            printf("%d, ", arr[i]);
        }
    }
}

int_arr_t *init_int_arr(size_t cap)
{
    if (cap == 0)
    {
        printf("Bruh\n");
        return NULL;
    }

    int_arr_t *new_arr = malloc(sizeof(int_arr_t));

    if (new_arr == NULL)
    {
        printf("Failed to allocate memory\n");
        return NULL;
    }

    new_arr->data = malloc(sizeof(int) * cap);

    if (new_arr->data == NULL)
    {
        printf("Failed to allocate memory for the array data\n");
        free(new_arr);

        return NULL;
    }

    new_arr->size = 0;
    new_arr->cap = cap;

    return new_arr;
}

void int_arr_push(int_arr_t *arr, int val)
{
    if (arr == NULL || arr->data == NULL)
    {
        printf("Bruh\n");
        return;
    }

    if (arr->size == arr->cap)
    {
        size_t new_cap = arr->cap * 2;
        int *new_data = realloc(arr->data, sizeof(int) * new_cap);

        if (new_data == NULL)
        {
            printf("Failed to expand the array capacity\n");
            return;
        }

        arr->data = new_data;
        arr->cap = new_cap;
    }

    arr->data[arr->size++] = val;
}

int int_arr_pop(int_arr_t *arr)
{
    if (arr == NULL || arr->data == NULL)
    {
        printf("Bruh\n");
        return -1;
    }

    if (arr->size == 0)
    {
        printf("Array is empty\n");
        return -1;
    }

    int last_val = arr->data[arr->size - 1];
    arr->size--;

    if (arr->size > 10 && arr->size <= arr->cap / 4)
    {
        size_t new_cap = arr->cap / 2;
        int *new_data = realloc(arr->data, sizeof(int) * new_cap);

        if (new_data != NULL)
        {
            arr->data = new_data;
            arr->cap = new_cap;
        }
    }

    return last_val;
}

void free_int_arr(int_arr_t *arr)
{
    if (arr == NULL)
    {
        printf("Bruh\n");
        return;
    }

    free(arr->data);
    free(arr);
}
