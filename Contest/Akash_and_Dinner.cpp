#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (mp.find(a[i]) != mp.end())
        {
            mp[a[i]] = min(mp[a[i]], x);
        }
        else
            mp[a[i]] = x;
    }
    vector<ll> tmp;
    for (auto i : mp)
        tmp.push_back(i.second);
    if (tmp.size() < k)
        cout << -1 << endl;
    else
    {
        ll ans = 0;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < k; i++)
            ans += tmp[i];
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