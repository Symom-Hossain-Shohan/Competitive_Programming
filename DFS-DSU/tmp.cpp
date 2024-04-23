#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> g(n + 1);
    for (int i = 0, u, v; i < n; i += 1) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> dep(n + 1, -1), par(n + 1);
    dep[b] = 0;
    int root = 0;
    function<void(int)> dfs = [&](int u) {
      for (int v : g[u]) {
        if (dep[v] == -1) {
          par[v] = u;
          dep[v] = dep[u] + 1;
          dfs(v);
        } else if (dep[v] < dep[u] and par[u] != v) {
          root = v;
        }
      }
    };
    dfs(b);
    vector<int> d(n + 1, -1);
    d[root] = 0;
    queue<int> q;
    q.push(root);
    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    cout << (d[a] > d[b] ? "YES" : "NO") << "\n";
  }
}