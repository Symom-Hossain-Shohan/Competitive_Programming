#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
vector<ll> H;
vector<ll> memo;

ll dp(ll pos)
{
    if (pos >= n - 1)
        return 0;
    if (memo[pos] != -1)
        return memo[pos];
    ll v1 = 1e18, v2 = 1e18;
    if (pos + 1 < n)
        v1 = dp(pos + 1) + abs(H[pos] - H[pos + 1]);
    if (pos + 2 < n)
        v2 = dp(pos + 2) + abs(H[pos] - H[pos + 2]);
    return memo[pos] = min(v1, v2);
}

void solve()
{
    cin >> n;
    H.resize(n);
    memo.resize(n + 1, -1);
    for (auto &i : H)
        cin >> i;

    cout << dp(0) << endl;
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