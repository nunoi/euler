# Useful math functions module
# for use with Project Euler's problems

from math import sqrt

# Brute force prime check
# 1 is not considered prime; see
# http://www.research.att.com/~njas/sequences/A000040
def is_prime(n):
        """Check if the number is prime"""
        if (n <= 1):
                return False
	if (n == 2):
                return True
        i = int(2)
        while (i <= sqrt(float(n))):
                if (int(n) % i == 0):
                        return False
                i = i + 1
        return True


# fast prime number list generator using a sieve algorithm
def prime_sieve(n):
	""" returns a list of prime numbers from 2 to < n """
	if n < 2: 
		return []
	if n == 2: 
		return [2]
	# do only odd numbers starting at 3
	s = range(3, n, 2)
	# n**0.5 may be slightly faster than math.sqrt(n)
	mroot = n ** 0.5
	half = len(s)
	i = 0
	m = 3
	while m <= mroot:
		if s[i]:
			j = (m * m - 3)//2
			s[j] = 0
			while j < half:
				s[j] = 0
				j += m
		i = i + 1
		m = 2 * i + 3
	# make exception for 2
	return [2]+[x for x in s if x]




def gcd(a,b):
    assert a >= b     # a must be the larger number
    while (b != 0):
        remainder = int(a) % int(b)
        a, b  = b, remainder
    return int(a)

