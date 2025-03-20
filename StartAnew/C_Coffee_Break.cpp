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
    ll n, m, d; 
    cin >> n >> m >> d; 
    set<pair<ll, ll>> q; 

    for(ll i=0;i<n; i++)
    {
        ll x;
        cin >> x;
        q.insert({x, i});
    }
    ll cnt = 1; 
    vector<ll> ans(n);
    while (!q.empty())
    {
        auto it = q.begin();
        ll pos = it->second; 
        ll val = it->first;
        ans[pos] = cnt;
        q.erase(it);
        while (true)
        {
            auto it = q.lower_bound({val + d+1, 0});
            if (it == q.end())
                break;
            pos = it->second;
            val = it->first;
            ans[pos] = cnt;
            q.erase(it);
        }
        cnt++;
    }
    cout << cnt-1 << endl; 
    for(auto i: ans) cout << i << " ";
    
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