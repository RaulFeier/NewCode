#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
  vector<int> tree;
  int n;

public:
  SegmentTree(vector<int> &tree) {
    n = tree.size();
    this->tree.resize(n * 4);
    build(tree, 1, 0, n - 1);
  }

  void build(vector<int> &tree, int node, int start, int end) {
    if (start == end) {
      this->tree[node] = tree[start];
      return;
    }

    int mid = (start + end) / 2;
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;

    build(tree, leftNode, start, mid);
    build(tree, rightNode, mid + 1, end);

    this->tree[node] = max(this->tree[leftNode], this->tree[rightNode]);
  }

  void update(int index, int value) { updateTree(1, 0, n - 1, index, value); }

  void updateTree(int node, int start, int end, int index, int value) {
    if (start == end) {
      this->tree[node] = value;
      return;
    }

    int mid = (start + end) / 2;
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;

    if (index <= mid) {
      updateTree(leftNode, start, mid, index, value);
    } else {
      updateTree(rightNode, mid + 1, end, index, value);
    }

    this->tree[node] = max(this->tree[leftNode], this->tree[rightNode]);
  }

  int query(int left, int right) { return queryTree(1, 0, n - 1, left, right); }

  int queryTree(int node, int start, int end, int left, int right) {
    if (start > right or end < left) {
      return 0; // impossible
    }

    if (start >= left and end <= right) {
      return this->tree[node];
    }

    int mid = (start + end) / 2;
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;

    int leftValue = queryTree(leftNode, start, mid, left, right);
    int rightValue = queryTree(rightNode, mid + 1, end, left, right);

    return max(leftValue, rightValue);
  }
};

int main() {

  ifstream cin{"arbint.in"};
  ofstream cout{"arbint.out"};

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  SegmentTree tree(a);

  for (int i = 0; i < m; i++) {
    int t, term1, term2;
    cin >> t >> term1 >> term2;

    if (t == 0) {
      term1--;
      term2--;
      cout << tree.query(term1, term2) << '\n';
    } else {
      term1--;
      tree.update(term1, term2);
    }
  }

  return 0;
}