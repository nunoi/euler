/*
 * Find the greatest product of four adjacent numbers in same direction
 * in the grid
 */

/* size of grid is 20x20 */
#define SIZE 400
#define COLS 20
#define LINES 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *read_file(const char *fname) {
    FILE *fp;
    int *data;
    int num, i;

    i = 0;
    data = (int *) malloc(sizeof(int) * SIZE);
    fp = fopen(fname, "rb");
    if (fp != NULL) {
        while (fscanf(fp, "%d", &num) != EOF) {
            data[i++] = num;
        }
    }
    fclose(fp);
    return data;
}

/* TODO: this function is ugly, should be made into something
 * more simple and elegant */
int get_greatest_product(int *d)
{
    int i, j;
    int prod;

    prod = 0;
    for(i = 0; i < COLS - 3; i++) {
        for(j = 0; j < LINES - 3; j++) {
            int p;
            int lpos;

            printf("[%d, %d]\n", i, j);
            p = 0;
            /* horizontal */
            lpos = j * COLS;
            p = (*(d + i + lpos)) *\
                (*(d + i + 1 + lpos)) *\
                (*(d + i + 2 + lpos)) *\
                (*(d + i + 3 + lpos));
            if (p > prod) {
                prod = p;
            }
            /* vertical */
            p = (*(d + i + lpos)) *\
                (*(d + i + ((j + 1) * COLS))) *\
                (*(d + i + ((j + 2) * COLS))) *\
                (*(d + i + ((j + 3) * COLS)));
            if (p > prod) {
                prod = p;
            }
            /* diagonal from top left to bottom right*/
            p = (*(d + i + lpos)) *\
                (*(d + i + 1 + ((j + 1) * COLS))) *\
                (*(d + i + 2 + ((j + 2) * COLS))) *\
                (*(d + i + 3 + ((j + 3) * COLS)));
            if (p > prod) {
                prod = p;
            }
            /* diagonal from bottom left to top right*/
            p = (*(d + i + 3 + lpos)) *\
                (*(d + i + 2 + ((j + 1) * COLS))) *\
                (*(d + i + 1 + ((j + 2) * COLS))) *\
                (*(d + i + ((j + 3) * COLS)));
            if (p > prod) {
                prod = p;
            }
        }
    }
    return prod;
}

int main(int argc, char *argv[])
{
    char fname[] = "p011_grid.txt";
    int *data;
    int prod;

    data = read_file(fname);
    prod = get_greatest_product(data);
    printf("Greatest product is %d\n", prod);
	return 0;
}

