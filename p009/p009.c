/*
 * Pythagorean triplet
 * a < b < c, for which a^2 + b^2 = c^2
 *
 * find triplet for which a + b + c = 1000
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SUM 1000

typedef struct triplet_t {
    int a;
    int b;
    int c;
} triplet_t;

void get_triplets(int sum, list_t *list)
{
    int i, j, k;
    triplet_t *cand;

    for (i = 1; i < sum; i++) {
        for (j = i; j < sum; j++) {
            for (k = j; k < sum; k++) {
                if (i + j + k == sum) {
                    cand = (triplet_t *) malloc(sizeof(triplet_t));
                    cand->a = i;
                    cand->b = j;
                    cand->c = k;
                    list_add(list, cand);
                }
            }
        }
    }
}

triplet_t *check_triplets(list_t *list)
{
    lnode_t *n;

    n = list->first;
    while (n->next) {
        int a, b, c;
        triplet_t *t;

        t = n->data;
        a = t->a;
        b = t->b;
        c = t->c;
        if (a * a + b * b == c * c) {
            return t;
        }
        n = n->next;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    list_t *candidates;
    triplet_t *res;

    candidates = list_create();
    get_triplets(SUM, candidates);
    res = check_triplets(candidates);
    printf("The triplet for which a^2 + b^2 = c^2 is:\n");
    printf("a: %d; b: %d; c: %d\n", res->a, res->b, res->c);
    printf("Their product is: %d\n", res->a * res->b * res->c);
    list_destroy(candidates);
	return 0;
}

