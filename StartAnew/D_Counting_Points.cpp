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


bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    return a.first-a.second < b.first-b.second;
}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<pair<ll,ll>> v(n);
    for(ll i=0; i<n; i++)
    {
        cin >> v[i].first;
    }
    for(ll i=0; i<n; i++)
    {
        cin >> v[i].second;
    }
    
    sort(v.begin(), v.end(), cmp);

    vector<ll> x(n), r(n);
    for(ll i=0; i<n; i++)
    {
        x[i] = v[i].first;
        r[i] = v[i].second;
    }

    ll ans = 0;
    ll j = 0, x1 = -1e18;
    for(ll i=0; i<n; i++)
    {
        x1 = max(x1, x[i]-r[i]); 
        while(x1<=x[i]+r[i])
        {
            while(j<n-1 and x[j+1]-r[j+1]<=x1)
            {
                j++; 
            }
            ll y = 0;
            for(ll ii=i; ii<=j; ii++)
            {
                y = max(y, (ll) sqrt(r[ii]*r[ii]-(x[ii]-x1)*(x[ii]-x1)));
            }
            ans += 2*y+1;
            x1++;
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