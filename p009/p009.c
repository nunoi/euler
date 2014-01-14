/*
 * Pythagorean triplet
 * a < b < c, for which a^2 + b^2 = c^2
 *
 * find triplet for which a + b + c = 1000
 */

#include <stdio.h>
#include <stdlib.h>

#define SUM 1000
#define SIZE 100000

typedef struct {
    int a;
    int b;
    int c;
} triplet;

triplet *get_triplets(int sum)
{
    int i, j, k;
    int n;
    triplet *cand;

    n = 0;
    cand = (triplet *) malloc(SIZE * sizeof(triplet));
    for (i = 1; i < sum; i++) {
        for (j = i; j < sum; j++) {
            for (k = j; k < sum; k++) {
                if (i + j + k == sum) {
                    cand[n].a = i;
                    cand[n].b = j;
                    cand[n].c = k;
                    n++;
                }
            }
        }
    }
    return cand;
}

triplet check_triplets(triplet cand[])
{
    int i;

    for (i = 0; i < SIZE; i++) {
        int a, b, c;
        a = cand[i].a;
        b = cand[i].b;
        c = cand[i].c;
        if (a * a + b * b == c * c) {
            return cand[i];
        }
    }
}

int main(int argc, char *argv[])
{
    triplet *candidates, res;

    candidates = get_triplets(SUM);
    res = check_triplets(candidates);
    printf("The triplet for which a^2 + b^2 = c^2 is:\n");
    printf("a: %d; b: %d; c: %d\n", res.a, res.b, res.c);
    printf("Their product is: %d\n", res.a * res.b * res.c);
	return 0;
}

