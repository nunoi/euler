#!/usr/bin/python

def seq_iter(n):
    if n % 2 == 0:
        return n/2
    else:
        return 3*n+1

def seq(n):
    res = []
    res.append(n)
    while n != 1:
        n = seq_iter(n)
        res.append(n)
    return res

iters = []
last = []
for i in range(1, 1000000):
    if i % 100000 == 0:
        print i
    new = seq(i)
    if len(new) > len(last):
        last = new
print last

