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

vector<ll> adj[MX]; 
ll n, m; 
ll mxLevel = 0; 
vector<ll> level(MX); 

vector<vector<pair<ll,ll>>> vp(MX, vector<pair<ll,ll>> ()); 

vector<ll> industry(MX, 0); 

vector<ll> depth(MX); 
vector<ll> subTree(MX); 

ll ans = 0; 

void dfs_calc(ll node, ll par, ll cnt = 0)
{
    if(industry[node]) ans += cnt; 
    else cnt++; 
    for(auto child: adj[node])
    {
        if(child != par)
        {
            dfs_calc(child, node, cnt); 
        }
    }
}

ll dfs(ll node, ll par)
{
    ll sz = 1; 
    
    for(auto child: adj[node])
    {
        if(child != par)
        {
            depth[child] = depth[node] + 1; 
            sz += dfs(child, node); 
        }
    }
    subTree[node] = sz; 
    return sz; 
}

bool cmp(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b)
{
    if(get<0>(a) == get<0>(b))
        return get<1> (a) > get<1> (b); 
    else return get<0>(a) < get<0> (b); 
}


void solve()
{
    cin >> n >> m; 
    for(int i=0;i<n-1; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }


    depth[1] = 0; 
    dfs(1, 0); 

    vector<tuple<ll,ll, ll>> vp; 
    vector<pair<ll,ll>> leaf; 
    for(int i=1;i<=n; i++) 
    {
        if(subTree[i]==1)
        {
            // industry[i] = 1; 
            leaf.push_back({depth[i], i}); 
            continue;
        }
        vp.push_back({depth[i], subTree[i], i}); 
    }

    sort(leaf.begin(), leaf.end()); 

    // for(auto i: leaf) cout << i.second << ' '; 
    // cout << endl; 

    // cout << m << endl; 
    // cout << leaf.size() << endl; 

    for(int i=(int)leaf.size()-1; i>=0 and m; i--, m--)
    {
        ll x = leaf[i].second; 
        industry[x] = 1; 
    }

    
    sort(vp.begin(), vp.end(), cmp); 
    // for(auto i: vp)
    // {
    //     cout << get<0> (i) << get<1> (i) << get<2> (i) << endl; 
    // }

    for(int i=vp.size()-1; i>=0 and m; i--, m--)
    {
        ll x = get<2> (vp[i]); 


        industry[x] = 1; 
    }
    
    dfs_calc(1, 0); 
    cout << ans << endl; 
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