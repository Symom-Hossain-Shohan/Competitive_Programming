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
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> ar(n + 1, 0);
    ar[x] = 0, ar[y] = 1;
    ll cnt = 0;
    for (int i = x + 1; i < y; i++, cnt++)
    {
        if (cnt % 2 == 0)
            ar[i] = 1;
        else
            ar[i] = 0;
    }
    if (y == 1)
    {
        if (ar[n] == 1)
            ar[n] = 2;
    }
    else
    {
        if (ar[y - 1] == 1)
            ar[y - 1] = 2;
    }

    cnt = 0;
    for (int i = y + 1; i <= n; i++, cnt++)
    {
        if (cnt % 2 == 0)
        {
            ar[i] = 0;
        }
        else
            ar[i] = 1;
    }

    for (int i = 1; i < x; i++, cnt++)
    {
        if (cnt % 2 == 0)
        {
            ar[i] = 0;
        }
        else
            ar[i] = 1;
    }

    if (x == 1)
    {
        if (ar[n] == 0)
            ar[n] = 2;
    }
    else
    {
        // cout << ar[x-1] << endl; 
        if (ar[x - 1] == 0)
            ar[x - 1] = 2;
    }


    for(int i=1;i<=n; i++) cout << ar[i] <<' '; 
    cout << endl; 
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