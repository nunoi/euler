
#include <stdio.h>
#include "list.h"
#include "mathutil.h"

int count_prime_factors(lnode_t *node) {
    int n;
    prime_factor_t *pf;
    lnode_t *cur;
    
    n = 1;
    cur = node;
    while(cur) {
        pf = cur->data;
        n *= (pf->count + 1);
        /* printf("%llu - %d\n", pf->prime, pf->count); */
        cur = cur->next;
    }
    return n;
}	


int main(int argc, char *argv[])
{
    unsigned long long *tn;
    unsigned long long i;
    list_t *list;
    lnode_t *node;
    int nfactors;

    tn = triangle_number_generator();
    for(i = 0; i < TRIANGLE_LIMIT; i++) {
        nfactors = 1;
        list = get_prime_factors(tn[i]);
        node = list->first;
        nfactors = count_prime_factors(node);
        if (nfactors >= 500) {
            printf("Triangle number %llu has %d factors\n", tn[i], nfactors);
            return 0;
        }
        /* for debugging initially */
/*        if (tn[i] > 72) {
            return 0;
        } */
    }
	return 1;
}

