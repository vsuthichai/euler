#!/usr/bin/env python

F = []
F.append(1)
F.append(1)
i = 1
while len(str(F[i])) < 1000:
  i = i + 1
  F.append(F[i - 1] + F[i - 2])

print i + 1
print len(str(F[i]))
