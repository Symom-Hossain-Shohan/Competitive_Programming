#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<ll> v(n); 
    for(auto &i:  v) cin >> i; 
    ll ans = 0; 
    sort(v.begin(),  v.end()); 
    for(int i=0;i<m;i++)
    {
        if(v[i]<0) ans += v[i];  
    }
    cout << abs(ans) << endl; 

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