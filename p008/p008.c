/*
 * Find greatest product of five consecutive digits 
 * in the 1000 digit number
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int get_digit(int number, int pos)
{
    number /= pow(10, pos);
    return number % 10;
}

int get_product(int number)
{
    int i;
    int prod;

    prod = 1;
    for (i = 0; i < 5; i++) {
        int p;
        p = get_digit(number, i);
        prod = prod * p;
    }
    /*printf("digits %d - product %d\n", number, prod);*/
    return prod;
}

int find_greatest_product(char *a)
{
    int len, res, i;
    int digits, prod;

    digits = 5;
    res = 0;
    len = strlen(a);
    for (i = 0; i < len - digits; i++) {
        char *substr;
 
        substr = get_substr(a, i, digits);
        prod = get_product(atoi(substr));
        /* printf("prod: %s - substr: %s\n", prod, substr); */
        if (res < prod) {
            res = prod;
        }
        free(substr);
   }
    return res;
}

int main(int argc, char *argv[])
{
    char *a;
    int res;

    a = NULL;
    res = 0;

    a = read_file("p008_number.txt");
    res = find_greatest_product(a);

    free(a);

    printf("Greatest product is %d\n", res);

	return 0;
}

