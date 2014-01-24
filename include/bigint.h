
#ifndef BIGINT_H
#define BIGINT_H

/* simple big integer library 
 * for now it is only base 10 and only has
 * functions to create and add big ints */

#define BASE 10

typedef struct bi_t {
    uint8_t *bi;
    int base;
    int size;
} bi_t;

bi_t *bi_init(int base);
void bi_set(bi_t *bi, char *str);
void bi_add(bi_t *res, bi_t *bi1, bi_t *bi2);
void bi_print(bi_t *bi);

#endif // BIGINT_H
