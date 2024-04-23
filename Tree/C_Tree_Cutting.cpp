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

void solve()
{
    ll n, k;

    cin >> n >> k;
    vector<vector<ll>> adj(n + 1);

    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<pair<int, int>(int, int, int)> dfs = [&](int node, int fa, int s) {

        int sz = 1, cnt = 0; 
        for(auto child: adj[node])
        {
            if(child!=fa)
            {
                auto tmp = dfs(child, node, s); 
                sz += tmp.first, cnt += tmp.second; 
            }
        }

        if(sz>=s)
        {
            sz = 0; 
            cnt++; 
        }
        return make_pair(sz, cnt); 
    };

    ll ans = -1; 
    ll l = 1, r = n; 
    while(l<=r)
    {
        ll mid = (l+r)/2;
        if(dfs(1, 0, mid).second>k)
        {
            ans = mid; 
            l = mid + 1; 
        } 
        else r = mid - 1; 
    }

    cout << ans << endl; 
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