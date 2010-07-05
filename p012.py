#!/usr/bin/python

import operator

# A slightly efficient superset of primes.
def PrimesPlus():
  yield 2
  yield 3
  i = 5
  while True:
    yield i
    if i % 6 == 1:
      i += 2
    i += 2
# Returns a dict d with n = product p ^ d[p]
def GetPrimeDecomp(n):
  d = {}
  primes = PrimesPlus()
  for p in primes:
    while n % p == 0:
      n /= p
      d[p] = d.setdefault(p, 0) + 1
    if n == 1:
      return d
def NumberOfDivisors(n):
  d = GetPrimeDecomp(n)
  powers_plus = map(lambda x: x+1, d.values())
  return reduce(operator.mul, powers_plus, 1)


def triangle():
    i = 0
    res = 0
    while True:
        i = i + 1
        res = res + i
        yield res


# fast prime number list generator using a sieve algorithm
def primes(n):
    """ returns a list of prime numbers from 2 to < n """
    if n < 2:  return []
    if n == 2: return [2]
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


t = triangle()
#for k in range(1,10):
#    print t.next()
n = 0
while n < 500:
    a = t.next()
    n = NumberOfDivisors(a)
    if n > 250:
        print n
print a

