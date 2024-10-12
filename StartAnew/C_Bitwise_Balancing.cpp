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
    map<tuple<int, int, int>, int> mp;

    mp[{0, 0, 0}] = 0;
    mp[{0, 0, 1}] = 1;
    mp[{0, 1, 0}] = 0;
    mp[{0, 1, 1}] = -1;
    mp[{1, 0, 0}] = -1;
    mp[{1, 0, 1}] = 0;
    mp[{1, 1, 0}] = 1;
    mp[{1, 1, 1}] = 0;

    ll a = 0, b, c, d;
    cin >> b >> c >> d;

    for (int i = 60; i >= 0; i--)
    {
        ll x = (((1ll << i) & b) != 0);

        ll y = (((1ll << i) & c) != 0);

        ll z = (((1ll << i) & d) != 0);

        ll t = mp[{x, y, z}];

        if (t == -1)
        {
            a = -1;
            break;
        }

        a += t * (1ll << i);
    }
    cout << a << endl;
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