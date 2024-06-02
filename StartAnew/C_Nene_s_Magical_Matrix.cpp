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
    if(n==1)
    {
        cout << "1 1\n1 1 1\n"; 
    }
    else if(n==2)
    {
        vector<vector<ll>> v; 

        for(int i=0;i<n; i++)
        {
            vector<ll> vv; 
            vv.push_back(1); 
            vv.push_back(i+1); 
            vv.push_back(n); 
            for(int j=1;j<n; j++) vv.push_back(j); 
            v.push_back(vv); 
        }

        ll x = n*(n+1)/2; 
        ll ans = 0; 
        ans += n*n; 
        for(int i=1;i<n; i++)
        {
            if(n*i<x)
            {
                vector<ll> vv; 
                vv.push_back(2); 
                vv.push_back(i+1); 
                vv.push_back(n); 
                for(int j=1;j<n; j++) vv.push_back(j); 
                v.push_back(vv);
            }
            ans += max(n*i, x); 
        }

        cout << ans << ' ' << v.size() << endl; 
        for(auto i: v)
        {
            for(auto j: i) cout << j << ' '; 
            cout << '\n'; 
        }
    }
    else 
    {
        ll sum = 0; 
        for(int i=1;i<=n; i++) sum += i*(2*i-1); 

        cout << sum << ' ' << 2*n << endl; 
        for(int i =n;i>=1; i--)
        {
            cout << 1 << ' ' << i << ' '; 
            for(int j=1;j<=n; j++) cout << j << ' '; 
            cout << '\n';
            cout << 2 << ' ' << i << ' '; 
            for(int j=1;j<=n; j++) cout << j << ' '; 
            cout << '\n'; 
        }
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