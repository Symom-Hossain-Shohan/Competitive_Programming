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
    ll n, m, x; 
    cin >> n >> m >> x; 
    map<ll,set<ll>> st; 

    ll lvl = 1; 
    st[0].insert(x); 
    for(int i=0;i<m; i++)
    {
        ll d; 
        cin >> d; 
        char c; 
        cin >> c; 
        if(c=='?')
        {
            for(auto i: st[lvl-1])
            {
                ll nxt = i - d; 
                if(nxt<=0) nxt += n; 

                st[lvl].insert(nxt); 
            }
            for(auto i: st[lvl-1])
            {
                ll nxt = i + d; 
                if(nxt>n) nxt -= n; 

                st[lvl].insert(nxt); 
            }
        }
        else if(c=='1')
        {
            for(auto i: st[lvl-1])
            {
                ll nxt = i - d; 
                if(nxt<=0) nxt += n; 

                st[lvl].insert(nxt); 
            }
        }
        else 
        {
            for(auto i: st[lvl-1])
            {
                ll nxt = i + d; 
                if(nxt>n) nxt -= n; 

                st[lvl].insert(nxt); 
            }
        }
        lvl++; 
    }
    lvl--; 
    cout << st[lvl].size() << endl; 
    for(auto i: st[lvl]) cout << i << ' '; 
    cout << endl; 
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