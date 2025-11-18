#include <stdio.h>
#include <stdlib.h>
#include "../helpers.h"

int _parent(size_t i);
int _left(size_t i, size_t size);
int _right(size_t i, size_t size);

void _sift_up(int_arr_t *heap, size_t i);
void _sift_down(int_arr_t *heap, size_t i);

void heapify(int_arr_t *arr);
void heap_push(int_arr_t *heap, int val);
int heap_pop(int_arr_t *heap);

void heapify(int_arr_t *arr)
{
    if (arr == NULL)
    {
        printf("Bruh\n");
        return;
    }

    for (size_t i = (arr->size / 2) - 1; i-- > 0;)
    {
        _sift_down(arr, i);
    }
}

void heap_push(int_arr_t *heap, int val)
{
    int_arr_push(heap, val);

    _sift_up(heap, heap->size - 1);
}

int heap_pop(int_arr_t *heap)
{
    if (heap == NULL || heap->data == NULL)
    {
        printf("Bruh\n");
        return -1;
    }

    if (heap->size == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    int min_val = heap->data[0];
    int last_val = int_arr_pop(heap);

    if (heap->size > 0)
    {
        heap->data[0] = last_val;
        _sift_down(heap, 0);
    }

    return min_val;
}

int _parent(size_t i)
{
    return (i > 0) ? (int)((i - 1) / 2) : -1;
}

int _left(size_t i, size_t size)
{
    size_t left = 2 * i + 1;
    return (left < size) ? (int)left : -1;
}

int _right(size_t i, size_t size)
{
    size_t right = 2 * i + 2;
    return (right < size) ? (int)right : -1;
}

void _sift_up(int_arr_t *heap, size_t i)
{
    int parent_idx = _parent(i);

    while (parent_idx != -1 && heap->data[parent_idx] > heap->data[i])
    {
        swap(&heap->data[parent_idx], &heap->data[i]);

        i = parent_idx;
        parent_idx = _parent(i);
    }
}

void _sift_down(int_arr_t *heap, size_t i)
{
    while (1)
    {
        int smallest = i;
        int left = _left(i, heap->size);
        int right = _right(i, heap->size);

        if (left != -1 && heap->data[smallest] > heap->data[left])
        {
            smallest = left;
        }

        if (right != -1 && heap->data[smallest] > heap->data[right])
        {
            smallest = right;
        }

        if (smallest == i)
        {
            break;
        }

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
}
