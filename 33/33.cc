#include <vector>
#include <iostream>

using namespace std;

vector<int> vi;
vector<int> ints;

bool num_contains_n(int num, int n)
{
  return ((num % 10 == n) || (num / 10 == n));
}

void print_ints()
{
  cout << "[";
  for (vector<int>::iterator vi_it = ints.begin(); vi_it != ints.end(); vi_it++) {
    cout << *vi_it << ", ";
  }
  cout << "]" << endl;
}

int factor_out(int num, int n)
{
  if (num % 10 == n)
    return num / 10;
  if (num / 10 == n)
    return num % 10;
}

int main(int argc, char *argv[])
{
  for (int i = 11; i <= 99; i++) {
    vi.push_back(i);
  }

  for (int i = 1; i <= 9; i++) {
    ints.clear();
    for (vector<int>::iterator vi_it = vi.begin(); vi_it != vi.end(); vi_it++) {
      if (num_contains_n(*vi_it, i))
        ints.push_back(*vi_it);
    }
    //print_ints();
    for (vector<int>::iterator vi_it = ints.begin(); vi_it != ints.end(); vi_it++) {
      for (vector<int>::iterator vi_it2 = ints.begin(); vi_it2 != ints.end(); vi_it2++) {
        if (*vi_it == *vi_it2)
	  continue;
	double factored_out = static_cast<double>(factor_out(*vi_it, i)) / factor_out(*vi_it2, i);
        if (factored_out < 1 && static_cast<double>(*vi_it) / *vi_it2 == factored_out) {
	  cout << *vi_it << " " << *vi_it2 << endl;
	}
      }
    }
  }
}

