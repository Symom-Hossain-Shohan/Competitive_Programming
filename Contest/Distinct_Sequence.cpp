#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    n *= 2;
    if (count(s.begin(), s.end(), '1') == n or count(s.begin(), s.end(), '0') == n)
        cout << -1 << endl;
    else
    {
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
            v.push_back({s[i] - '0', i});
        sort(v.begin(), v.end());
        for (int i = 0; i < n / 2; i++)
            cout << v[i].second + 1 << ' ';
        cout << endl;
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