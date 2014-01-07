/*
 *
 * What is the smallest number evenly divisible by
 * all numbers from 1 to 20 ?
 *
 */
#include <stdio.h>

/* checks if n is divisible by all numbers from 1 to 20 */
int is_divisible(int n) 
{
    int res = 0;
    int i;

    for (i = 2; i <= 20; i++) {
        if (n % i != 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int i = 21;
    int divisible = 0;

    while (!divisible) {
        i++;
        if (is_divisible(i)) {
            printf("Smallest number divisible by [1..20] is %d\n", i);
            return(0);
        }
   }
}

