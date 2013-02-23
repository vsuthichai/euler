#!/usr/bin/env python

def main(argv=None):
	a = 2
	for i in xrange(0, 999):
  		a = a * 2

	print sum([int(i) for i in str(a)])

if __name__ == '__main__'
	main()
