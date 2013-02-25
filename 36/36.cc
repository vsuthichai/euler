#include <iostream>

using namespace std;

bool palindrome_10(int n)
{
  int pal = 0;
  int num = n;
  while (num > 0) {
    pal *= 10;
    pal += num % 10;
    num /= 10;
  }
  return n == pal;
}

bool palindrome_2(int n)
{
  int i;
  int sz = sizeof(int) * 8;
  int pal = 0;
  for (i = sz - 1; i >= 0; i--) {
    if ((1 << i) & n)
      break;
  }
  for (int j = 0; j <= i; j++) {
    pal <<= 1;
    if ((1 << j) & n) {
      pal += 1;
    }
  }
  return pal == n;
}

int main(int argc, char *argv[])
{
  int sum = 0;
  for (int i = 0; i < 1000000; i++) {
    if (palindrome_10(i) && palindrome_2(i))
      sum += i;
  }  
  cout << sum << endl;
}
