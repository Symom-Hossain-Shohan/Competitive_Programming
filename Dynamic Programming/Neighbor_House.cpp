#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll rgb[25][3];
ll memo[25][3];

ll n;

ll dp(ll pos, ll col)
{
    if(pos==n) return 0; 
    ll &ans = memo[pos][col];

    if(ans == -1)
    {
        ans = rgb[pos][col] ; 
        if(col==0)
        {
            ans += min(dp(pos+1, 1), dp(pos+1,2 )); 
        }
        else if(col==1)
        {
            ans += min(dp(pos+1, 0), dp(pos+1, 2)); 
        }
        else
        {
            ans += min(dp(pos+1, 0), dp(pos+1, 1));
        }
    }
    return ans; 
}

void solve()
{
    
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    memset(memo, -1, sizeof(memo));

    cout << min({dp(0, 0), dp(0, 1), dp(0, 2)}) << endl; 
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