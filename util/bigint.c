
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bigint.h"

bi_t *bi_init(int base)
{
    bi_t *bi;

    bi = (bi_t *) malloc(sizeof(bi_t));
    bi->base = base;
    bi->size = 0;
    bi->bi = NULL;
    return bi;
}

void bi_set(bi_t *bi, char *str)
{
    uint8_t *n;
    int i, len;

    len = strlen(str);
    if (len <= 0) {
        return;
    }
    i = 0;
    bi->size = len;
    n = (uint8_t *) malloc(sizeof(uint8_t) * len);
    while(len > 0) {
        n[--len] = (*str++ - '0');
    }
    bi->bi = n;
}

void bi_add(bi_t *res, bi_t *bi1, bi_t *bi2)
{
    uint8_t carry, tmp;
    uint8_t *num;
    int biggest, i, p1, p2;

    carry = 0;
    i = 0;
    biggest = bi1->size > bi2->size ? bi1->size : bi2->size;
    res->size = biggest;
    num = (uint8_t *) malloc(sizeof(uint8_t) * (res->size));
    while(i < res->size) {
        p1 = i >= bi1->size ? 0 : bi1->bi[i];
        p2 = i >= bi2->size ? 0 : bi2->bi[i];
        tmp = p1 + p2 + carry;
        if (tmp >= res->base) {
            tmp = tmp - res->base;
            carry = 1;
        } else {
            carry = 0;
        }
        num[i] = tmp;
        i++;
/*
        printf("p1: %d p2: %d carry: %d\n", p1, p2, carry);
        printf("num[%d]: %d\n", i, num[i]);
*/
    }
    if (carry == 1) {
        uint8_t *extra_num;

        extra_num = (uint8_t *) malloc(sizeof(uint8_t) * res->size + 1);
        for(i = 0; i < res->size; i++) {
            extra_num[i] = num[i];
        }
        extra_num[i] = carry;
        res->bi = extra_num;
        res->size++;
        free(num);
    } else {
        res->bi = num;
    }
}

void bi_print(bi_t *bi)
{
    uint8_t *c;
    int len;

    c = bi->bi;
    len = bi->size - 1;
    while(len >= 0) {
        printf("%d", c[len--]);
    }
    printf("\n");
}

void bi_clear(bi_t *bi)
{
    free(bi->bi);
    bi->bi = NULL;
}

