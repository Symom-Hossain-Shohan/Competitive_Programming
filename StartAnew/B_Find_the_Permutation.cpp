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
    ll n; 
    cin >> n; 
    char mtx[n+1][n+1]; 

    for(int i=1;i<=n; i++)
    {
        for(int j=1;j<=n; j++) cin >> mtx[i][j]; 
    }

    int ar[n+1] = {0};
    ll res[n+1] = {0}; 

    for(int i=1;i<=n; i++)
    {
        ll cnt = 0; 
        for(int j=i+1;j<=n;j++) 
        {
            if(mtx[i][j] == '0') cnt++; 
        }
        // cout << i << ' ' << cnt << endl;
        ll knt = 0; 
        for(int j=1;j<=n; j++)
        {
            if(ar[j]==0) knt++; 
            if(knt>cnt)
            {
                ar[j] = i; 
                break;
            }
        }
    }

    for(int i=1;i<=n; i++) cout << ar[i] << " ";
    cout << endl; 
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