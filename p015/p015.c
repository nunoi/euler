/*
 * Find number of routes in a 20x20 grid
 */

#include <stdio.h>
#include "mathutil.h"

#define HORIZ 20
#define VERT 20

int main(int argc, char *argv[])
{
    int h, v;
    unsigned long long res;

    h = HORIZ;
    v = VERT;
    res = combination(h + v, h);
    printf("Number of paths is %llu\n", res);
	return 0;
}

