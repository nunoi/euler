
#include <stdio.h>
#include "list.h"
#include "mathutil.h"

int main(int argc, char *argv[])
{
    unsigned long long *tn;
    unsigned long long i;
    list_t *list;
    lnode_t *node;
    prime_factor_t *p;
    int nfactors;

/*    list = get_prime_factors(72);
    node = list->first;
    while(node) {
        prime_factor_t *p;
        
        p = node->data;
        printf("%llu ^ %llu\n", p->prime, p->count);
        node = node->next;
    } */

    tn = triangle_number_generator();
    for(i = 0; i < TRIANGLE_LIMIT; i++) {
        nfactors = 1;
        list = get_prime_factors(tn[i]);
        node = list->first;
        while(node) {
            p = node->data;
            nfactors *= p->count;
            printf("counted %d factors for t.n. %llu\n", nfactors, tn[i]);
            if (nfactors >= 500) {
                printf("%llu\n", tn[i]);
                return 0;
            }
            if (tn[i] > 28) {
                return 0;
            }
            node = node->next;
        }
    }
	return 1;
}

