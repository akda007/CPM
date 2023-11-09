#include "linked_list.h"

struct Node * init_node(void *data, callback_print cprint, callback_compare ccompare)
{
    assert(data != NULL);

    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->cprint = cprint;
    new_node->ccompare = ccompare;

    return new_node;
}

void free_node(struct Node *node)
{
    free(node);
}

LinkedList * init_list(void)
{
    LinkedList *new_list = malloc(sizeof(LinkedList));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->length = 0;

    return new_list;
}

void append_list(LinkedList *list, struct Node *node)
{
    assert(list != NULL);
    assert(node != NULL);

    if (list->head != NULL)
        list->head->next = node;
        
    list->head = node;
    list->length++;
}

void * fetch_index_list(LinkedList *list, unsigned index)
{
    assert(list != NULL);
    assert(index < list->length);

    struct Node *current_node = list->tail;
    for (int i = 1; i < index; i++)
    {
        current_node = current_node->next;
    }

    return current_node->data;
}

void free_list(LinkedList *list)
{
    struct Node *current_node = list->tail, *next_node;

    for (int i = 0; i < list->length; i++)
    {
        if (current_node->next != NULL)
        {
            next_node = current_node->next;
        }
        free_node(current_node);
        current_node = next_node;
    }

    free(list);
}