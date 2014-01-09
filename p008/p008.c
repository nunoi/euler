/*
 * Find greatest product of five consecutive digits 
 * in the 1000 digit number
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * read text files into char array 
 * this will not work very well on huge files
 * returns 
 * NULL on failure
 * pointer to char* on success 
 */
char *read_file(const char *fname) {
    FILE *fp;
    long int fsize;
    char *content;

    content = NULL;
    fp = fopen(fname, "rb");
    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        fsize = ftell(fp);
        rewind(fp);
        content = (char *) malloc((fsize + 1) * sizeof(char));
        fread(content, sizeof(char), fsize, fp);
        content[fsize] = '\0';
    }
    return content;
}

char *get_substr(char *a, int pos, int len)
{
    char *s;
    int i;

    s = (char *) malloc(sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        s[i] = *(a + i + pos);
    }
    s[i] = '\0';
    return s;
}

int generate_products(int *p)
{
    int size = 0;

    return size;
}

int find_greatest_product(int *p, size_t size, char *a)
{
    int len, res, i, j;

    res = 0;
    len = strlen(a);
    for (i = 0; i < size; i++) {
        /* 59049 is largest product, so 5+1 is enough to hold number 
         * and null character */
        char prod[6];
        int l;

        l = sprintf(prod, "%d", p[i]);
        for (j = 0; j < len - l; j++) {
            char *substr;

            substr = get_substr(a, j, l);
            printf("prod: %s - substr: %s\n", prod, substr);
            if (strncmp(prod, substr, l) == 0) {
                if (res < p[i]) {
                    res = p[i];
                }
            }
            free(substr);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    char *a;
    int *table, size, res;

    a = NULL;
    table = NULL;
    size = 0;
    res = 0;

    a = read_file("p008_number.txt");
    size = generate_products(table);
    res = find_greatest_product(table, size, a);

    printf("Greatest product is %d\n", res);

	return 0;
}

