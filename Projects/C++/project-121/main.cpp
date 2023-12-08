#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<string, int> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s; // aici citim n orase
    m[s]++;   // la fiecare oras s adaugam 1
  }

  // printam map care se face unpica mai ciudat pt tn

  for (auto &c : m) {
    cout << c.first << " " << c.second
         << endl; // orasu e primu si nr de apariti al doilea se si vede dupa
                  // map<string, int>
  }

  return 0;
}