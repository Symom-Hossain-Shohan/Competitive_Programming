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
    ll n, x; 
    cin >> n >> x; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    vector<ll> ans(n, 0); 
    vector<pair<ll, ll>> u, v; 
    for(ll i=0; i<n; i++)
    {
        u.push_back({a[i], i});
        v.push_back({b[i], i});
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    for(int i=x-1, j=n-1; i>=0; i--, j--)
    {
        ans[u[j].second] = v[i].first; 
    }

    // for(auto i: ans) cout << i << " ";
    for(int i=0, j=x;i<n-x; i++, j++)
    {
        ans[u[i].second] = v[j].first;
    }

    // for(auto i: ans) cout << i << " ";
    ll cnt_get = 0; 
    for(int i=0; i<n; i++)
    {
        if(a[i]>ans[i]) cnt_get++;
    }

    if(cnt_get==x)
    {
        cout << "YES" << endl;
        for(auto i: ans) cout << i << " ";
        cout << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }
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