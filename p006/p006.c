/*
 * Difference between sum of quares and square of sums
 * of the first 100 natural numbers
 */
#include <stdio.h>

#define TARGET 100

int sum_squares(int n)
{
    int i;
    int res = 0;

    for (i = 1; i <= n; i++) {
        res += i * i;
    }
    return res;
}

int square_sums(int n) {
    int i;
    int res = 0;

    for (i = 1; i <= n; i++) {
        res += i;
    }
    return res * res;
}

int main(int argc, char *argv[])
{
    printf("Square of sums is %d\n", square_sums(TARGET));
    printf("Sum of squares is %d\n", sum_squares(TARGET));
    printf("Difference is %d\n", square_sums(TARGET) - sum_squares(TARGET));
    return 0;
}

