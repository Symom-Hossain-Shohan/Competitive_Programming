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
    vector<ll> a(n), b(m); 

    for(auto &i: a) cin >> i; 

    for(auto &i: b) cin >> i; 

    sort(a.begin(), a.end()); 

    ll g; 
    if(n==1)
    {
        g = a[0]; 
    }
    else 
    {
        g = a[1] - a[0]; 
    }

    for(int i=2; i<n; i++)
    {
        g = __gcd(g, a[i]-a[0]); 
    } 

    if(n==1)
    {
        for(int i=0;i<m; i++)
        {
            cout << a[0] + b[i] << ' '; 
        }
        return; 

    }
    // cout << g << endl; 

    for(int i=0;i<m; i++)
    {
        cout << __gcd(g, a[0]+ b[i]) << ' '; 
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