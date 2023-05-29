#include <bits/stdc++.h>

using namespace std;

int power_of_two(int n) {
  int crt = 1;
  while (crt < n) {
    crt *= 2;
  }

  return crt * 2;
}

class SegmentTree {
private:
  int n;
  vector<int> tree;
  int len;

  void build(vector<int> &tree) {
    for (int i = 0; i < n; i++) {
      this->tree[i + len] = tree[i];
    }

    int start = len / 2;
    int end = len;
    while (start != 0) {
      for (int index = start - 1; index < len; index++) {
        this->tree[index] =
            max(this->tree[index * 2], this->tree[index * 2 + 1]);
      }
      start /= 2;
      end /= 2;
    }
  }

public:
  SegmentTree(vector<int> &tree) {
    n = tree.size();
    this->tree.resize(power_of_two(tree.size()), 0);
    len = this->tree.size() / 2;
    build(tree);
  }

  void update(int pos, int value) {
    pos = pos + len - 1;
    this->tree[pos] = value;

    pos = pos / 2;
    while (pos > 1) {
      this->tree[pos] = max(this->tree[pos * 2], this->tree[pos * 2 + 1]);
      pos /= 2;
    }
  }

  int query(int l, int r) {
    l = l + len - 1;
    r = r + len - 1;
    int res = -1;

    while (l <= r) {
      if (l % 2 == 1) {
        res = max(res, this->tree[l]);
        l++;
      }
      if (r % 2 == 0) {
        res = max(res, this->tree[r]);
        r--;
      }
      r /= 2;
      l /= 2;
    }

    return res;
  }

  void print_tree() {
    for (int index = 1; index < this->tree.size(); index++) {
      cout << this->tree[index] << " ";
    }
    cout << endl;
  }
};

int main() {
  int n;
  cin >> n;

  vector<int> tree(n);

  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }

  SegmentTree CopilCopac(tree);

  return 0;
}

/*
       10
   10       1
 10   6   1   0
4 10 5 6 1 0 0 0
*/