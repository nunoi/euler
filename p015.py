#!/usr/bin/python

# see http://www.joaoff.com/2008/01/20/a-square-grid-path-problem/


def fac(n):
    if n == 1:
        return 1
    else:
        return n*fac(n-1)

n = 20
numerator = fac(2*n)
denominator = fac(n) * fac(n)

res = numerator/denominator
print res

