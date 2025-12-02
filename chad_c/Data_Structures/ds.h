#ifndef DS_H
#define DS_H

#include <stddef.h>
#include <stdbool.h>

// ----- HEAP ----- //

typedef struct IntArray int_arr_t;

int _parent(size_t i);
int _left(size_t i, size_t size);
int _right(size_t i, size_t size);

void _sift_up(int_arr_t *heap, size_t i);
void _sift_down(int_arr_t *heap, size_t i);

void heapify(int_arr_t *arr);
void heap_push(int_arr_t *heap, int val);
int heap_pop(int_arr_t *heap);

// ----- HEAP ----- //

//

// ----- SINGLY LINKED LIST (SLL) ----- //

typedef struct SingleNode single_node_t;
typedef struct SinglyLinkedList singly_linked_list_t;

singly_linked_list_t *init_sll();
void free_sll(singly_linked_list_t *list);
void print_sll(singly_linked_list_t *list);

single_node_t *prepend_sll(singly_linked_list_t *list, int data);
single_node_t *append_sll(singly_linked_list_t *list, int data);
single_node_t *insert_node_sll(singly_linked_list_t *list, int data, size_t i);
int remove_node_sll(singly_linked_list_t *list, int key);

// ----- SINGLY LINKED LIST (SLL) ----- //

//

// ----- DOUBLY LINKED LIST (DLL) ----- //

typedef struct DoubleNode
{
    struct DoubleNode *prev;
    int data;
    struct DoubleNode *next;
} double_node_t;

typedef struct DoublyLinkedList
{
    double_node_t *head;
    double_node_t *tail;
    size_t size;
} doubly_linked_list_t;

doubly_linked_list_t *init_dll();
void free_dll(doubly_linked_list_t *list);
void print_dll(doubly_linked_list_t *list);

double_node_t *prepend_dll(doubly_linked_list_t *list, int data);
double_node_t *append_dll(doubly_linked_list_t *list, int data);
double_node_t *insert_node_dll(doubly_linked_list_t *list, int data, size_t i);
int remove_node_dll(doubly_linked_list_t *list, int key);

// ----- DOUBLY LINKED LIST (DLL) ----- //

//

// ----- ADJACENCY LIST ----- //

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

adj_list_t *init_adj_list(size_t vertices);
void free_adj_list(adj_list_t *graph);
void print_adj_list(adj_list_t *graph);
bool adj_list_edge_exists(const adj_list_t *graph, size_t src, size_t dst);

adj_list_node_t *create_adj_list_node(size_t vertex);
void add_edge_in_adj_list(adj_list_t *graph, size_t src, size_t dst, bool directed);

// ----- ADJACENCY LIST ----- //

#endif