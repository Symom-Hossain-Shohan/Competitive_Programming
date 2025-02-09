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
    ll n; 
    cin >> n; 
    vector<vector<ll>> adj(n+1, vector<ll> ()); 

    vector<ll> deg(n+1, 0); 
    for(int i=1;i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u);
        deg[u]++, deg[v]++; 
    }

    for(int i=1;i<=n; i++) sort(adj[i].begin(), adj[i].end());
    ll ans = 0; 
    for(int i=1;i<=n; i++)
    {
        for(auto child: adj[i])
        {
            ans = max(ans, deg[i] + deg[child] - 2); 
        }
    }

    vector<pair<ll,ll>> vp; 
    for(int i=1;i<=n; i++)
    {
        vp.push_back({deg[i], i}); 
    }

    sort(vp.rbegin(), vp.rend());

    for(int i=1;i<=n; i++)
    {
        for(int j=i+1;j<=n; j++)
        {
            ll u = vp[i-1].second, v = vp[j-1].second;
            if(binary_search(adj[u].begin(), adj[u].end(), v)) continue;
            ans = max(ans, vp[i-1].first + vp[j-1].first-1);
            break;
        }
    }

    cout << ans << endl; 
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