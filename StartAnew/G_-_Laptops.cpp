#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> v(n); 
    for(auto &i: v) cin >> i.first >> i.second; 
    sort(v.begin(), v.end());  
    bool ok = false; 
    
    for(int i=0;i<n-1;i++)
    {
        if(v[i].first<v[i+1].first and v[i].second > v[i+1].second)
        {
            ok = true; 
            break;
        }
    }
    if(ok) cout << "Happy Alex\n"; 
    else cout <<  "Poor Alex\n"; 
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