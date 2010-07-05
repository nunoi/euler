#!/usr/bin/python

import os

numlist = []

f = open("p013.txt", "r")
for line in f:
    numlist.append(int(line))

total = 0
for num in numlist:
    total = total + num
print total
a = str(total)
print a[:10]

