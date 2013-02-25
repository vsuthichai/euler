#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
int current_prime;

void init_prime_iterator()
{
  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(5);
  primes.push_back(7);
  current_prime = 7;
}

int next_prime()
{
  bool goodPrime = false;
  while (!goodPrime) {
    current_prime += 2;
    goodPrime = true;
    for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++) {
      if (current_prime % (*it) == 0) {
        goodPrime = false;
        break;
      }
    }
    if (goodPrime) {
      primes.push_back(current_prime);
    }
  }
  return current_prime;
}

bool is_prime(int n)
{
  for (vector<int>::iterator it = primes.begin(); it != primes.end() && *it <= n; it++) {
    if (n == (*it))
      return true;
    else if (n % *it == 0)
      break;
  }
  return false;
}

bool truncatable(int n)
{
  int num = n;
  int digits = 0;

  // truncatable rtl
  while (num > 0) {
    digits += 1;
    if (!is_prime(num))
      return false;
    num = num / 10;
  }

  // truncatable ltr
  int pow = 1;
  for (int i = 1; i < digits; i++)
    pow *= 10;

  num = n;
  for (int i = 0; i < digits; i++, pow /= 10) {
    if (!is_prime(num))
      return false;
    num = num % pow;
  }
  return true;
}


int main(int argc, char *argv[])
{
  int i = 0;
  int prime;
  int sum = 0;
  init_prime_iterator();
  while (i < 11) {
    prime = next_prime();
    if (truncatable(prime)) {
      i++;
      sum += prime;
      //cout << prime << " is truncatable " << endl;
    }
  }
  cout << sum << endl;
}

