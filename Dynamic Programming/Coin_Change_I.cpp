#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll coin[51], numb[51], n, k; 

ll memo[51][22][1005], mod =  100000007;

ll dp(ll pos, ll times, ll val)
{
    if(val ==0 ) return 1; 
    if(pos==n) return 0; 

    if(memo[pos][times][val]!=-1) return memo[pos][times][val];
    ll ans = 0; 

    if(coin[pos]<=val and times<numb[pos]) ans += (dp(pos, times+1, val-coin[pos]) + dp(pos+1, 0, val)%mod);
    else ans += dp(pos+1, 0,val);

    return memo[pos][times][val] = ans % mod;  
}

void solve()
{
    cin >> n >> k; 
    for(int i=0;i<n;i++) cin >> coin[i];
    for(int i=0;i<n;i++) cin >> numb[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, k) % mod << endl; 
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