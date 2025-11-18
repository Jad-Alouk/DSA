#include <stdio.h>
#include <stdbool.h>
#include "../helpers.h"

void bubble_sort(int arr[], size_t n)
{
    if (arr == NULL || n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}