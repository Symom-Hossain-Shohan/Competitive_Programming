#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 300005; 

vector<ll> adj[mx]; 

void solve()
{
    ll n, a, b; 
    cin >> n >> a >> b; 
    for(int i=1;i<n;i++)
    {
        ll u,v; 
        cin >> u >> v; 
        adj[u].push_back(v), adj[v].push_back(u);  
    }

    vector<ll> dist_a(n+1); 
    dist_a[a] = 0;  
    vector<bool> visited(n+1, false);  
    visited[a] = true;  
    queue<ll> q; 
    q.push(a); 
    while(!q.empty())
    {
        ll cur = q.front(); 
        q.pop(); 
        for(auto child: adj[cur])
        {
            if(!visited[child])
            {
                visited[child] = true; 
                dist_a[child] = dist_a[cur] + 1; 
                q.push(child);  
            }
        }
    } 
    for(int i=1;i<=n;i++) cout << dist_a[i] << ' '; 
      
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}