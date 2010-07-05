#!/usr/bin/python

import sys

a = 999
b = 999


def palindrome(n):
	s = str(n)
	s = s[::-1]
	if s == str(n):
		return True
	return False


res = False
for i in range(a, 1, -1):
	print "ciclo " + str(i)
	for k in range(b, 1, -1):
		res = palindrome(i*k)
		if res == True and i*k > 900000:
			print "palindrome: " + str(i*k)
			sys.exit(0)
