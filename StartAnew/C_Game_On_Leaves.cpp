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
    vector<vector<ll>> adj(n+1);
    for(ll i=1; i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> level(n+1, -1); 
    queue<ll> q;
    q.push(k); 
    level[k] = 0;
    while(!q.empty())
    {
        ll u = q.front(); q.pop();
        for(auto v: adj[u])
        {
            if(level[v]==-1)
            {
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }

    ll cnt = 0; 
    for(ll i=1; i<=n; i++)
    {
        if(level[i]>1) cnt++; 
    }
    cnt+=adj[k].size()-1; 

    if(adj[k].size()<=1)
    {
        cout << "Ayush\n";
        return; 
    }

    if(cnt%2)
    {
        cout << "Ashish\n";
    }
    else
    {
        cout << "Ayush\n";
    }
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