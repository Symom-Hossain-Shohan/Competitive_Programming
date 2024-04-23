#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=1e6+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll coins[101], memo[MX]; 
ll n, m; 

ll dp(ll sum)
{
    if(sum==0) return 1; 
    if(memo[sum]==-1)
    {
        ll v = 0; 
        for(int i=0;i<n; i++)
        {
            if(coins[i]<=sum)
            {
                v = (v + dp(sum-coins[i]) + dp(sum)) % mod; 
            }
        }
    }
}


void solve()
{
    cin >> n >> m; 
    for(int i=0;i<n; i++) cin >> coins[i]; 
    memset(memo, -1, sizeof(memo)); 
    cout << dp(m) << endl; 
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