#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n;

struct Graph {
    int par[N];
    vector <int> adj[N];
} graph;

int calc_opt(vector <int> lens, int q) {
    int match[lens.size()];
    for (int i = 1; i < lens.size(); ++i) {
        match[i] = lens.size() - i;

        if (lens[i] + lens[match[i]] < q) {
            return -1;
        }
    }
    for (int i = 1; i < lens.size(); ++i) {
        match[match[i]] = i - 1;
        match[i - 1] = match[i];

        if (lens[i - 1] + lens[match[i - 1]] < q) {
            return lens[i - 1];
        }
    }
    return lens.back();
}

int dfs(int u, int q, bool root = true) {
    vector <int> lens;
    for (int v: graph.adj[u]) {
        if (graph.par[u] == v) {
            continue;
        }
        graph.par[v] = u;
        int len = dfs(v, q, false) + 1;
        if (!len) {
            return -1;
        }
        lens.push_back(len);
    }
    sort(lens.begin(), lens.end());
    if (lens.size() % 2 == 0) {
        if (!root && !lens.empty() && lens.back() >= q) {
            int opt = calc_opt(vector <int> (lens.begin(), lens.end() - 1), q);
            if (opt != -1) {
                return opt;
            }
        }
        for (int i = 0; i < lens.size(); ++i) {
            if (lens[i] + lens[lens.size() - i - 1] < q) {
                return -1;
            }
        }
        return 0;
    }
    return calc_opt(lens, q);
}

bool check(int q) {
    int rem = dfs(1, q);
    return rem == 0 || rem >= q;
}

int binary_search(int l, int r) {
    if (l == r) {
        return l;
    }
    int q = l + r + 1 >> 1;
    if (check(q)) {
        return binary_search(q, r);
    } else {
        return binary_search(l, q - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph.adj[u].push_back(v);
        graph.adj[v].push_back(u);
    }
    cout << binary_search(1, N) << "\n";
}