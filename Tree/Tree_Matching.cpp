#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


ll dp[MX][2]; 

void dfs(vector<vector<ll>>&adj, ll node, ll par)
{
    for(auto child: adj[node])
    {
        if(child!=par)
        {
            dfs(adj, child, node); 
            dp[node][0] += max(dp[child][0], dp[child][1]); 
        }
    }

    for(auto child: adj[node])
    {
        if(child!=par)
        {
            // dfs(adj, child, node); 
            dp[node][1] = max(dp[node][1], 1 + dp[node][0] - max(dp[child][0], dp[child][1]) + dp[child][0]);  
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<vector<ll>> adj(n+1, vector<ll> ()); 
    
    for(int i=1;i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    dfs(adj, 1, -1); 
    cout << max(dp[1][0], dp[1][1]); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}