
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "mathutil.h"

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

unsigned int *triangle_number_generator()
{
    int i, stop;
    unsigned int *table, tn;

    stop = 0;
    i = 0;
    tn = 0;
    table = (unsigned int *) malloc(sizeof(unsigned int) * TRIANGLE_LIMIT);
    while(i < TRIANGLE_LIMIT) {
        tn = tn + i;
        table[i] = tn;
        printf("%d\n", tn);
        i++;
    }
    return table;
}

