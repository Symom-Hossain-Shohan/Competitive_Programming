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

ll n, k, z; 

ll ar[MX]; 

ll  memo[MX][3][6]; 

ll dp(ll pos, ll flag, ll left)
{
    if(pos + 2*(z-left)>k) return ar[pos]; 
    if(memo[pos][flag][left]!=-1) return memo[pos][flag][left]; 

    if(flag<2)
    {
        if(left > 0)
        {
            ll v1 = ar[pos] + dp(pos+1, 0, left); 
            ll v2 = ar[pos] + dp(pos-1, flag+1, left-1);
            return memo[pos][flag][left] = max(v1, v2); 
        } 
        else 
        {
            return memo[pos][flag][left] = ar[pos] + dp(pos+1, 0, left); 
        }
    }
    else 
    {
        return memo[pos][flag][left] = ar[pos] + dp(pos+1, 0, left); 
    }
}

void solve()
{
    cin >> n >> k >> z; 

    for(int i=1; i<=n; i++)
    {
        cin >> ar[i]; 
    }

    // ll memo[n+1][2][min(5ll, k)]; 
    // memset(memo, -1, sizeof(memo)); 

    for(int i=0;i<=n; i++)
    {
        for(int j=0;j<6; j++) memo[i][0][j] = memo[i][1][j] = memo[i][2][j] = -1; 
    }

    cout << dp(0, 0, z) << endl; 
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