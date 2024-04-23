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
    vector<vector<int>> g(n+1, vector<int> ()); 

    map<pair<ll,ll>, ll> mp; 
    vector<ll> indegree(n+1, 0); 
    for(int i=0;i<m; i++)
    {
        ll u, v, w; 
        cin >> u >> v >> w; 
        g[u].push_back(v); 
        indegree[v]++; 
        mp[{u, v}] = w; 
    }

    vector<bool> visited(n+1, false); 
    ll mxDepth = 1e18, last = -1; 
    auto dfs = [&](auto self, int node) ->void{
        visited[node] = true; 
        last = node; 
        for(auto child: g[node])
        {
            if(!visited[child])
            {
                self(self, child); 
                mxDepth = min(mxDepth, mp[{node, child}]); 
            }
        }
    }; 

    vector<tuple<ll,ll,ll>> ans; 
    for(int i=1;i<=n; i++)
    {
        if(indegree[i]==0) 
        {
            mxDepth = 1e18; 
            dfs(dfs, i); 
            if(i!=last)
            ans.push_back({i, last, mxDepth}); 
        }
    }

    cout << ans.size() << endl; 
    for(auto i: ans)
    {
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << endl; 
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