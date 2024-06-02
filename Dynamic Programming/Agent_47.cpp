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
ll n; 
vector<ll> health(15); 
ll mtx[15][15]; 

const ll mx = ((1<<16)+1); 
ll dp[mx]; 


ll fun(ll mask)
{
    if(mask==((1<<n)-1))
    {
        return 0; 
    }    

    if(dp[mask]!=-1) return dp[mask]; 

    // vector<ll> hit(n); 
    // for(int i=0;i<n; i++) hit[i] = 1; 

    // for(ll i=0;i<n; i++)
    // {
    //     if((mask & (1<<i))==1)
    //     {
    //         for(ll j=0;j<n; j++)
    //         {
    //             hit[j] = max(hit[j], mtx[i][j]); 
    //         }
    //     }
    // }   

    ll val = LLONG_MAX - 1000000000000000;; 
    for(ll i=0;i<n; i++)
    {
        if((mask & (1<<i))==0)
        {
            for(int j=0;j<n; j++)
            {
                if((mask & (1<<j))!=0)
                {
                    if(mtx[j][i])
                    {
                        val = min(val, (health[i]+mtx[j][i]-1)/mtx[j][i] + fun(mask | (1<<i))); 
                    }
                }
            }
            val = min(val, health[i] + fun(mask | (1<<i))); 
        }
    }

    return dp[mask] = val; 

}

void solve()
{
    cin >> n; 
    for(int i=0;i<n; i++) cin >> health[i]; 
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            char c; 
            cin >> c; 
            mtx[i][j] = c-'0'; 
        }
    }

    memset(dp, -1, sizeof(dp)); 
    cout << fun(0) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}