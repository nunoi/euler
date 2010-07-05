#!/usr/bin/python

import sys
import random
import mutils


def Euclid(a, b):
  while b != 0:
    r = a % b
    a = b
    b = r
  return a

def PollardRho(n):
  i = 1
  x = random.randint(0, n - 1)
  y = x
  k = 2
  tried = set()
  tried.add(x)
  while True:
    i = i + 1
    x = (x ** 2 - 1) % n
    if x in tried:
      return
    tried.add(x)
    d = Euclid(y - x, n)
    if d != 1 and d != n:
      if mutils.is_prime(d):
        print d
#      print str(d) + " - " + str(is_prime(int(d))) # d is a factor. Print it.
    if i == k:
      y = x
      k = 2 * k

def main(argv):
  PollardRho(int(argv[0]))

if __name__ == "__main__":
    main(sys.argv[1:])

