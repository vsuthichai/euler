#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  vector<int> vi;
  for (int i = 1; i <= 20; i++) {
    vi.push_back(i);
  }

  bool b = false;
  for (long num = 40; !b; num += 20) {
    b = true;
    for (vector<int>::iterator vi_it = vi.begin(); vi_it != vi.end(); vi_it++) {
      if (num % *vi_it != 0) {
        b = false;
        break;
      }
    }
    if (b)
      cout << num << endl;
  }
}
