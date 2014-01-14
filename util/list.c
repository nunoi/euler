/*
 * Implementation of double linked list
 */

#include <stdlib.h>
#include "list.h"

list_t *list_create()
{
    list_t *l;

    l = (list_t *) malloc(sizeof(list_t));
    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return l;
}

void list_destroy(list_t *list)
{
    lnode_t *node = list->first;

    while (node->next) {
        free(node->data);
        node = node->next;
        free(node->prev);
    }
    free(node->data);
    free(node);
}

void list_add(list_t *list, void *data)
{
    lnode_t *node = (lnode_t *) malloc(sizeof(lnode_t));

    node->data = data;
    if (list->count == 0) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    list->count++;
    return;
}

void list_remove(list_t *list, lnode_t *node)
{
}

