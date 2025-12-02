#include <stdio.h>
#include <stdbool.h>
#include "../Data_Structures/ds.h"

void dfs(adj_list_t *graph, size_t vertex, bool visited[])
{
    if (graph == NULL)
    {
        printf("Bruh\n");
        return;
    }

    visited[vertex] = true;
    printf("%zu ", vertex);

    adj_list_node_t *curr = graph->edges[vertex].head;

    while (curr)
    {
        if (!visited[curr->vertex])
        {
            dfs(graph, curr->vertex, visited);
        }

        curr = curr->next;
    }
}
