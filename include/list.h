/*
 * double linked list
 */

#ifndef LIST_H
#define LIST_H

struct lnode_t;

typedef struct lnode_t {
    struct lnode_t *next;
    struct lnode_t *prev;
    void *data;
} lnode_t;

typedef struct list {
    int count;
    lnode_t *first;
    lnode_t *last;
} list_t;

#define LIST_COUNT(A) ((A)->count)
#define LIST_FIRST(A) ((A)->first != NULL ? (A)->first->data : NULL)
#define LIST_LAST(A) ((A)->last != NULL ? (A)->last->data : NULL)

list_t *list_create();
void list_destroy(list_t *list);
void list_add(list_t *list, void *d);
void list_remove(list_t *list, lnode_t *node);

#endif /* LIST_H */

