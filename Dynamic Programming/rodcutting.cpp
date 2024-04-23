#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 1e5;
int ar[mx], n;
ll memo[mx];

ll dp(ll ln)
{
    if (ln == 0)
        return 0;
    else if (memo[ln] != -1)
        return memo[ln];
    ll ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (ln - i >= 0)
            ans = max(ans, ar[i] + dp(ln - i));
    }

    return memo[ln] = ans;
}

void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    memset(memo, -1, sizeof(memo));

    cout << dp(n) << endl;
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