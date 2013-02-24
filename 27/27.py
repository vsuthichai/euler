#!/usr/bin/env python

from math import sqrt

primes = {}
primes_count = {}

def is_prime(k):
  if k <= 1:
    return False

  v = primes.get(k)
  if v != None:
    return v

  if k % 2 == 0:
    primes[k] = False
    return primes[k]

  sqrt_k = sqrt(k)
  i = 3
  primes[k] = True
  while i <= sqrt_k:
    if k % i == 0:
      primes[k] = False
      break
    i = i + 2

  return primes[k]

def main(argv=None):
  solution = 0
  a_b = ()
  max_primes = 0
  for a in xrange(-999, 1000):
    for b in xrange(-999, 1000):
      n = 0
      while is_prime((n * n) + (a * n) + b):
        n = n + 1

      if n >= 1:
        primes_count[(a, b)] = n

      if n > max_primes:
        max_primes = n
        a_b = (a, b)
        solution = a * b

  #print max_primes
  #print a_b
  print solution


if __name__ == '__main__':
  main()
