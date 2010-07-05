#!/usr/bin/python

# Brute force method implemented
# To optimize you could use this:
# Sum of first n numbers = n(n+1)/2
# Sum of squares of first n numbers = n(n+1)(2n+1)/6 

import sys

sum_squares = 0
square_sum = 0
for i in range(1,101):
	sum_squares = sum_squares + i**2
	square_sum = square_sum + i
square_sum = square_sum**2
print "Sum of squares = " + str(sum_squares)
print "Square of sum = " + str(square_sum)
print "Difference = " + str(square_sum - sum_squares)
