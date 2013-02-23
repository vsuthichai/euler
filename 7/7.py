#!/usr/bin/env python

primes = [2, 3, 4, 7, 11]

def isprime(x):
  i = 2
  while x % i != 0:
    i = i + 1
  if x == i:
    return True
  return False


for i in xrange(5, 10001):
  prev = primes[i - 1]
  while 1:
    prev = prev + 1
    if isprime(prev):
      primes.append(prev)
      #print prev
      break

print primes
