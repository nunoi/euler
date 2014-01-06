#!/usr/bin/python

import sys

def mult(s):
	res = 1
	if s.find('0') >= 0:
		return 0
	for c in s:
		res = res * int(c)
	return res

f = open("p008_number.txt","r")
try:
	str = f.read()
finally:
	f.close()


biggest = 1
# range ends at 996 because we need to have always 5 digits to multiply
for i in range(1,996):
	res = mult(str[i:i+5])
	if res > biggest:
		biggest = res
	i = i + 1
	print biggest

