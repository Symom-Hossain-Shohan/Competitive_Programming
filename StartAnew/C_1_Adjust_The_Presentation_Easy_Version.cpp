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
    ll n, m, k; 
    cin >> n >> m >> k; 
    vector<ll> a(n), b(m), c; 
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 

    map<ll,ll> mp; 
    for(auto i: b)
    {
        if(mp[i]==0)
        {
            mp[i]++;
            c.push_back(i); 
        }
    }

    bool ok = true; 
    for(int i=0;i<(int)c.size(); i++)
    {
        if(a[i]!=c[i]) ok = false; 
    }
    if(ok) cout << "YA\n"; 
    else cout << "TIDAK\n"; 
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