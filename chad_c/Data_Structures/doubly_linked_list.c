#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleNode double_node_t;
typedef struct DoublyLinkedList doubly_linked_list_t;

typedef struct DoubleNode
{
    double_node_t *prev;
    int data;
    double_node_t *next;
} double_node_t;

typedef struct DoublyLinkedList
{
    double_node_t *head;
    double_node_t *tail;
    size_t size;
} doubly_linked_list_t;

doubly_linked_list_t *init_dll()
{
    doubly_linked_list_t *list = malloc(sizeof(doubly_linked_list_t));

    if (list == NULL)
    {
        printf("Failed to allocate memory\n");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void free_dll(doubly_linked_list_t *list)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return;
    }

    double_node_t *curr = list->head;

    while (curr)
    {
        double_node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

void print_dll(doubly_linked_list_t *list)
{
    if (list == NULL || list->head == NULL || list->size == 0)
    {
        printf("Bruh\n");
        return;
    }

    double_node_t *curr = list->head;

    while (curr)
    {
        if (curr == list->head)
        {
            if (curr->next == NULL)
            {
                printf("NULL <-- [Head: %d] --> NULL\n", curr->data);
                return;
            }

            printf("NULL <--> [Head: %d] <--> ", curr->data);
        }

        else if (curr == list->tail)
        {
            printf("[Tail: %d] <--> NULL\n", curr->data);
            return;
        }

        else
        {
            printf("[%d] <--> ", curr->data);
        }

        curr = curr->next;
    }
}

double_node_t *prepend_dll(doubly_linked_list_t *list, int data)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return NULL;
    }

    double_node_t *new_node = malloc(sizeof(double_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = list->head;

    if (list->head)
    {
        list->head->prev = new_node;
    }

    else
    {
        list->tail = new_node;
    }

    list->head = new_node;
    list->size++;

    return new_node;
}

double_node_t *append_dll(doubly_linked_list_t *list, int data)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return NULL;
    }

    double_node_t *new_node = malloc(sizeof(double_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->prev = list->tail;
    new_node->data = data;
    new_node->next = NULL;

    if (list->tail)
    {
        list->tail->next = new_node;
    }

    else
    {
        list->head = new_node;
    }

    list->tail = new_node;
    list->size++;

    return new_node;
}

double_node_t *insert_node_dll(doubly_linked_list_t *list, int data, size_t i)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return NULL;
    }

    if (i > list->size)
    {
        printf("Position is out of bound\n");
        return NULL;
    }

    if (i == 0)
    {
        return prepend_dll(list, data);
    }

    if (i == list->size)
    {
        return append_dll(list, data);
    }

    double_node_t *curr = list->head;

    while (i > 1)
    {
        curr = curr->next;
        i--;
    }

    double_node_t *new_node = malloc(sizeof(double_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->prev = curr;
    new_node->data = data;
    new_node->next = curr->next;

    curr->next->prev = new_node;
    curr->next = new_node;

    list->size++;
    return new_node;
}

int remove_node_dll(doubly_linked_list_t *list, int key)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return -1;
    }

    if (list->head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    double_node_t *curr = list->head;

    while (curr)
    {
        if (curr->data == key)
        {
            if (curr == list->head)
            {
                list->head = curr->next;

                if (list->head)
                {
                    list->head->prev = NULL;
                }

                else
                {
                    list->tail = NULL;
                }
            }

            else
            {
                curr->prev->next = curr->next;

                if (curr->next)
                {
                    curr->next->prev = curr->prev;
                }

                else
                {
                    list->tail = curr->prev;
                }
            }

            free(curr);
            list->size--;
            return key;
        }

        curr = curr->next;
    }

    return -1;
}
