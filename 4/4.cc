#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

stringstream ss;
string str;

bool is_palindrome(int x)
{
  int divisor;
  ss.str(string());
  str.clear();
  if (x >= 100000) {
    divisor = x / 100000;
    x -= (divisor * 100000);
    ss << divisor;
    //cout << divisor << endl;
  }

  for (int i = 10000; i > 0; i /= 10) {
    divisor = x / i;
    x -= (divisor * i);
    ss << divisor;
    //cout << divisor << endl;
  }

  str = ss.str();
  //cout << str << endl;

  for (int i = 0; i < str.size() / 2; i++) {
    if (str[i] != str[str.size() - i - 1])
      return false;
  }

  return true;
}

int main(int argc, char *argv[])
{
  vector<int> vi;
  for (int i = 999; i >= 100; i--) {
    for (int j = 999; j >= 100; j--) {
      if (is_palindrome(i * j)) {
        vi.push_back(i * j);
      }
    }
  }

  sort(vi.begin(), vi.end());
  cout << vi[vi.size() - 1] << endl;

  //cout << is_palindrome(11321) << endl;
  return 0;
}
