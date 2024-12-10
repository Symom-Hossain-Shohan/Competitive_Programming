#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const ll MX = 3e5 + 5;
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


ll fact[MX] = {0}; 
void solve()
{
    ll n;
    cin >> n;
    vector<ll> red(n), green(n);
    for(auto &i: red) cin >> i; 
    for(auto &i: green) cin >> i; 

    ll sum_wt= 0;
    for (int i = 0; i < n; ++i)
    {
        sum_wt = (sum_wt + red[i] + green[i]) % mod;
    }

    ll s = (sum_wt*modInverse(2)) %mod; 
    // ll n_inv = modInverse(n); 

    for (int k = 1; k <= n; ++k)
    {
        ll x = modDiv(fact[n-k], fact[n]); 

        ll ans = modMul(s, x); 
        cout << ans << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    fact[0] = 1; 
    for(int i=1;i<MX; i++) 
    {
        fact[i] = modMul(i, fact[i-1]); 
    }
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}