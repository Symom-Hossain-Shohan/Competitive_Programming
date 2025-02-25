#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2000000+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll d, x, y; 
ll memo[MX]; 

ll dp(ll pos)
{
    cout << pos << endl;
    cout << memo[pos] << endl;
    if(pos>d) return 1e18; 
    if(pos==d) return 0;

    if(memo[pos]!=-1) return memo[pos];

    ll v1 = 1e18, v2 = 1e18;
    if(pos%2==0)
    {
        if(pos+1<=d)
        {
            v1 = y + dp(pos+1);
        }
    }
    if(pos*2<=d)
    {
        v2 = x + dp(pos*2);
    }

    return memo[pos] = min(v1, v2);
    
}


void solve()
{
    cin >> d >> x >> y; 

    for(int i=0;i<=d; i++) memo[i] = -1;

    cout << dp(0) << endl; 

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