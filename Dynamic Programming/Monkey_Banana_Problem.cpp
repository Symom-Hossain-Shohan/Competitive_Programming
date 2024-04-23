#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    ll mtx[2 * n - 1][n];
    memset(mtx, 0, sizeof(mtx));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> mtx[i][j];
    }

    ll sft = 1;
    for (int i = n; i < 2 * n - 1; i++)
    {
        for (int j = sft; j < n; j++)
            cin >> mtx[i][j];
        sft++;
    }

    ll dp[2*n-1][n];

    memset(dp, 0, sizeof(dp)); 

    dp[0][0] = mtx[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0) dp[i][j] = mtx[i][j] + dp[i-1][j];
            else dp[i][j] = mtx[i][j] + max(dp[i-1][j], dp[i-1][j-1]); 
        }
    }
    sft = 1; 
    for(int i=n;i<2*n-1;i++)
    {
        for(int j= sft;j<n;j++)
        {
            dp[i][j] = mtx[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    cout << dp[2*n-2][n-1] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}