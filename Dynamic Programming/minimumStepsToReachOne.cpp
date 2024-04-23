#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll,ll> memo; 

ll dp(ll n)
{
    if(n == 1) return 0; 
    else if(memo.find(n)!=memo.end()) return memo[n]; 
    ll v1 = 1 + dp(n-1), v2 = 1e18, v3 = 1e18; 
    if(n%2==0) v2 = 1 + dp(n/2); 
    if(n%3==0) v3 = 1 + dp(n/3); 

    return memo[n] = min({v1, v2, v3});     
}

void solve()
{


    ll n;
    cin >> n; 
    cout << dp(n) <<endl; 

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