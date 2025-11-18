#include <stdio.h>
#include "../helpers.h"

void selection_sort(int arr[], size_t n)
{
    if (arr == NULL || n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        size_t min_idx = i;

        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&arr[i], &arr[min_idx]);
    }
}