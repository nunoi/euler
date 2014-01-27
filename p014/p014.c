/*
 * Find starting number of longest Collatz sequence
 * whose starting number is under one million
 */

#include <stdio.h>

#define UPLIMIT 999999
unsigned int collatz(unsigned int start)
{
    unsigned int n, count;

    count = 1;
    n = start;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    int n, number, res, nterms;

    n = UPLIMIT;
    nterms = 0;
    while (n > 1) {
        res = collatz(n);
        if (res > nterms) {
            nterms = res;
            number = n;
        }
        n--;
    }
    printf("Longest Collatz sequence has %d terms\n", nterms);
    printf("Its starting point is %d\n", number);
	return 0;
}

