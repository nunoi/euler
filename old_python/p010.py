#!/usr/bin/python

import sys
import mutils

# Sieve approach
sum = 0
# problem was changed from 1.000.000 to 2.000.000
# primeList = mutils.prime_sieve(1000000)
primeList = mutils.prime_sieve(2000000)
for i in primeList:
	sum = sum + i
print sum
sys.exit(0)

# Brute force approach
# This is too slow - it takes around 150s (2.5 mins) in an Athlon XP 2600
sum = 2
# 1.000.000 is multiple of ten so we can end the checking at 999.999
for i in range(3, 1000000, 2):
	if mutils.is_prime(i):
		sum = sum + i
print sum

