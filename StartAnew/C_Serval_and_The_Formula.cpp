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
    ll x, y;
    cin >> x >> y;

    ll memo[62][2][2];
    memset(memo, -1, sizeof(memo));

    auto dp = [&](auto &&self, int bit, int c1, int c2) -> ll
    {
        if (bit == 61)
        {
            if ((!c1) && (!c2))
            {
                return 0;
            }
            else
            {
                return 2e18;
            }
        }

        if (memo[bit][c1][c2] != -1)
            return memo[bit][c1][c2];

        int b1 = ((x & (1LL << bit)) ? 1 : 0);
        int b2 = ((y & (1LL << bit)) ? 1 : 0);

        for (int i = 0; i <= 1; i++)
        {
            ll d1 = b1 + c1 + i;
            ll d2 = b2 + c2 + i;

            if ((d1 & 1) && (d2 & 1))
            {
                continue;
            }

            ll ans = self(self, bit + 1, d1 / 2, d2 / 2);
            if (ans > 1e18)
                continue;
            return memo[bit][c1][c2] = ans + (1LL << bit) * i;
        }

        return memo[bit][c1][c2] = 2e18;
    };

    ll ans = dp(dp, 0, 0, 0);

    if (ans > 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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