#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
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
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 

    vector<vector<map<ll,ll>>> dp(n+1, vector<map<ll,ll>> (n+1)); 

    for(int i=0;i<n; i++)
    {
        for(int k=2; k<=n; k++)
        {
            for(int j=i+1;j<n; j++)
            {
                ll dif = v[j]-v[i]; 
                if(k==2)
                {
                    dp[j][k][dif]++; 
                    continue;
                }

                dp[j][k][dif] = modAdd(dp[j][k][dif],dp[i][k-1][dif]);
            }
        }
    }

    for(int i=1;i<=n; i++)
    {
        if(i==1) 
        {
            cout << n << ' '; 
            continue;
        }
        ll ans = 0; 
        for(auto j: dp)
        {
            for(auto k: j[i]) ans = modAdd(ans, k.second);
        }

        cout << ans << ' '; 
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