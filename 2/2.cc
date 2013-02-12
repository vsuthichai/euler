#include <stdio.h>

int fibs[2000000];

int fibonacci()
{
  int total = 2;
  for (int i = 2; ; i++) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
    if (fibs[i] > 4000000)
      return total;
    if (fibs[i] % 2 == 0)
      total += fibs[i];
  }
}

int main(int argc, char *argv[])
{
  fibs[0] = 1;
  fibs[1] = 2; 
  printf("%d\n", fibonacci());
  
}
