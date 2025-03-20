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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (k == 1)
    {
        ll ans = a[0] + a[n - 1];
        for (ll i = 1; i < n - 1; i++)
        {
            ans = max(ans, a[i] + max(a[0], a[n - 1]));
        }
        cout << ans << endl;
    }
    else if (k >= n - 1)
    {
        cout << accumulate(a.begin(), a.end(), 0LL) << endl;
    }
    else
    {
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll score = a[i];
            if (i == 0)
            {
                vector<ll> b;
                for (int j = 1; j < n; j++)
                {
                    b.push_back(a[j]);
                }
                sort(b.rbegin(), b.rend());
                for (int j = 0; j < k; j++)
                {
                    score += b[j];
                }
                ans = max(ans, score);
            }
            else if (i == n - 1)
            {
                vector<ll> b;
                for (ll j = 0; j < n - 1; j++)
                    b.push_back(a[j]);
                sort(b.rbegin(), b.rend());
                for (ll j = 0; j < k; j++)
                {
                    score += b[j];
                }
                // cout << score << endl;
                ans = max(ans, score);
            }
            else
            {
                // cout << i << "------- " << endl;
                vector<ll> b, c;
                for (ll j = 0; j < i; j++)
                    b.push_back(a[j]);
                for (ll j = i + 1; j < n; j++)
                    c.push_back(a[j]);
                sort(b.begin(), b.end());
                sort(c.begin(), c.end());
                // for(auto it: b) cout << it << " ";
                // cout << endl;
                // for(auto it: c) cout << it << " ";
                // cout << endl;
                // cout << "-----------\n";
                bool from_b = false, from_c = false;
                for (ll j = 0; j < k - 1; j++)
                {
                    if (!b.empty() and !c.empty())
                    {
                        if (b.back() > c.back())
                        {
                            score += b.back();
                            b.pop_back();
                            from_b = true;
                        }
                        else
                        {
                            score += c.back();
                            c.pop_back();
                            from_c = true;
                        }
                    }
                    else
                    {
                        if (!b.empty())
                        {
                            score += b.back();
                            b.pop_back();
                            from_b = true;
                        }
                        else
                        {
                            score += c.back();
                            c.pop_back();
                            from_c = true;
                        }
                    }
                }
                // cout << score << endl;
                if (from_b == false)
                {
                    score += b.back();
                    // cout << score << endl;
                }
                else if (from_c == false)
                {
                    score += c.back();
                    // cout << score << endl;
                }
                else
                {
                    if (b.size() and c.size())
                    {
                        score += max(b.back(), c.back());
                        // cout << score << endl;
                    }
                    else if (b.size())
                        score += b.back();
                    else
                        score += c.back();
                }

                // cout << score << endl;
                // cout << "---------\n";
                ans = max(ans, score);
            }
        }
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