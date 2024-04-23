#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sz, n; 

ll weight[2001], value[2001], memo[2001][2001]; 

ll dp(ll pos, ll wt)
{
    if(pos==n or wt==0) return 0; 

    ll &ans = memo[pos][wt]; 

    if(ans == -1)
    {
        if(weight[pos]<=wt) 
        {
            ans = max(value[pos] + dp(pos+1, wt-weight[pos]), dp(pos+1, wt)); 
        }
        else ans = dp(pos+1, wt); 
    }
    return ans; 
}

void solve()
{
    cin >> sz >> n; 

    for(int i=0;i<n;i++) cin >> weight[i] >> value[i]; 
    memset(memo, -1, sizeof(memo)); 

    cout << dp(0, sz) << endl; 
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