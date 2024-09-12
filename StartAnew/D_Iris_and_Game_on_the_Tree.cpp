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


vector<ll> leaves; 


void dfs(ll node, ll par, vector<vector<ll>> &adj)
{
    for(auto child: adj[node])
    {
        if(adj[child].size()==1 and child != 1) leaves.push_back(child); 
        if(child!=par) dfs(child, node, adj); 
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<vector<ll>> adj(n+1, vector<ll>()); 
    for(ll i=1;i<n; i++){
        ll u, v; 
        cin >> u >> v; 

        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }

    string s; 
    cin >> s; 
    // vector<ll> leaves = dfs(1, -1, adj); 
    leaves.clear(); 
    dfs(1, -1, adj); 
    // for(auto i: leaves) cout << i << endl; 
    // cout << endl; 
    ll c_0 = 0, c_1=0, c_2 = 0; 


    for(auto i: leaves)
    {
        if(s[i-1]=='0') c_0++; 
        else if(s[i-1]=='1') c_1++; 
        else c_2++; 
    }

    // cout << c_0 << ' ' << c_1 << ' ' << c_2 << endl; 

    ll questions = count(s.begin(), s.end(), '?'); 

    // cout << questions << endl; 

    if(s[0]=='?')
    {
        ll mid = questions - 1 - c_2; 
        // cout << mid << endl; 
        if(c_1==c_0)
        {
            // cout << "yes\n";  
            if(mid%2==1)
            {
                // cout << "Yeh\n"; 
                cout << max(c_0, c_1) + (c_2+1)/2 << endl; 
            }
            else cout << max(c_0, c_1) + c_2/2 << endl; 
        }
        else 
        {
            cout << max(c_1, c_0) + c_2/2 << endl;  
        }
    }
    else 
    {
        if(s[0]=='1') cout << c_0 + (c_2+1)/2 << endl; 
        else cout << c_1 + (c_2+1)/2 << endl; 
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