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
    string s;
    cin >> s;
    string rev = s;
    reverse(rev.begin(), rev.end());

    if (s < rev)
    {
        cout << "YES\n";
        return;
    }

    if (k == 0)
    {
        if (s < rev)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    else if (k == 1)
    {
        if(s[0]==s[n-1])
        {
            for(int i=1;i<n-1;i++)
            {
                if(s[i]!=s[0])
                {
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
        }
        else 
        {
            cout << "YES\n";
        }
    }
    else
    {
        sort(s.begin(), s.end());
        if (s[0] == s[n - 1])
        {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
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