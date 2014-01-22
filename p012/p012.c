
#include <stdio.h>
#include "mathutil.h"

int main(int argc, char *argv[])
{
    unsigned int *tn;
    int i;

    tn = triangle_number_generator();
    for(i = 0; i < TRIANGLE_LIMIT; i++) {
        printf("%d\n", tn[i]);
    }
	return 0;
}

