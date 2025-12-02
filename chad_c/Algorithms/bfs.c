#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Data_Structures/ds.h"

void bfs(adj_list_t *graph, size_t start)
{
    if (graph == NULL || start >= graph->vertices)
    {
        printf("Bruh\n");
        return;
    }

    bool *visited = calloc(graph->vertices, sizeof(bool));

    if (visited == NULL)
    {
        printf("Failed to allocate memory for the \"visited\" arr\n");
        return;
    }

    size_t *queue = malloc(graph->vertices * sizeof(size_t));

    if (queue == NULL)
    {
        printf("Failed to allocate memory for the queue\n");
        free(visited);
        return;
    }

    size_t front = 0;
    size_t back = 0;

    visited[start] = true;
    queue[back++] = start;

    while (front < back)
    {
        size_t v = queue[front++];
        printf("%zu ", v);

        adj_list_node_t *curr = graph->edges[v].head;

        while (curr)
        {
            size_t neighbor = curr->vertex;

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue[back++] = neighbor;
            }

            curr = curr->next;
        }
    }

    printf("\n");

    free(queue);
    free(visited);
}
