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
    string s, t; 
    cin >> s >> t; 
    s += ".."; 
    t += ".."; 

    priority_queue<pair<pair<ll, ll>, string>> pq; 
    map<string, ll> dist; 

    pq.push({{0, n}, s}); 

    while(!pq.empty())
    {
        auto tp = pq.top(); 
        pq.pop(); 

        string cur = tp.second; 
        if(dist.count(cur)) continue;
        ll op = tp.first.first, idx = tp.first.second; 

        dist[cur] = -op; 
        for(ll j=0;j<n+1; j++)
        {
            if(j==idx || j+1==idx || j==idx+1 || j+1==idx+1)
                continue;
            string nS = cur; 

            nS[idx] = j; 
            nS[idx+1] = j+1; 
            nS[j] = nS[j+1] = '.'; 
            pq.push({{op-1, j}, nS}); 

        }
    }

    if(dist.count(t)) cout << dist[t] << '\n';
    else cout << -1 << '\n';  

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