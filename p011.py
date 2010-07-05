#!/usr/bin/python

import sys
import mutils

f = open("p011_grid.txt","r")

l = []
try:
	for line in f:
		tmp = line
		tmp = tmp[:-1].split() # remove '\n' and split numbers
		l.append(tmp)
finally:
	f.close()

#print l

max = 0
for i in range(1,17):
	print i
	for k in range(1,17):
		h = 1
		v = 1
		dr = 1
		dl = 1
		for n in range(0,4):
			h = h * int(l[i][k + n])
			v = v * int(l[i + n][k])
			dr = dr * int(l[i + n][k + n])
			if i > 3:
				dl = dl * int(l[i - n][k + n])
		if max < h:
			max = h
		if max < v:
			max = v
		if max < dl:
			max = dl
		if max < dr:
			max = dr
print max

