#ifndef ALGOS_H
#define ALGOS_H

#include <stddef.h>
#include <stdbool.h>

typedef struct AdjList adj_list_t;

void bubble_sort(int arr[], size_t n);
void selection_sort(int arr[], size_t n);
void insertion_sort(int arr[], size_t n);
void merge_sort(int arr[], int temp[], size_t left, size_t right);
int binary_search(int arr[], size_t size, int target);
void dfs(adj_list_t *graph, size_t vertex, bool visited[]);
void bfs(adj_list_t *graph, size_t start);

#endif