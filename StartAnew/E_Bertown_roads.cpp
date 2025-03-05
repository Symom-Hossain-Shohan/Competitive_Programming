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


void dfs(int node, int par, vector<vector<ll>> &adj, vector<ll> &in, vector<ll> &low, map<pair<ll, ll>, ll> &mp, vector<pair<ll, ll>> &edges, int &bridge, int &timer)
{
    if(bridge) return;


    in[node] = low[node] = ++timer;

    for(auto child: adj[node])
    {
        if(mp[{node, child}] ==0 and mp[{child, node}] == 0)
        {
            mp[{node, child}] = 1; 
            mp[{child, node}] = 1; 
            edges.push_back({node, child}); 
        }

        if(child == par) continue;
        if(in[child] == 0)
        {
            dfs(child, node, adj, in, low, mp, edges, bridge, timer);
            low[node] = min(low[node], low[child]); 
        }
        else 
        {
            low[node] = min(low[node], in[child]); 
        }
    }

    if(low[node] >= in[node] and node != 1)
    {
        bridge = 1; 
        return; 
    }
}


void solve()
{
    int n, m; 
    cin >> n >> m;
    vector<vector<ll>> adj(n+1, vector<ll> ()); 
    for(int i=0; i<m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    vector<ll> in(n+1, 0), low(n+1, 0); 
    map<pair<ll, ll>, ll> mp;
    vector<pair<ll, ll>> edges; 
    int bridge = 0, timer = 0; 
    dfs(1, 0, adj, in, low, mp, edges, bridge, timer); 


    if(bridge)
    {
        cout << 0 << endl;
    }
    else 
    {
        for(auto x: edges)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
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