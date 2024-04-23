#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mem [101][101]; 

int n, m; 

ll dp(ll i, ll j)
{
    if(i==n-1 and j==m-1)
    {
        return 1; 
    }
    return 0;
}

void solve()
{
    
    cin >> n >> m; 
    memset(mem, -1, sizeof(mem)); 
    cout << dp(0, 0) << endl; 
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