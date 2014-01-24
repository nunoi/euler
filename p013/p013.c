
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bigint.h"

#define LIST_SIZE 100
#define NUMBER_SIZE 50

char **read_file(const char *fname) {
    FILE *fp;
    char **data;
    char *num;
    int i;

    i = 0;
    data = (char **) malloc(sizeof(char *) * LIST_SIZE);
    num = (char *) malloc(sizeof(char) * NUMBER_SIZE);
    fp = fopen(fname, "rb");
    if (fp != NULL) {
        data[i++] = num;
        while (fscanf(fp, "%s", num) != EOF) {
            num = (char *) malloc(sizeof(char) * NUMBER_SIZE);
            data[i++] = num;
        }
        data[i] = '\0';
    }
    fclose(fp);
    return data;
}

int main(int argc, char *argv[])
{
    char **data;
    bi_t *bi, *bi_sum, *bi_tmp;
    bi_t *bi1, *bi2, *bi3;
    bi_t *list_bi[LIST_SIZE];
    int i;

    data = read_file("p013.txt");
    for(i = 0; i < LIST_SIZE; i++) {
        bi = bi_init(10);
        bi_set(bi, data[i]);
        list_bi[i] = bi;
    }
    bi_sum = bi_init(10);
    bi_tmp = bi_init(10);
    bi_set(bi_tmp, "0");
    bi_add(bi_sum, list_bi[0], list_bi[1]);
        bi_print(bi_sum);
    for(i = 2; i < LIST_SIZE - 1; i++) {
        bi_add(bi_sum, bi_sum, list_bi[i]);
        /*bi_sum = bi_tmp;*/
        bi_print(bi_sum);
    }
    
     bi1 = bi_init(10);
    bi2 = bi_init(10);
    bi3 = bi_init(10);
    bi_set(bi1, "83484225211392112511446123117807668296927154000788");
    bi_set(bi2, "74324986199524741059474233309513058123726617309629");
    bi_add(bi3, bi1, bi2);
    bi_print(bi1);
    bi_print(bi2);
    bi_print(bi3);
	return 0;
}

