#!/usr/bin/python

import sys
from math import sqrt

for c in range(3,500):
	for b in range(2, c):
		for a in range(1, b):
			if a**2 + b**2 == c ** 2:
				print "a: " + str(a) + " - b: " + str(b) +\
				      " - c: " + str(c)
				if a + b + c == 1000:
					print "a+b+c = 1000; with a*b*c =" +\
					      str(a*b*c)
					sys.exit(0)

# without programming
#
# a= 2mn; b= m^2 -n^2; c= m^2 + n^2;
# a + b + c = 1000;
# 
# 2mn + (m^2 -n^2) + (m^2 + n^2) = 1000;
# 2mn + 2m^2 = 1000;
# 2m(m+n) = 1000;
# m(m+n) = 500;
# 
# m>n;
# 
# m= 20; n= 5;
# 
# a= 200; b= 375; c= 425;

