#include <bits/stdc++.h>

using namespace std;

int pow_2(int n) {
  int nn = 1;

  while (nn < n) {
    nn *= 2;
  }

  return nn * 2;
}

void build(vector<int> &tree, int len) {
  int nn = len / 2;
  int start = nn / 2;
  int end = nn;

  while (start != 0) {
    for (int i = start; i < end; i++) {
      tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }

    start /= 2;
    end /= 2;
  }
}

void update(int pos, int val, vector<int> &tree) {
  int len = tree.size() / 2;
  pos = pos + len;

  tree[pos] = val;
  while (pos != 0) {
    pos /= 2;
    tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
  }
}

int query(int l, int r, vector<int> &tree) {
  int len = tree.size() / 2;
  int res = -1;

  l += len;
  r += len;

  while (l <= r) {
    if (l % 2 == 1) {
      res = max(res, tree[l]);
      l++;
    }
    if (r % 2 == 0) {
      res = max(res, tree[r]);
      r--;
    }

    l /= 2;
    r /= 2;
  }

  return res;
}

int main() {

  ifstream cin("arbint.in");
  ofstream cout("arbint.out");

  int n, q;
  cin >> n >> q;

  int len = pow_2(n);

  vector<int> tree(len, 0);
  for (int i = 0; i < n; i++) {
    cin >> tree[i + len / 2];
  }

  build(tree, len);

  for (int i = 0; i < q; i++) {
    int cc, a, b;
    cin >> cc >> a >> b;

    a--;

    if (cc == 0) {
      b--;
      cout << query(a, b, tree) << endl;
    } else {
      update(a, b, tree);
    }
  }

  return 0;
}