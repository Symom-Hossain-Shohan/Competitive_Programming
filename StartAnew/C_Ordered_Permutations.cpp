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

ll n, k; 
void fun(ll l, ll r, ll k, ll i, vector<ll> &v)
{
    if(i>n) return; 
    if(k>pow(2, r-l-1))
    {
        v[r] = i; 
        return fun(l, r-1, (k-pow(2, r-l-1)), i+1, v); 
    }
    else 
    {
        v[l] = i; 
        return fun(l+1, r, k, i+1, v); 
    }
}

void solve()
{

    cin >> n >> k; 
    if(k>pow(2, n-1)) cout << -1 << endl; 
    else 
    {
        vector<ll> v(n); 
        fun(0, n-1, k, 1, v); 
        for(auto i: v) cout << i << ' '; 
        cout << endl; 
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