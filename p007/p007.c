
#include <stdio.h>
#include "mathutil.h"

#define TARGET 10001

int main(int argc, char *argv[])
{
    unsigned int i;
    unsigned int *a;
    int count = 0;

    a = prime_generator();
    for (i = 0; i <= PRIME_LIMIT; i++) {
        if (a[i] == 1) {
            count++;
            if (count == TARGET) {
                printf("The 10001st prime is %u\n", i);
            }
        }
    }
    printf("Counted %d primes\n", count);

	return 0;
}

