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
    ll n, k; 
    cin >> n >> k; 
    vector<ll> marked(n+1, 0); 
    // for(auto &i: marked) cin >> i; 
    for(int i=0;i<k; i++)
    {
        ll x; 
        cin >> x; 
        marked[x] = 1; 
    }

    vector<vector<ll>> adj(n+1); 
    for(int i=1,u, v; i<n; i++)
    {
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
     
    vector<ll> dist(n+1, 0); 

    function<void(int, int)> dfs = [&] (int node, int fa)
    {
        for(auto child: adj[node])
        {
            if(child!=fa)
            {
                dist[child] = dist[node] + 1; 
                dfs(child, node); 
            }
        }
    };
    dfs(1, 0); 
    ll maxDist = -1, u; 
    for(int i=1;i<=n; i++)
    {
        if(dist[i]>maxDist and marked[i])
        {
            maxDist = dist[i], u = i; 
        }
    }

    dist[u] = 0;  
    dfs(u, 0); 

    maxDist = -1; 
    for(int i=1;i<=n; i++)
    {
        if(dist[i]>maxDist and marked[i])
        {
            maxDist = dist[i], u = i; 
        }
    }

    cout << (maxDist+1)/2 << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}