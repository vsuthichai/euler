
a = 2
for i in xrange(0, 999):
  a = a * 2

print sum([int(i) for i in str(a)])
