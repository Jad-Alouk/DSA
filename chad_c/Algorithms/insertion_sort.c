#include <stdio.h>
#include "../helpers.h"

void insertion_sort(int arr[], size_t n)
{
    if (arr == NULL || n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    for (size_t i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = (int)i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}