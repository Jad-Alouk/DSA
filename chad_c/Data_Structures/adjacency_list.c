#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    AdjListNode:
        A node in a singly linked list representing one edge.
        Stores the index of a neighboring vertex and a pointer
        to the next neighbor in the adjacency list.

    AdjListEdges:
        Represents the adjacency list for a single vertex.
        Stores a pointer to the head of that vertex's linked list
        of neighbor nodes.

    AdjList:
        Represents the entire graph.
        Stores the number of vertices and an array of adjacency
        lists (one per vertex).
*/

typedef struct AdjListNode adj_list_node_t;
typedef struct AdjListEdges adj_list_edges_t;
typedef struct AdjList adj_list_t;

typedef struct AdjListNode
{
    size_t vertex;
    adj_list_node_t *next;
} adj_list_node_t;

typedef struct AdjListEdges
{
    adj_list_node_t *head;
} adj_list_edges_t;

typedef struct AdjList
{
    size_t vertices;
    adj_list_edges_t *edges;
} adj_list_t;

adj_list_t *init_adj_list(size_t vertices)
{
    if (vertices == 0)
    {
        printf("Bruh\n");
        return NULL;
    }

    adj_list_t *graph = malloc(sizeof(adj_list_t));

    if (graph == NULL)
    {
        printf("Failed to allocate memory for the adj list\n");
        return NULL;
    }

    graph->vertices = vertices;
    graph->edges = calloc(vertices, sizeof(adj_list_edges_t));

    if (graph->edges == NULL)
    {
        printf("Failed to allocate memory for the adj list edges\n");
        free(graph);
        return NULL;
    }

    return graph;
}

void free_adj_list(adj_list_t *graph)
{
    if (graph == NULL)
    {
        printf("Bruh\n");
        return;
    }

    for (size_t i = 0; i < graph->vertices; i++)
    {
        adj_list_node_t *curr = graph->edges[i].head;

        while (curr)
        {
            adj_list_node_t *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free(graph->edges);
    free(graph);
}

void print_adj_list(adj_list_t *graph)
{
    if (graph == NULL)
    {
        printf("Bruh\n");
        return;
    }

    for (size_t i = 0; i < graph->vertices; i++)
    {
        printf("%zu -> ", i);

        adj_list_node_t *curr = graph->edges[i].head;

        while (curr)
        {
            printf("%zu ", curr->vertex);
            curr = curr->next;
        }

        printf("\n");
    }
}

bool adj_list_edge_exists(adj_list_t *graph, size_t src, size_t dst)
{
    adj_list_node_t *curr = graph->edges[src].head;

    while (curr)
    {
        if (curr->vertex == dst)
        {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

adj_list_node_t *create_adj_list_node(size_t vertex)
{
    adj_list_node_t *node = malloc(sizeof(adj_list_node_t));

    if (node == NULL)
    {
        printf("Failed to allocate memory for the adj list node\n");
        return NULL;
    }

    node->vertex = vertex;
    node->next = NULL;

    return node;
}

void add_edge_in_adj_list(adj_list_t *graph, size_t src, size_t dst, bool directed)
{
    if (graph == NULL)
    {
        printf("Bruh\n");
        return;
    }

    if (src >= graph->vertices || dst >= graph->vertices)
    {
        printf("Invalid edge: %zu -> %zu\n", src, dst);
        return;
    }

    // Check for duplicates
    if (!adj_list_edge_exists(graph, src, dst))
    {
        adj_list_node_t *new_node = create_adj_list_node(dst);

        if (new_node == NULL)
        {
            printf("Failed to allocate memory for the adj list dst node\n");
            return;
        }

        new_node->next = graph->edges[src].head;
        graph->edges[src].head = new_node;
    }

    // Check for duplicates again
    if (!directed && !adj_list_edge_exists(graph, dst, src))
    {
        adj_list_node_t *new_node = create_adj_list_node(src);

        if (new_node == NULL)
        {
            printf("Failed to allocate memory for the adj list src node\n");
            return;
        }

        new_node->next = graph->edges[dst].head;
        graph->edges[dst].head = new_node;
    }
}
