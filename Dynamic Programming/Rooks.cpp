#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[35][35], fact[20];

ll ncr(ll n, ll r)
{
    if(n==r or r==0) return 1; 
    if(r==1) return n; 
    ll ans = dp[n][r]; 
    if(ans == -1)
    {
        ans = ncr(n-1, r-1)  + ncr(n-1, r);
    }
    return ans; 
}

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    ll res = 0; 
    if(n>=k) res = ncr(n, k);
    cout << res*res* fact[k] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    memset(dp, -1, sizeof(dp));
    fact[0] = fact[1] = 1; 
    for(int i=2;i<20;i++) fact[i] = fact[i-1] * i; 
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}