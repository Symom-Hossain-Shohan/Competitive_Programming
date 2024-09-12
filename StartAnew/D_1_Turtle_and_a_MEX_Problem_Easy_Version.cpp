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
    ll mex = 0; 
    while(n--)
    {
        ll l; 
        cin >> l; 
        set<ll> st; 
        while(l--)
        {
            ll a; 
            cin >> a; 
            st.insert(a); 
        }

        ll j = 0, ok = 0; 
        while(true)
        {
            if(st.find(j)==st.end())
            {
                if(ok==0) ok = 1; 
                else 
                {
                    mex = max(mex, j); 
                    break;
                }
            }
            j++; 
        }

    }

    ll ans = 0; 
    if(m<=mex)  cout << mex*(m+1) << endl; 
    else cout << mex*(mex+1) + m*(m+1)/2 - mex*(mex+1)/2 << endl; 
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