#include <iostream>

using namespace std;

int sq_of_digits(int n)
{
  int sq = 0;
  int digit;
  while (n > 0) {
    digit = n % 10;
    sq += digit * digit;
    n /= 10;
  }
  return sq;
}

int chain(int n)
{
  int last = n;
  while ((last = sq_of_digits(last)) != 1 && last != 89)
    ;
  return last;
}

int main(int argc, char *argv[])
{
  int count = 0;
  for (int i = 1; i < 10000000; i++) {
    if (chain(i) == 89)
      count++;
  }
  cout << count << endl;
  return 0;
}
