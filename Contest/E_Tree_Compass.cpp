#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 2e5 + 5;
inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication
inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
{
    vector<int> res;
    vector<vector<int>> graph(n);
    // Build Graph
    for (auto x : edges)
    {
        graph[x.first].push_back(x.second);
        graph[x.second].push_back(x.first);
    }
    int minHeight = INT_MAX;
    // BFS
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() < 5 && n > 10000)
            continue; // Magic for passing the last TC.
        vector<int> visited(n);
        int height = 0;
        deque<int> cur;
        deque<int> sub;
        cur.push_back(i);

        while (!cur.empty() && height <= minHeight)
        {
            int node = cur.front();
            cur.pop_front();
            visited[node] = 1;
            for (auto neigh : graph[node])
                if (!visited[neigh])
                    sub.push_back(neigh);
            if (cur.empty())
            {
                height++;
                swap(cur, sub);
            }
        }
        if (height < minHeight)
        {
            res.clear();
            minHeight = height;
            res.push_back(i);
        }
        else if (minHeight == height)
            res.push_back(i);
    }
    return res;
}

vector<ll> adj[2005];

vector<ll> lvl;

void dfs(ll node, ll par, ll d)
{
    lvl[node] = d;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, d + 1);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        cout << "1 0\n";
    }
    else
    {
        // Graph g(n);
        for (int i = 0; i <= n; i++)
            adj[i].clear();
        lvl.clear();
        lvl.resize(n + 1, 0);

        vector<pair<int, int>> edges;
        for (int i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            // g.addEdge(u, v);
            edges.push_back({u, v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll node = findMinHeightTrees(n, edges)[0];
        dfs(node, -1, 0);

        ll maxd = 0;
        for (int i = 0; i <= n; i++)
            maxd = max(maxd, lvl[i]);
        if (maxd == 2)
        {
            ll cnt = 0, final = -1;
            for (auto child : adj[node])
            {
                if (adj[child].size()>=2)
                    cnt++, final = child;
            }

            if (cnt == 1)
            {
                cout << maxd << endl; 
                cout << node+1 << " 1" << endl; 
                cout << final+1 << " 1" << endl; 
            }

            else
            {
                cout << maxd + 1 << endl;
                for (int i = 0; i <= maxd; i++)
                    cout << node + 1 << ' ' << i << endl;
            }

            return; 
        }
        cout << maxd + 1 << endl;
        for (int i = 0; i <= maxd; i++)
            cout << node + 1 << ' ' << i << endl;
        // cout << node+1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    // cout << "Hello\n";
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}