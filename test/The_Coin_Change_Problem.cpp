#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 51; 

ll v, n, coin[mx], memo[mx][251]; 




ll dp(ll pos, ll val)
{
    if(val == 0) return 1; 
    if(val<0) return 0; 
    if(pos==n) return 0; 

    ll &
    ans = memo[pos][val]; 

    if(ans == -1)
    {
        ans = dp(pos, val-coin[pos]) + dp(pos+1, val); 
    }
    return ans; 
}

void solve()
{
   
    cin >> v >> n; 
    for(int i=0;i<n;i++) cin >> coin[i]; 
    memset(memo, -1, sizeof(memo)); 

    cout << dp(0, v) << endl; 

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