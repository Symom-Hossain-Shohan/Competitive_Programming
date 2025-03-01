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

bool isBad(ll x)
{
    ll y = sqrt(x);
    return y * y == x;
}

void solve()
{
    ll n;
    cin >> n;
    if (isBad(n*(n+1)/2))
    {
        cout << -1 << "\n";
    }
    else
    {
        vector<ll> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(i);
        ll sum = 0;
        for (int i = 0; i < n-1; i++)
        {
            sum += ans[i];
            if (isBad(sum))
            {
                sum -= ans[i];
                sum += ans[i + 1];
                swap(ans[i], ans[i + 1]);
            }
        }

        for(auto i: ans)
            cout << i << " ";
        cout << "\n";
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