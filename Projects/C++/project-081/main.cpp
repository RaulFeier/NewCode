#include <bits/stdc++.h>

using namespace std;

struct nod {
  int inf;
  nod *urm;
} * p, *prim;

int maximul(nod *p) {
  int maxim = 0;
  while (p != NULL) {
    if (maxim < p->inf) {
      maxim = p->inf;
    }
    p = p->urm;
  }

  return maxim;
}

int sum(nod *p) {
  int sum = 0;
  while (p != NULL) {
    sum += p->inf;
    p = p->urm;
  }

  return sum;
}

void afisare(nod *p) {
  while (p != NULL) {
    cout << p->inf << " ";
    p = p->urm;
  }
}

void inserare(int x, nod *&prim) {
  nod *p = new nod;
  p->inf = x;
  p->urm = prim;
  prim = p;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    inserare(x, prim);
  }
  cout << endl;
  cout << "Lista: ";
  afisare(prim);

  cout << endl;
  cout << "Suma: " << sum(prim) << endl;

  cout << "Maximul: " << maximul(prim) << endl;

  return 0;
}