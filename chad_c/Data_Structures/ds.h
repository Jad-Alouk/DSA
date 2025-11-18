#ifndef DS_H
#define DS_H

#include <stddef.h>

typedef struct IntArray int_arr_t;

int _parent(size_t i);
int _left(size_t i, size_t size);
int _right(size_t i, size_t size);

void _sift_up(int_arr_t *heap, size_t i);
void _sift_down(int_arr_t *heap, size_t i);

void heapify(int_arr_t *arr);
void heap_push(int_arr_t *heap, int val);
int heap_pop(int_arr_t *heap);

#endif