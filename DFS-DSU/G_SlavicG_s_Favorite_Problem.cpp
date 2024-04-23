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

ll n, a, b; 
vector<ll> adj[MX], cost[MX]; 
set<ll> st; 

bool flag; 
void dfs(ll node, ll par, ll x)
{
    st.insert(x); 
    for(int i=0;i<(int)adj[node].size(); i++)
    {
        ll child = adj[node][i], cst = cost[node][i]; 

        if(child!=par and child!=b) dfs(child, node, x^cst); 
    }
}

void dfs_(ll node, ll par, ll x)
{
    if(node!=b and st.count(x))
    {
        flag = true; 
    }

    if(flag) return;

    for(int i=0;i<(int)adj[node].size(); i++)
    {
        ll child = adj[node][i], cst = cost[node][i]; 

        if(child!=par and child!=b) dfs_(child, node, x^cst); 
    }
}

void solve()
{
    cin >> n >> a >> b; 
    st.clear(); 
    flag = false; 
    for(int i=0;i<=n; i++)
    {
        adj[i].clear(), cost[i].clear();
    }

    for(int i=1;i<n; i++)
    {
        ll u, v, w; 
        cin >> u >> v >> w; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        cost[u].push_back(w); 
        cost[v].push_back(w); 
    }

    dfs(a, -1, 0); 
    dfs_(b, -1, 0);

    if(flag) cout << "YES\n"; 
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