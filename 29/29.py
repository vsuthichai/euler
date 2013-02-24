#!/usr/bin/env python

def main(argv=None):
  terms = set()
  for a in xrange(2, 101):
    for b in xrange(2, 101):
      terms.add(a ** b)
  print len(terms)

if __name__ == '__main__':
  main()
