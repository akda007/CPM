#ifndef LINKED_LIST_H
#define LINKED_LIST_H

    #include <stdlib.h>
    #include <stdbool.h>
    #include <assert.h>

    typedef void (*callback_print) (void *data);
    typedef bool (*callback_compare) (void *data1, void *data2);

    struct Node
    {
        void *data;
        struct Node *next;
        callback_print cprint;
        callback_compare ccompare;
    };

    typedef struct
    {
        struct Node *head;
        struct Node *tail;
        unsigned length;
    } LinkedList;

    struct Node * init_node(void *data, callback_print cprint, callback_compare ccompare);
    void free_node(struct Node *node);

    LinkedList * init_list(void);
    void append_list(LinkedList *list, struct Node *node);
    void * fetch_index_list(LinkedList *list, unsigned index);
    void free_list(LinkedList *list);

#endif