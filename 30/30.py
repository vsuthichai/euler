#!/usr/bin/env python

# 9^5 * 6 = 354294
def main(argv=None):
  numbers = []
  for a in xrange(0, 10):
    for b in xrange(0, 10):
      for c in xrange(0, 10):
        for d in xrange(0, 10):
          for e in xrange(0, 10):
            for f in xrange(0, 10):
              num = int(str(a) + str(b) + str(c) + str(d) + str(e) + str(f))
              if (a ** 5) + (b ** 5) + (c ** 5) + (d ** 5) + (e ** 5) + (f ** 5) == int(num):
                #print [a, b, c, d, e, f]
                #print num
                numbers.append(num)
  
  print sum(numbers) - 1

if __name__ == '__main__':
  main()
