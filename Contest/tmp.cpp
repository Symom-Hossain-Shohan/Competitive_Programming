#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long

using namespace std;

void solve() {	
	int n;
	cin >> n;
	
	vector<vector<int>> g(n + 1, vector<int>());
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> d(n + 1), f(n + 1);
	int s, t, mx = 0;
	auto dfs = [&](auto self, int u, int fa) -> void {
		d[u] = d[fa] + 1;
		f[u] = fa;
		for (auto v : g[u]) {
			if (v == fa) continue;
			self(self, v, u);
		}
		if (d[u] > mx) {
			mx = d[u];
			t = u; 
		}
	};
	dfs(dfs, 1, 0);
	s = t, mx = 0;
	dfs(dfs, s, 0);
	
	vector<int> a;
	int x = t;
	while (x != s) {
		a.push_back(x);
		x = f[x];
	}
	a.push_back(s);
	
	int len = a.size();
	x = len / 2;
	if (len % 4 == 0) {
		cout << len / 2 << "\n";
		for (int i = 1; i < len / 2; i += 2) {
			cout << a[x] << " " << i << "\n"; 
			cout << a[x - 1] << " " << i << "\n";
		}
	}
	else if (len % 4 == 1) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i <= len / 2; i++) {
			cout << a[x] << " " << i << "\n"; 
		}
	}
	else if (len % 4 == 2) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i < len / 2; i += 2) {
			cout << a[x] << " " << i << "\n"; 
			cout << a[x - 1] << " " << i << "\n";
		}
	}
	else if (len % 4 == 3) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i <= len / 2; i++) {
			cout << a[x] << " " << i << "\n"; 
		}
	}
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	int T = 1;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}



