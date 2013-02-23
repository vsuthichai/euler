#!/usr/bin/env python

from math import sqrt

def main(argv=None):
  arr = range(1, 1000)
  for i, a in enumerate(arr):
    for j, b in enumerate(arr[i + 1:]):
      c = sqrt(a * a + b * b)
      if a + b + c == 1000:
        print "%d %d %d" % (a, b, c)

if __name__ == '__main__':
  main()
