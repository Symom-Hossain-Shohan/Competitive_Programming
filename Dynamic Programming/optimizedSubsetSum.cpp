#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll sum, n;
    cin >> sum >> n;
    int ar[n + 2];
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    int dp[2][sum + 1];

    dp[0][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[1][j] = dp[0][j];
            if (j - ar[i] >= 0)
                dp[1][j] |= dp[0][j - ar[i]];
        }

        for (int j = 0; j <= sum; j++)
            dp[0][j] = dp[1][j];
    }

    if (dp[1][sum])
        cout << "Possible\n";
    else
        cout << "Not Possible\n";
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