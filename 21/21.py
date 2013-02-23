#!/usr/bin/env python

def divisors(n):
  if n == 1:
    return []

  f = [1]
  if n == 2:
    return f

  i = 2
  while 1:
    if n % i == 0:
      i_i = n / i
      if i_i < i:
        break
      f.append(i)
      if i_i != i:
        f.append(i_i)
    i = i + 1

  return f

def factors(n):
  f = [1]
  if n == 1:
    return f

  i = 1
  i_i = n
  f = []

  while 1:
    if n % i == 0:
      i_i = n / i
      if i >= i_i:
        break
      f.append(i)
      if i_i != i:
        f.append(i_i)
    i = i + 1

  return f

amicable = {}

def main(argv=None):
  s = set()
  for i in xrange(2, 10001):
    sum_i = sum(divisors(i))
    if sum(divisors(sum_i)) == i:
      if i == sum_i:
        continue
      s.add(sum_i)
      s.add(i)
  print s
  print sum(list(s))

if __name__ == '__main__':
  main()

