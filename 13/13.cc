#include <iostream>
#include <string>
#include <stack>
#include <ostream>

#include <stdlib.h>

using namespace std;

const int numString = 100;
const int numDigits = 50;

int main(int argc, char *argv[])
{
  string str[numString];
  for (int i = 0; i < numString; i++) {
    cin >> str[i];
  }

  int carry = 0;
  int col = 0;
  char digit, c[2];
  stack<int> si;
  for (int i = 0; i < numDigits; i++) {
    col = carry;
    for (int j = 0; j < numString; j++) {
      c[0] = str[j][numDigits - i - 1];
      c[1] = '\0';
      col += atoi(c);
    }
    carry = col / 10;
    si.push(col % 10);
  }
  si.push(carry);

  while (!si.empty()) {
    cout << si.top();
    si.pop();
  }
  cout << endl;
  return 0;
}
