
def factors(num):
  if num == 1:
    return [0]
  if num == 2:
    return [1]

  f = []
  i = 1
  i_i = num

  while 1:
    if num % i == 0:
      i_i = num / i
      if i > i_i:
        break
      f.append(i)
      if i != i_i:
        f.append(i_i)
    i = i + 1

  return f

def triangle_num(num):
  return sum([i for i in xrange(1, num)])

def main(argv=None):
  i = 2
  length = 0
  t_n = 0
  length = 0
  while length <= 500:
    t_n = triangle_num(i)
    #print t_n
    f = factors(t_n)
    #print f
    length = len(f)
    #print length
    i = i + 1

  print t_n
  print f
  print length

if __name__ == '__main__':
  main()
