/*
 * Sum of all primes below 2 million
 */

#include <stdio.h>
#include "mathutil.h"

int main(int argc, char *argv[])
{
    unsigned int *primes;
    int i;
    unsigned long long sum;

    sum = 0;
    primes = prime_generator();
    for (i = 0; i < PRIME_LIMIT; i++) {
        if (primes[i]) {
            sum += i;
        }
    }
    printf("The sum of all primes < 2000000 is %llu\n", sum);
    return 0;
}

