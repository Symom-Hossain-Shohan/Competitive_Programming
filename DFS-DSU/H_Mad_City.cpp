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
    int n, a, b; 
    cin >> n >> a >> b; 
    vector<vector<int>> g(n+1); 
    for(int i=0, u, v; i<n; i++)
    {
        cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }

    vector<int> dep(n+1, -1),  par(n+1); 
    dep[b]  = 0; 
    int root = 0; 
    
    function<void(int)> dfs = [&](int u){
        for (auto child: g[u])
        {
            if(dep[child] == -1)
            {
                par[child]= u; 
                dep[child] = dep[u] + 1; 
                dfs(child); 
            }
            else if(dep[child]< dep[u] and par[u] != child)
            {
                root = child; 
            }
        }
    };

    dfs(b); 
    vector<int> d(n+1, -1); 
    d[root] = 0; 
    queue<int> q; 
    q.push(root); 
    while(!q.empty())
    {
        int cur = q.front(); 
        q.pop(); 
        for(auto child: g[cur])
        {
            if(d[child]==-1)
            {
                q.push(child); 
                d[child] = d[cur] + 1; 
            }
        }
    }

    if(d[a]>d[b] ) cout << "YES\n"; 
    else cout << "NO\n"; 
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