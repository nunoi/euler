
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "list.h"
#include "mathutil.h"

prime_factor_t *create_prime_factor(unsigned long long p)
{
    prime_factor_t *pf;

    pf = (prime_factor_t *) malloc(sizeof(prime_factor_t));
    pf->prime = p;
    pf->count = 0;
    return pf;
}

/* A function to get all prime factors of a given number n from
 * http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/ */
list_t *get_prime_factors(unsigned long long n)
{
    list_t *l;
    prime_factor_t *p;

    l = list_create();
    /* Print the number of 2s that divide n */
    p = create_prime_factor(2);
    while (n % 2 == 0)
    {
        /* printf("%d ", 2); */
        n = n / 2;
        p->count++;
    }
    list_add(l, p);

    unsigned long long i;
    /* n must be odd at this point. 
     * So we can skip one element (Note i = i +2) */
    for (i = 3; i <= sqrt(n); i = i + 2) {
        /* While i divides n, print i and divide n */
        p = create_prime_factor(i);
        while (n % i == 0) {
            /* printf ("%llu\n", i); */
            p->count++;
            n = n / i;
        }
        list_add(l, p);
    }
 
    /* This condition is to handle the case when n is a prime number
     * greater than 2 */
    if (n > 2) {
        p = create_prime_factor(n);
        p->count = 1;
        /* printf ("%llu\n", n); */
        list_add(l, p);
    }
    return l;
}

unsigned int *prime_generator()
{
    unsigned int i, j;
    unsigned int *table;

    table = malloc(PRIME_LIMIT * sizeof(unsigned int));

    table[0] = 0;
    table[1] = 0;

    for (i = 2; i <= PRIME_LIMIT; i++) {
        table[i] = 1;
    }

    for (i = 2; i < sqrt(PRIME_LIMIT); i++) {
        if (table[i] == 1) {
            for (j = i * i; j < PRIME_LIMIT; j += i) {
                table[j] = 0;
            }
        }
    }
    return table;
}

unsigned long long *triangle_number_generator()
{
    int i, stop;
    unsigned long long *table, tn;

    stop = 0;
    i = 1;
    tn = 0;
    table = (unsigned long long *) \
            malloc(sizeof(unsigned long long) * TRIANGLE_LIMIT);
    while(i < TRIANGLE_LIMIT) {
        tn = tn + (unsigned long long) i;
        table[i - 1] = tn;
        /* printf("%llu\n", tn); */
        i++;
    }
    return table;
}

