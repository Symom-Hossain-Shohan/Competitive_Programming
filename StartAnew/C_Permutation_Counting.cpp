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

bool good(vector<ll> &v, ll k, ll mid)
{
    ll cnt = 0; 
    for(auto i: v)
    {
        if(i<mid) cnt += mid-i; 
    }

    return cnt<=k; 
}


void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    ll l = v[0], r = v[n-1] + k; 
    ll ans = -1; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 

        if(good(v, k, mid))
        {
            ans = mid; 
            l = mid + 1; 
        }
        else r = mid - 1; 
    }

    // cout << ans << endl; 
    for(int i=0;i<n; i++)
    {
        if(v[i]<ans) k-= (ans-v[i]), v[i] = ans;  
    }

    for(int i=n-1;i>=0; i--)
    {
        if(v[i]==ans and k) v[i]++, k--; 
    }

    ll res = n*v[0] - (n-1); 
    for(int i=0;i<n; i++) if(v[i]>ans) res++; 
    cout << res << endl; 
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