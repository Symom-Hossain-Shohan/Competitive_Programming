#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mx = 2e5 + 1;

ll cost[mx], memo[mx], n;

ll dp(ll pos)
{
    if (pos >= n)
        return 0;
    if (memo[pos] != -1)
        return memo[pos];
    return memo[pos] = cost[pos] + min(dp(pos+1), min(dp(pos+2), dp(pos+3))); 
    

}

void solve()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    memset(memo, -1, sizeof(memo));

    cout << min(dp(0) , min(dp(1) , dp(2) )) << endl;
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