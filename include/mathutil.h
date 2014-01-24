
#ifndef MATHUTIL_H
#define MATHUTIL_H

/* This limit is more than enough for problem 7 and 10 */
#define PRIME_LIMIT 2000000
#define TRIANGLE_LIMIT 2000000

typedef struct prime_factor_t {
    unsigned long long prime;
    int count;
} prime_factor_t;

unsigned int *prime_generator();
unsigned long long *triangle_number_generator();
list_t *get_prime_factors(unsigned long long n);

#endif

