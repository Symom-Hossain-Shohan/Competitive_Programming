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


ll func(ll n)
{
    ll l = 1, r = n;
    ll ans = 1;  
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        if(mid*(mid+1)/2<=n)
        {
            l = mid+1; 
            ans = mid; 
        }
        else r = mid-1; 
    }
    return ans; 
}

void solve()
{
    ll n; 
    cin >> n; 
    char c = 'a'; 
    string s = "";
    if(n==0)
    {
        cout << c << endl; 
        return;
    }

    while(n)
    {
        ll t = func(n);
        n -= t *(t+1)/2; 
        // cout << t << endl; 
        t++; 
        while (t--)
        {
            s.push_back(c);
        }
        c++; 
    }
    cout << s << endl; 
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