#ifndef ALGOS_H
#define ALGOS_H

#include <stddef.h>

void bubble_sort(int arr[], size_t n);
void selection_sort(int arr[], size_t n);
void insertion_sort(int arr[], size_t n);
void merge_sort(int arr[], int temp[], size_t left, size_t right);

#endif