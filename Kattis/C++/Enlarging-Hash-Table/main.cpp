#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<i64> p;
bitset<10000010> bs;
i64 _size;

void sieve(i64 n) {
  _size = n + 1;
  bs.set();

  bs[0] = bs[1] = 0;

  for (i64 i = 2; i < _size; i++) {
    if (bs[i]) {
      for (i64 j = i * i; j < _size; j += i) {
        bs[j] = 0;
      }
      p.push_back(i);
    }
  }
}

bool isPrime(i64 n) {
  if (n < _size) {
    return bs[n];
  }

  for (i64 i = 0; i < p.size() and p[i] * p[i] <= n; i++) {
    if (n % p[i] == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n;
  sieve(1e7);

  while (true) {
    scanf("%lld", &n);
    if (n == 0)
      break;

    bool is_prime = true;
    if (!isPrime(n)) {
      is_prime = false;
    }

    i64 i = (2 * n) + 1;
    if (i < _size) {
      while (!bs[i]) {
        i++;
      }
    } else {
      while (!isPrime(i)) {
        i++;
      }
    }

    if (is_prime) {
      cout << i << "\n";
    } else {
      cout << i << " (" << n << " is not prime)"
           << "\n";
    }
  }

  return 0;
}