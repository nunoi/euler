#!/usr/bin/python
import sys
import random
from math import *
import mutils

number = int(0)
number = sys.argv[1]

def f_function(x, n):
	return ((x**2 + 1) % int(n))

def factor(n):
	x = 2
	y = 2
	d = 1
	while (d == 1):
		x = f_function(x, n)
		y = f_function(f_function(y, n), n)
		d = mutils.gcd(n, fabs(x - y))
#		print "------------------"
#		print "x: " + str(x) + " - y: " + str(y)
#		print "x: " + str(is_prime(x)) + " - y: " + str(is_prime(y))
	if (d == n):
		return -1
	print str(d) + " - " + str(mutils.is_prime(d))


#print is_prime(number)
#res = gcd(int(number2), int(number))
#print res
res = factor(number)


