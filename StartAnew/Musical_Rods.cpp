#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool Compare(pair<ll, ll> A, pair<ll, ll> B)
{
    return A.first * B.second > A.second * B.first;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; i++)
        cin >> vp[i].first;
    for (int i = 0; i < n; i++)
        cin >> vp[i].second;

    sort(vp.begin(), vp.end(), Compare);

    ll d = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += d * vp[i].second;
        d += vp[i].first;
    }
    cout << sum << endl;
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