/*
 * This program finds the prime factors of a number.
 * The problem is to find the largest prime factor.
 */

#include <stdio.h>
#include <math.h>
#include <stdint.h>

/* A function to print all prime factors of a given number n from
 * http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/ */
void prime_factors(unsigned long long n)
{
    /* Print the number of 2s that divide n */
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }

    unsigned long long i;
    /* n must be odd at this point. 
     * So we can skip one element (Note i = i +2) */
    for (i = 3; i <= sqrt(n); i = i + 2)
    {
        /* While i divides n, print i and divide n */
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }
 
    /* This condition is to handle the case whien n is a prime number
     * greater than 2 */
    if (n > 2)
        printf ("%d\n", n);
}

int main(int argc, char *argv[])
{
    unsigned long long number = 600851475143ULL;
    prime_factors(number);
    return(0);
}

