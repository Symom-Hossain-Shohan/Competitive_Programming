#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 5005; 

ll memo[mx], n; 
string s;

ll dp(ll pos)
{
    if(pos>=n) return 1; 
    if(memo[pos]!=-1) return memo[pos]; 
    ll ans = 0; 
    if(s[pos]>='1') ans += dp(pos+1); 
    if(pos+1<n)
    {
        if(s[pos]=='1' and s[pos+1]<='9')  ans += dp(pos+2); 
        else if(s[pos]=='2' and s[pos]<='6') ans += dp(pos+2); 
    }
    return memo[pos] = ans; 
}

void solve()
{
     
    while(cin >> s)
    {
        if(s=="0") break;
        memset(memo, -1, sizeof(memo)); 
        n = s.length(); 
        cout << dp(0) << endl; 
    }
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