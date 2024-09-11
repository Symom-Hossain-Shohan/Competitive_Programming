#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=3e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll dp[MX]; 

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    ll left = n; 
    while(k--)
    {
        ll r, c; 
        cin >> r >> c; 
        if(r==c) left--; 
        else left -= 2; 
    }

    cout << dp[left] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    dp[0] = dp[1] = 1; 
    for(int i=2;i<MX; i++)
    {
        dp[i] = (dp[i-1] + 2*(i-1)*(dp[i-2])) %  mod; 
    }
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}