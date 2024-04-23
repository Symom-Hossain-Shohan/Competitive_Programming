#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, marriage[17][17];

ll memo[17][65537];

ll dp(ll row, ll x)
{
    if(row==n) return 0; 

    ll &ans = memo[row][x];

    //cout << x << endl;  

    if(ans == -1)
    {
        ll res = 0; 
        for(int i=0;i<n;i++)
        {
            if(((1<<i)&x)  )
            {
                //cout << "yes\n";
                continue;
            }
            else 
            {
                //cout << "no\n";
                res = max(res, marriage[row][i] + dp(row+1, (x|(1<<i))));
            }
        }
        ans = res; 
    }
    return ans; 
}


void solve()
{
    cin >> n ;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++) cin >> marriage[i][j];
    }

    ll ans = 0; 
    memset(memo, -1, sizeof(memo));
    for(int i=0;i<n;i++)
    {
        ans = max(ans, dp(0, 0)); 
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}