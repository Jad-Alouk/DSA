#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../helpers.h"

#define BUCKET_COUNT_LIMIT 10000

// Helper to determine the number of buckets
size_t bucket_count(size_t n, size_t limit)
{
    if (n <= limit) // Small to medium n's: just create n buckets
    {
        return n;
    }

    // Large n's: take (k) the square root of n, and create k buckets
    size_t k = (size_t)(sqrt(n));
    return k == 0 ? 1 : k;
}

void bucket_sort(int arr[], size_t n, void (*sort_func)(int *, size_t))
{
    if (arr == NULL)
    {
        printf("Array is NULL\n");
        return;
    }

    if (sort_func == NULL)
    {
        printf("Sorting helper is NULL\n");
        return;
    }

    if (n <= 1)
    {
        printf("Array of size (n <= 1) is already sorted\n");
        return;
    }

    // Get min and max to perform linear normalization
    float min_v = arr[0];
    float max_v = arr[0];

    for (size_t i = 1; i < n; i++)
    {
        if (arr[i] < min_v)
        {
            min_v = arr[i];
        }

        else if (arr[i] > max_v)
        {
            max_v = arr[i];
        }
    }

    // Edge case: all values are equal
    if (min_v == max_v)
    {
        printf("Array is already sorted\n");
        return;
    }

    size_t k = bucket_count(n, BUCKET_COUNT_LIMIT);

    // 2D array: rows == k && cols == dynamic size
    int_arr_t **buckets = malloc(sizeof(int_arr_t *) * k);

    if (buckets == NULL)
    {
        printf("Failed to allocate memory for the buckets container\n");
        return;
    }

    // Init a dynamic array for each bucket
    for (size_t i = 0; i < k; i++)
    {
        int_arr_t *bucket = init_int_arr();

        if (bucket == NULL)
        {
            printf("Failed to allocate memory for the buckets\n");

            // Free all prev allocated buckets
            for (size_t j = 0; j < i; j++)
            {
                free_int_arr(buckets[j]);
            }
            free(buckets);

            return;
        }

        buckets[i] = bucket;
    }

    // Cache the data range
    float range = max_v - min_v;

    //  Distribute elements into buckets
    for (size_t i = 0; i < n; i++)
    {
        float normalized_v = (arr[i] - min_v) / range; // Linear normalization

        // Edge case: normalized num == 1.0 => bi = n (index out of bound)
        int bi = normalized_v >= 1.0 ? k - 1 : (int)(k * normalized_v);

        // Assign data to each bucket
        int_arr_push(buckets[bi], arr[i]);
    }

    // Sort and concat all buckets
    // i loops over each bucket
    // k loops over each element in the original array
    // l loops over each element in each bucket
    size_t j = 0;
    for (size_t i = 0; i < k; i++)
    {
        // Soting helper must sort in place
        sort_func(buckets[i]->data, buckets[i]->size);

        for (size_t l = 0; l < buckets[i]->size; l++)
        {
            arr[j++] = buckets[i]->data[l];
        }
    }

    // Free all auxiliary data structures
    for (size_t i = 0; i < k; i++)
    {
        free_int_arr(buckets[i]);
    }
    free(buckets);
}