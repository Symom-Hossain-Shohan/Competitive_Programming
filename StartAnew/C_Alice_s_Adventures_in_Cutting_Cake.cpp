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
    ll n, m, vv;
    cin >> n >> m >> vv;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + v[i - 1];

    map<ll, ll> lft, rgt;
    lft[0] = 0, rgt[0] = n;

    ll cum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cum += v[i];
        if (cum >= vv)
        {
            cum = 0, cnt++;
            lft[cnt] = i + 1;
        }
    }

    cum = 0, cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        cum += v[i];
        if (cum >= vv)
        {
            cum = 0, cnt++;
            rgt[cnt] = i + 1;
        }
    }

    ll ans = -1; 

    for(int i=1;i<m ;i++)
    {
        ll l = i, r = m-i; 
        l = lft[l], r = rgt[r]; 
        // if(l==0 or r==0) continue;
        // cout << "OK: " << i << ' ' << sum[r-1]-sum[l] << endl; 
        ans = max(ans, sum[r-1]-sum[l]); 
    }

    // cout << "sum" << ' ' << endl; 
    // for(auto i: sum) cout << i << ' '; 
    // cout << endl; 

    // cout << "lft" << ' ' << endl; 
    // for(auto i: lft) cout << i.second << ' '; 
    // cout << endl;

    // cout << "rgt" << ' ' << endl; 
    // for(auto i: rgt) cout << i.second << ' '; 
    // cout << endl;

    // cout << "ans2 " << ans << endl; 
    if(lft[m]!=0) 
    {
        ll l = lft[m]; 
        ans = max(ans, sum.back()-sum[l]); 
        // cout << "m" << ' ' << sum.back()-sum[l] << endl; 
    }
    if(rgt[m]!=0)
    {
        ll r = rgt[m]; 
        ans = max(ans, sum[r-1]); 
        // cout << "0" << ' ' << sum[r-1] << endl; 
    }

    cum = 0, cnt = 0; 
    for(auto i: v)
    {
        cum += i; 
        if(cum>=vv)
        {
            cum = 0;
            cnt++; 
        }
    }

    if(cum>=0) cnt++; 
    if(cnt<m)
    {
        cout << -1 << endl; 
        return; 
    }

    cout << ans << endl; 
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