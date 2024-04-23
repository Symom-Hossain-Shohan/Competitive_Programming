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
    string s;
    cin >> s;

    int n = s.size();
    int f = 1;

    vector<int> v;

    for (auto e : s)
    {
        if (e == '+')
        {
            if (v.size() && v.back() == -1)
                v.push_back(-1);
            else
                v.push_back(0);
        }
        else if (e == '-')
        {
            int tmp = v.back();
            v.pop_back();

            if (tmp == 1 && v.size())
                v.back() = 1;
        }
        else
        {

            if (e == '1')
            {
                if (v.size() < 2)
                    continue;
                if (v.back() == -1)
                    f = 0;
                else
                    v.back() = 1;
            }
            else
            {
                if (v.size() < 2)
                {
                    f = 0;
                    continue;
                }
                if (v.back() == 1)
                    f = 0;
                else
                    v.back() = -1;
            }
        }
    }

    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
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