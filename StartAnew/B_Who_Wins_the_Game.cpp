#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=3000+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll memo[MX][MX][2]; 
ll ar[MX]; 
ll n; 


ll dp(ll fst, ll lst, ll flag)
{
    // cout << fst << " " << lst << " " << flag << endl;
    // cout << memo[fst][lst][flag] << endl;
    
    if(fst>=n || lst<0) return 0;
    if(fst>lst) return 0;
    if(memo[fst][lst][flag]!=-1e13) return memo[fst][lst][flag];

    

    if(flag==0)
    {
        ll v1 = ar[fst] + dp(fst+1, lst, 1);
        ll v2 = ar[lst] + dp(fst, lst-1, 1);
        return memo[fst][lst][flag] = max(v1, v2);
    }
    else 
    {
        ll v1 = -ar[fst] + dp(fst+1, lst, 0);
        ll v2 = -ar[lst] + dp(fst, lst-1, 0);
        return memo[fst][lst][flag] = min(v1, v2);
    }

    
}

void solve()
{
    cin >> n; 
    for(int i=0;i<n; i++)
    {
        cin >> ar[i];
    }

    for(int i=0;i<=n; i++)
    {
        for(int j=0;j<=n; j++)
        {
            memo[i][j][0] = -1e13; 
            memo[i][j][1] = -1e13; 
        }
    }

    ll ans = dp(0, n-1, 0); 
    // cout << ans << endl; 
    if(ans==0) 
    {
        cout << ans << "  Both Chocolates are same\n"; 
    }
    else if(ans>0)
    {
        cout << ans << " Rajib\n"; 
    }
    else 
    {
        cout << -ans << " Rakib\n"; 
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