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

const ll m = 1e9 + 7;
const ll i2 = 5e8 + 4;
const int N = 1e5;
ll dp[N + 1][2];

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][0] = (1 + dp[i - 1][0]) % m;
            dp[i][1] = (1 + (dp[i - 1][0] + dp[i - 1][1]) * i2) % m;
        }
        else
        {
            dp[i][0] = (1 + (dp[i - 1][0] + dp[i - 1][1]) * i2) % m;
            dp[i][1] = (1 + dp[i - 1][1]) % m;
        }
    }
    cout << dp[n - 1][0] << '\n';
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