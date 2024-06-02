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

ll n, k; 
vector<ll> v; 

bool good(ll val)
{
    ll cnt = 0; 
    ll sum = 0; 

    for(int i=0;i<n; i++)
    {
        if(sum + v[i]>val)
        {
            // if(v[i]>val) return false;  
            sum = v[i]; 
            cnt++; 
        }
        else sum += v[i]; 
    }
    if(sum) cnt++; 
    return cnt<=k; 
}

void solve()
{
    cin >> n >> k; 
    v.resize(n); 

    for(auto &i: v) cin >> i; 

    ll l = *max_element(v.begin(), v.end()), r = accumulate(v.begin(), v.end(), 0LL); 
    ll ans = -1; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        // cout << mid << endl; 
        if(good(mid))
        {
            ans = mid; 
            r = mid-1; 
        }
        else l = mid+1; 
    }

    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}