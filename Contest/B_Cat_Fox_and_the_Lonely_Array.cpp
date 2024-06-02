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

bool good(vector<vector<ll>> &v, ll mid)
{
    vector<ll> tmp = v[mid-1]; 
    bool ok = true; 
    for(int i=mid; i<(v.size()); i++)
    {
        vector<ll> nww; 
        for(int j=0;j<22; j++) 
        {
            ll x = v[i][j] - v[i-mid][j]; 

            if(x==0 and tmp[j]!=0) ok = false; 
            else if(x!=0 and tmp[j]==0) ok = false; 
        }
    }

    return ok; 
}

void solve()
{
    ll n; 
    cin >>n; 
    vector<vector<ll>>v(n); 
    for(int i=0;i<n; i++)
    {
        ll x; 
        cin >> x; 
        vector<ll> vv; 
        for(int j=0;j<22; j++)
        {
            vv.push_back(x%2); 
            x/=2;
        }

        reverse(vv.begin(), vv.end()); 
        v[i] = vv; 
    }

    for(int i=1;i<n; i++)
    {
        for(int j=0;j<22;j++)
        {
            v[i][j] += v[i-1][j]; 
        }
    }

    ll l = 1, r = n; 
    ll ans = n; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        if(good(v, mid))
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
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}