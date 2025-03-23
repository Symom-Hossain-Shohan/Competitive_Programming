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
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    ll fst = 0, lst = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (v[i] == 0)
            fst++;
    }
    for (int i = n / 2 + 1; i <= n; i++)
    {
        if (v[i] == 0)
            lst++;
    }
    // cout << fst << " " << lst << "\n";
    if (fst + lst == 0)
    {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
    }
    else
    {
        if (fst > 0 and lst > 0)
        {
            if (n % 2 == 0)
            {
                cout << 3 << "\n";
                cout << 1 << " " << n / 2 << "\n";
                cout << 2 << " " << n / 2 + 1 << "\n";
                cout << 1 << " " << 2 << "\n";
            }
            else
            {
                cout << 3 << "\n";
                cout << 1 << " " << n / 2 << "\n";
                cout << 2 << " " << n / 2 + 2 << "\n";
                cout << 1 << " " << 2 << "\n";
            }
        }
        else if (fst)
        {
            if (n % 2 == 0)
            {
                cout << 2 << "\n";
                cout << 1 << " " << n / 2 << "\n";
                cout << 1 << " " << n / 2 + 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
                cout << 1 << " " << n / 2 << "\n";
                cout << 1 << " " << n / 2 + 2 << "\n";
            }
        }
        else if (lst)
        {
            if (n % 2 == 0)
            {
                cout << 2 << "\n";
                cout << n / 2 + 1 << " " << n << "\n";
                cout << 1 << " " << n / 2 + 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
                cout << n / 2 + 1 << " " << n << "\n";
                cout << 1 << " " << n / 2 + 1 << "\n";
            }
        }
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