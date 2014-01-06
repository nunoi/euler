/*
 * Largest palindrome made from product of two 2-digit numbers is
 * 9009 = 91 * 99
 *
 * What is largest palindrome from product of two 3-digit numbers ?
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUMBER 999
#define MAX_PRODUCT (MAX_NUMBER * MAX_NUMBER)

int is_palindrome(int n)
{
    int i, j;
    int nlen;
    int palindrome = 1;
    char s[32];
    char s1[16], s2[16];

    sprintf(s, "%d", n);
    nlen = strlen(s);

    for (i = 0; i < nlen / 2; i++) {
        s1[i] = s[i];
        s2[i] = s[nlen - 1 - i];
    }
    s1[i + 1] = '\0';
    s2[i + 1] = '\0';

    if (strncmp(s1, s2, nlen / 2) != 0) {
        palindrome = 0;
    }

    return palindrome;
}

int main(int argc, char *argv[])
{
    int i, j;
    int largest = 0;
    
    for (i = MAX_NUMBER; i > 0; i--) {
        for (j = MAX_NUMBER; j > 0; j--) {
            //printf("%d x %d\n", i, j);
            if (is_palindrome(i * j)) {
                if (i * j > largest) {
                    largest = i * j;
                }
                //printf("Found palindrome %d. Largest yet is %d\n", i * j, largest);
            }
        }
    }
    /*if (is_palindrome(23432)) {
        printf("IT WORKS!\n");
    }*/
    printf("Largest palindrome of multiplication of " \
           "two 3-digit numbers is %d\n", largest);
    return(0);
}

