#!/usr/bin/env python

number = 600851475143

x = 2
primes = []

while x != number:
  if number % x == 0:
    primes.append(x)
    number = number / x
  else:
    x = x + 1

primes.append(x)

print primes
