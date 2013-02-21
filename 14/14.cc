#include <vector>
#include <iostream>

using namespace std;

void print_vi(vector<long>& vi)
{
  cout << "[";
  for (long i = 0; i < vi.size(); i++) {
    cout << vi[i] << ", ";
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[])
{
  vector<long> vi;
  long longest = 0;
  long answer = 0;
  for (long i = 999999; i > 0; i--) {
    long n = i;
    vi.clear();
    vi.push_back(n);
    while (n > 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = 3 * n +1;
      }
      vi.push_back(n);
    }
    if (n < 1) {
      cout << "Problem with " << i << " " << vi.size() << endl;
    }
    if (vi.size() > longest) {
      longest = vi.size();
      answer = i;
    }
    //print_vi(vi);
  }

  cout << answer << " " << longest << endl;
}
