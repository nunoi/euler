
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
    data = (char **) malloc(sizeof(char *) * (LIST_SIZE));
    num = (char *) malloc(sizeof(char) * (NUMBER_SIZE + 1));
    fp = fopen(fname, "rb");
    if (fp != NULL) {
        data[i++] = num;
        while (fscanf(fp, "%s\n", num) != EOF) {
            num = (char *) malloc(sizeof(char) * (NUMBER_SIZE + 1));
            data[i++] = num;
        }
    }
    fclose(fp);
    return data;
}

int main(int argc, char *argv[])
{
    char **data;
    bi_t *bi, *bi_sum, *bi_tmp;
    bi_t *list_bi[LIST_SIZE];
    int i;

    data = read_file("p013.txt");
    for(i = 0; i < LIST_SIZE; i++) {
        bi = bi_init(10);
        bi_set(bi, data[i]);
        list_bi[i] = bi;
        free(data[i]);
    }
    free(data);
    bi_sum = bi_init(10);
    bi_tmp = bi_init(10);
    bi_add(bi_sum, list_bi[0], list_bi[1]);
    for(i = 2; i <  LIST_SIZE; i++) {
        bi_add(bi_tmp, bi_sum, list_bi[i]);
        bi_sum = bi_tmp;
        bi_clear(list_bi[i]);
        free(list_bi[i]);
    }
    bi_print(bi_sum);
    bi_clear(bi_tmp);
    free(bi_tmp);
/*
    bi_t *bi1, *bi2, *bi3;
    
    bi1 = bi_init(10);
    bi2 = bi_init(10);
    bi3 = bi_init(10);
    bi_set(bi1, "1032263336663025168502381235602306604786810161963932");
    bi_set(bi2, "71693888707715466499115593487603532921714970056938");
    bi_add(bi3, bi1, bi2);
    bi_print(bi1);
    bi_print(bi2);
    bi_print(bi3);
    */
	return 0;
}

