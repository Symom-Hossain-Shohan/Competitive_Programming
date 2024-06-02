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


vector<ll> adj[505]; 
vector<ll> color(505); 
vector<ll> parent(505); 
ll cycles = 1e18; 

ll n, m; 

void bfs()
{
    ll ans = 1e18; 
    for(int i=1;i<=n;i++)
    {
        vector<ll> dist(n+1, 1e18); 

        vector<ll> par(n+1,-1); 
        dist[i] = 0; 
        queue<ll> q; 
        q.push(i); 

        while(!q.empty())
        {
            ll cur = q.front(); 
            q.pop(); 

            for(auto child: adj[cur])
            {
                if(dist[child] == 1e18)
                {
                    dist[child] = 1 + dist[cur]; 
                    q.push(child); 
                    par[child]= cur; 
                }
                else 
                {
                    if(par[cur] == child or par[child] == cur) continue;
                    else ans = min(ans, dist[child] + dist[cur] + 1);
                }
            }
        }
    }

    if(ans==1e18) cout << "impossible\n"; 
    else cout << ans << "\n"; 
}


void solve()
{
    // ll n, m; 
    cin >> n >> m; 

    if(n==2 and m==2)
    {
        cout << "2\n"; 
        return; 
    }

    for(int i=0;i<=n; i++) adj[i].clear(), color[i] = 0, parent[i] = -1; 

    for(int i=0; i<m; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        u++, v++; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    
    bfs(); 




}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}