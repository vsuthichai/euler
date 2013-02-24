#!/usr/bin/env python

def factorial(n):
  num = 1
  for i in xrange(2, n + 1):
    num = num * i
  return num

def main(argv=None):
  f = factorial(100)
  count = 0
  for i in str(f):
    count = count + int(i)
  print count

if __name__ == '__main__'
    main()
