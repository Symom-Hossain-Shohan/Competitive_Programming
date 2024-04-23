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
    int n, x;
    cin >> n >> x;
    unordered_set<int> st;
    int a = n - x;
    int b = n + x - 2;
    int c = 2 * (x - 1);
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if (i % 2 == 0 && i >= c)
                st.insert(i);
            int div = a / i;
            if (div % 2 == 0 && div != i && div >= c)
                st.insert(div);
        }
    }

    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            if (i % 2 == 0 && i >= c)
                st.insert(i);
            int div = b / i;
            if (div % 2 == 0 && div != i && div >= c)
                st.insert(div);
        }
    }

    cout << st.size() << endl;
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