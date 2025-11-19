#include <stddef.h>

void merge(int arr[], int temp[], size_t left, size_t mid, size_t right);

void merge_sort(int arr[], int temp[], size_t left, size_t right)
{
    if (left >= right)
    {
        return;
    }

    size_t mid = (left + right) / 2;

    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

void merge(int arr[], int temp[], size_t left, size_t mid, size_t right)
{
    size_t i = left;
    size_t j = mid + 1;
    size_t k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }

        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (size_t p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}
