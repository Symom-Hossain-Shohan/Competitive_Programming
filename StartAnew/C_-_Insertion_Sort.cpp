#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(v[j-1]>v[j]) swap(v[j-1], v[j]);  
        }
        cout << v[0] ; 
        for(int k=1;k<n;k++) cout << ' ' << v[k]; 
        cout << endl; 
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