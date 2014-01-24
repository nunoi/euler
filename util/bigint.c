
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bigint.h"

bi_t *bi_init(int base)
{
    bi_t *bi;

    bi = (bi_t *) malloc(sizeof(bi_t) + 1);
    bi->base = base;
    bi->size = 0;
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
    res->size = biggest + 1;
    num = (uint8_t *) malloc(sizeof(uint8_t) * (biggest + 1));
    while(i <= biggest + 1) {
        p1 = i > bi1->size ? 0 : bi1->bi[i];
        p2 = i > bi2->size ? 0 : bi2->bi[i];
        tmp = p1 + p2 + carry;
        if (tmp >= res->base) {
            tmp = tmp - res->base;
            carry = 1;
        } else {
            carry = 0;
        }
        num[i] = tmp;
/*
        printf("bi1: %d bi2: %d carry: %d\n", bi1->bi[i], bi2->bi[i], carry);
        printf("num[%d]: %d\n", i, num[i]);
*/
        i++;
    }
    if (num[i] == 0) {
        uint8_t *trunc_num;

        printf("truncated. was %d and is now 1 less\n", res->size);
        res->size--;
        trunc_num = (uint8_t *) malloc(sizeof(uint8_t) * res->size);
        for(i = 0; i < res->size; i++) {
            trunc_num[i] = num[i];
        }
        res->bi = trunc_num;
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


