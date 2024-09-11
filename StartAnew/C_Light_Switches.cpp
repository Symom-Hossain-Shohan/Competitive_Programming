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
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    ll l = v.back(), r = v.back() + k - 1; 
    ll lsmall = r, rbig = l; 

    for(ll i=0; i<n; i++)
    {
        ll dif = (v.back()-v[i])/k; 
        if(dif%2==0)
        {
            l = v.back(), r = v.back()+k; 
            ll ans = r; 
            while(l<=r)
            {
                ll mid = (l+r)/2; 

                dif = (mid-v[i])/k; 
                if(dif%2==0)
                {
                    ans = mid; 
                    l = mid+1; 
                }
                else r = mid - 1; 
            }

            lsmall = min(lsmall, ans); 
        }
        else 
        {
            l = v.back(), r = v.back()+k; 
            ll ans = l;
            while(l<=r)
            {
                ll mid = (l+r)/2; 

                dif = (mid-v[i])/k;
                if(dif%2==0)
                {
                    ans = mid; 
                    r = mid-1; 
                }
                else l = mid+1; 
            } 

            rbig = max(rbig, ans); 
        }
    }

    // cout << lsmall << ' ' << rbig << endl; 

    if(lsmall<rbig) cout << -1 << endl; 
    else cout << rbig << endl; 

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