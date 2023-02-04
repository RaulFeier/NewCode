#include <bits/stdc++.h>

using namespace std;

struct nod {
  int inf;
  nod *urm;
} * prim;

void afisare(nod *&prim) {
  while (prim != NULL) {
    cout << prim->inf << " ";
    prim = prim->urm;
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
  int x;

  for (int i = 0; i < n; i++) {
    cin >> x;
    inserare(x, prim);
  }
  afisare(prim);

  return 0;
}