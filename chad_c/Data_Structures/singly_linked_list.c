#include <stdio.h>
#include <stdlib.h>

typedef struct SingleNode single_node_t;
typedef struct SinglyLinkedList singly_linked_list_t;

typedef struct SingleNode
{
    int data;
    single_node_t *next;
} single_node_t;

typedef struct SinglyLinkedList
{
    single_node_t *head;
    single_node_t *tail;
    size_t size;
} singly_linked_list_t;

singly_linked_list_t *init_sll()
{
    singly_linked_list_t *list = malloc(sizeof(singly_linked_list_t));

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

void free_sll(singly_linked_list_t *list)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return;
    }

    single_node_t *curr = list->head;

    while (curr)
    {
        single_node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

void print_sll(singly_linked_list_t *list)
{
    if (list == NULL || list->head == NULL || list->size == 0)
    {
        printf("Bruh\n");
        return;
    }

    single_node_t *curr = list->head;

    while (curr)
    {
        if (curr == list->head)
        {
            if (curr->next == NULL)
            {
                printf("[Head: %d] --> NULL\n", curr->data);
                return;
            }

            printf("[Head: %d] --> ", curr->data);
        }

        else if (curr == list->tail)
        {
            printf("[Tail: %d] --> NULL\n", curr->data);
            return;
        }

        else
        {
            printf("[%d] --> ", curr->data);
        }

        curr = curr->next;
    }
}

single_node_t *prepend_sll(singly_linked_list_t *list, int data)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return NULL;
    }

    single_node_t *new_node = malloc(sizeof(single_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = list->head;

    list->head = new_node;

    if (list->tail == NULL)
    {
        list->tail = new_node;
    }

    list->size++;
    return new_node;
}

single_node_t *append_sll(singly_linked_list_t *list, int data)
{
    if (list == NULL)
    {
        printf("Bruh\n");
        return NULL;
    }

    single_node_t *new_node = malloc(sizeof(single_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->tail)
    {
        list->tail->next = new_node;
    }

    list->tail = new_node;

    if (list->head == NULL)
    {
        list->head = new_node;
    }

    list->size++;
    return new_node;
}

single_node_t *insert_node_sll(singly_linked_list_t *list, int data, size_t i)
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
        return prepend_sll(list, data);
    }

    if (i == list->size)
    {
        return append_sll(list, data);
    }

    single_node_t *curr = list->head;

    while (i > 1)
    {
        curr = curr->next;
        i--;
    }

    single_node_t *new_node = malloc(sizeof(single_node_t));

    if (new_node == NULL)
    {
        printf("Failed to create new node\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = curr->next;
    curr->next = new_node;

    list->size++;
    return new_node;
}

int remove_node_sll(singly_linked_list_t *list, int key)
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

    single_node_t *curr = list->head;
    single_node_t *prev = NULL;

    while (curr)
    {
        if (curr->data == key)
        {
            if (curr == list->head)
            {
                list->head = curr->next;

                if (list->head == NULL)
                {
                    list->tail = NULL;
                }
            }

            else
            {
                prev->next = curr->next;

                if (curr == list->tail)
                {
                    list->tail = prev;
                }
            }

            free(curr);
            list->size--;
            return key;
        }

        prev = curr;
        curr = curr->next;
    }

    return -1;
}
