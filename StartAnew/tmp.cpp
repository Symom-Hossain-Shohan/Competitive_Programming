#include <bits/stdc++.h>
using namespace std;

int n, m, num[200006], low[200006], cnt, cc;

vector<int> dsk[200005];
vector<pair<int, int>> v;
map<pair<int, int>, int> ma;
void dfs(int u, int p)
{
    if (cc)
        return;
    num[u] = low[u] = ++cnt;
    for (auto x : dsk[u])
    {
        if (ma.count({u, x}) == 0 && ma.count({x, u}) == 0)
        {
            ma[{x, u}] = ma[{u, x}] = 1;
            v.push_back({u, x});
        }
        if (x == p)
            continue;
        if (!num[x])
        {
            dfs(x, u);
            low[u] = min(low[u], low[x]);
        }
        else
            low[u] = min(low[u], num[x]);
    }
    if (low[u] == num[u] && u != 1)
    {
        cc++;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int i, j;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }
    dfs(1, 0);
    if (cc)
        cout << 0;
    else
    {
        for (auto x : v)
            cout << x.first << " " << x.second << '\n';
    }
}
