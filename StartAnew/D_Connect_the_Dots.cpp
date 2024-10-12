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

class UnionFind
{
private:
    vector<int> p, rank;

public:
    UnionFind(int n)
    {
        rank.assign(n, 0);
        p.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
                p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(11, 0));

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = max(arr[a][b], c);
    }

    UnionFind DSU(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int iterations = arr[i][j], position = i;

            while (iterations > 0 and position + j <= n)
            {
                iterations--;
                DSU.unionSet(position, position + j);
                arr[position][j] = 0;
                position += j;
                iterations = max(arr[position][j], iterations);
            }
        }
    }

    int components = 0;

    for (int i = 1; i <= n; i++)
        components += (DSU.findSet(i) == i);
    cout << components << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}