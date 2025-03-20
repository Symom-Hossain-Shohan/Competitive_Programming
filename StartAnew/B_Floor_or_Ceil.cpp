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
    ll x, n, m;
    cin >> x >> n >> m;

    ll y = x;
    for (int i = 0; i < min(n, (ll)60); i++)
    {
        y /= 2;
    }
    for (int i = 0; i < min(m, (ll)60); i++)
    {
        y = (y + 1) / 2;
    }
    ll max_val = y;

    ll z = x;
    for (int i = 0; i < min(m, (ll)60); i++)
    {
        z = (z + 1) / 2;
    }
    for (int i = 0; i < min(n, (ll)60); i++)
    {
        z /= 2;
    }
    ll min_val = z;

    cout << min_val << " " << max_val << endl;
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