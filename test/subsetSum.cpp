#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, Sum, ar[100]; 

ll memo[20][100]; 


ll dp(ll pos, ll sum)
{
    if(sum==0) return 1;   
    if(pos==n) return 0; 

    ll &ans = memo[pos][sum]; 

    if(ans==-1) 
    {
        ans = dp(pos+1, sum-ar[pos])  + dp(pos+1, sum); 
    }
    return ans; 
}

void solve()
{
    cin >> n >> Sum; 
    for(int i=0;i<n;i++) cin >> ar[i]; 
    memset(memo, -1, sizeof(memo));  
    cout << dp(0, Sum) << endl; 
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