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
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, s;
    cin >> x >> s;
    vector<ll> a(m), b(m), c(k), d(k);
    for (ll i = 0; i < m; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    for (ll i = 0; i < k; i++)
        cin >> c[i];
    for (ll i = 0; i < k; i++)
        cin >> d[i];

    ll ans = x * n;
    a.push_back(x);
    b.push_back(0);
    // cout << ans << endl;
    for (ll i = 0; i <= m; i++)
    {
        ll rem = s - b[i];
        if (rem < 0)
            continue;
        ll l = 0, r = k - 1, idx = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (d[mid] <= rem)
            {
                idx = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (idx != -1)
        {
            ll t = n - c[idx];
            ans = min(ans, t * a[i]);
        }
        else 
        {
            ans = min(ans, n*a[i]);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}