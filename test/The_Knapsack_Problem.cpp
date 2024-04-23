#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, n;  

ll memo[2001][2001];  
ll wt[2001], cost[2001];  


ll dp(ll pos, ll W)
{
    if(W==0) return 0; 
    if(pos==n) return 0; 

    ll &ans = memo[pos][W]; 

    if(ans==-1)
    {
        if(W>=wt[pos]) ans = max(cost[pos] + dp(pos+1, W-wt[pos]), dp(pos+1, W)); 
        else ans = dp(pos+1, W); 
    }

    return ans; 
}

void solve()
{
    cin >> s >> n;  
    memset(memo, -1, sizeof(memo));  
    for(int i=0;i<n;i++) cin >> wt[i] >> cost[i]; 

    cout << dp(0, s)<< endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}