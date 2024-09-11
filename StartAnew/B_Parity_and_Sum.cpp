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
    vector<ll> v(n); 

    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    ll pivot = n-1; 

    for(int i=n-1;i>=0; i--) 
    {
        if(v[i]%2)
        {
            pivot = i; 
            break;
        }
    }

    if(v[pivot]%2==0)
    {
        cout << 0 << endl; 
        return; 
    }

    ll x = v[pivot]; 

    ll ans = 0; 

    for(int i=pivot-1; i>=0; i--)
    {
        if(v[i]%2==0)
        {
            x += v[i]; 
            ans++; 
        }
    }

    for(int i=pivot+1; i<n; i++)
    {
        if(v[i]%2==0)
        {
            if(v[i]<x)
            {
                ans++; 
                x+= v[i];
            }
            else 
            {
                ll even =0; 
                for(int j=i; j<n; j++) if(v[j]%2==0) even++; 

                cout << ans + even + 1 << endl; 
                return; 
            }
        }
    }
    cout << ans << endl; 

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