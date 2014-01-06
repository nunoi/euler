#!/usr/bin/python

import sys
import mutils

# i is the accumulated number of primes
i = 2
# n is the number to be tested
n = 3 

while i != 10001:
	n = n + 2
	if mutils.is_prime(n):
		i = i + 1
#		print i
print "The 10001st prime is: " + str(n)

