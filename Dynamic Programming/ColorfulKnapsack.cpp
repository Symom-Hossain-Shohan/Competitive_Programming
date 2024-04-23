#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 101; 

ll N, M, X, W[mx], C[mx];  
ll memo[mx][10002]; 
vector<ll> col[101]; 


ll dp(ll pos, ll wt)
{
    if(pos==101) 
    {
        if(wt<0) return 1e9+5; 
        else return wt; 
    } 
    ll &ans = memo[pos][wt]; 
    if(ans == -1)
    {
        if(col[pos].empty()) ans = dp(pos+1, wt); 
        else 
        {
            ll val = 1e10; 
            for(auto i: col[pos]) val = min(val, dp(pos+1, wt-i)); 
            ans = val; 
        }

    }
    return ans; 
}

void solve()
{
    cin>> N >> M >> X; 
    for(int i=0;i<=100;i++) col[i].clear(); 
    for(int i=0;i<N;i++) cin >> W[i]; 
    for(int i=0;i<N;i++)
    {
        cin >> C[i];  
        col[C[i]].push_back(W[i]); 
    }
    memset(memo, -1, sizeof(memo)); 
    ll ans = dp(0, X); 
    if(ans == 1e9+5)  cout << -1 <<endl;
    else cout << ans << endl; 
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