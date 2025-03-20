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
    vector<ll> a(n + 1), b(n + 1), c(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    for (ll i = 1; i <= n; i++)
        cin >> c[i];

    for (ll i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }

    ll sum = (a.back() + 2) / 3;

    ll la = -1, lb = -1, lc = -1, ra = -1, rb = -1, rc = -1;
    // abc
    la = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] >= sum)
        {
            ra = i;
            ll j = i + 1;
            lb = j;
            for (; j <= n; j++)
            {
                if (b[j] - b[i] >= sum)
                {
                    rb = j;
                    lc = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (c[k] - c[j] >= sum)
                        {
                            rc = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // acb
    la = 1, lb = -1, lc = -1, ra = -1, rb = -1, rc = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] >= sum)
        {
            ra = i;
            lc = i + 1;
            for (ll j = i + 1; j <= n; j++)
            {
                if (c[j] - c[i] >= sum)
                {
                    rc = j;
                    lb = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (b[k] - b[j] >= sum)
                        {
                            rb = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // bac
    la = -1, lb = 1, lc = -1, ra = -1, rb = -1, rc = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (b[i] >= sum)
        {
            rb = i;
            la = i + 1;
            for (ll j = i + 1; j <= n; j++)
            {
                if (a[j] - a[i] >= sum)
                {
                    ra = j;
                    lc = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (c[k] - c[j] >= sum)
                        {
                            rc = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // bca
    la = -1, lb = 1, lc = -1, ra = -1, rb = -1, rc = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (b[i] >= sum)
        {
            rb = i;
            lc = i + 1;
            for (ll j = i + 1; j <= n; j++)
            {
                if (c[j] - c[i] >= sum)
                {
                    rc = j;
                    la = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (a[k] - a[j] >= sum)
                        {
                            ra = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // cab
    la = -1, lb = -1, lc = 1, ra = -1, rb = -1, rc = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (c[i] >= sum)
        {
            rc = i;
            la = i + 1;
            for (ll j = i + 1; j <= n; j++)
            {
                if (a[j] - a[i] >= sum)
                {
                    ra = j;
                    lb = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (b[k] - b[j] >= sum)
                        {
                            rb = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // cba
    la = -1, lb = -1, lc = 1, ra = -1, rb = -1, rc = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (c[i] >= sum)
        {
            rc = i;
            lb = i + 1;
            for (ll j = i + 1; j <= n; j++)
            {
                if (b[j] - b[i] >= sum)
                {
                    rb = j;
                    la = j + 1;
                    for (ll k = j + 1; k <= n; k++)
                    {
                        if (a[k] - a[j] >= sum)
                        {
                            ra = n;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    if (ra != -1 && rb != -1 && rc != -1 && la != -1 && lb != -1 && lc != -1)
    {
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << "\n";
        return;
    }

    // cout << sum << endl; 

    cout << -1 << "\n";
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