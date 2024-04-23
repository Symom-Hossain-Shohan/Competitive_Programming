#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll,ll> mp;
ll n;

ll dp(ll num)
{
    if(num==1) return 0;  
    if(mp.find(num) != mp.end()) return mp[num];  
    ll v1 = dp(num-1) + 1, v2 = 1e18, v3 = 1e18; 
    if(num%2==0) v2 = 1 + dp(num/2); 
    if(num%3==0) v3 = 1 + dp(num/3); 

    return mp[num] = min({v1, v2, v3});  
}

void solve()
{
    cin >> n; 
    cout << dp(n) << endl; 
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