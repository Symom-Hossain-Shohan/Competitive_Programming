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

void merge(vector<ll> &v, ll start, ll mid, ll end)
{
    vector<ll> temp;

    ll i = start, j = mid + 1;
    while (i <= mid and j <= end)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(v[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        v[idx + start] = temp[idx];
    }
}

void mergeSort(vector<ll> &v, ll start, ll end)
{
    if (start < end)
    {
        ll mid = (start + end) / 2;
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end);
        merge(v, start, mid, end); 
    }
}

void solve()
{
    vector<ll> v = {6, 4, 5, 1, 2}; 
    mergeSort(v, 0, v.size()-1); 
    for(auto i: v) cout << i << endl; 
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