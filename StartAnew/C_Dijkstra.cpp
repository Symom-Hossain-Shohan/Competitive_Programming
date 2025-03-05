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

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<vector<ll>> adj(n+1, vector<ll> (n+1)), cost(n+1, vector<ll> (n+1)); 

    for(int i=0;i<m ;i++)
    {
        ll u, v, w; 
        cin >> u >> v >> w; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        cost[u].push_back(w); 
        cost[v].push_back(w); 
    }

    vector<ll> dist(n+1, LLONG_MAX); 
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 
    pq.push({0, 1}); 
    dist[1] = 0; 
    vector<ll> parent(n+1, -1); 

    while(!pq.empty())
    {
        ll par = pq.top().second; 
        pq.pop(); 
        for(int i=0;i<adj[par].size(); i++)
        {
            ll child = adj[par][i]; 
            ll cst = cost[par][i]; 
            if(dist[child]>dist[par] + cst)
            {
                dist[child] = dist[par] + cst; 
                pq.push({dist[child], child}); 
                parent[child] = par; 
            }
        }
    }

    if(dist[n]==LLONG_MAX) cout << -1 << endl; 
    else 
    {
        vector<ll> ans; 
        ll cur = n; 
        while(cur!=-1)
        {
            ans.push_back(cur); 
            cur = parent[cur]; 
        }
        reverse(ans.rbegin(), ans.rend()); 
        for(auto it: ans) cout << it << ' '; 
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