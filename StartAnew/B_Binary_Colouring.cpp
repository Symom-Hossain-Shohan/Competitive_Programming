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
    vector<ll> v(32, 0); 

    for(int i=0; i<32; i++)
    {
        v[i] = n%2; 
        n/=2; 
    }

    // for(auto i: v) cout << i <<' '; 
    // cout << endl; 

    ll cnt=0; 
    for(int i=0;i<31; i++)
    {
        if(v[i]==1)
        {
            cnt++; 
        }
        else
        {
            if(cnt>1)
            {
                v[i] = 1; 
                ll l = i - cnt; 
                v[l] = -1; 
                l++; 
                while(l<i)
                {
                    v[l] = 0; 
                    l++; 
                }
                i--; 
            }
            cnt=0; 
        }
        
    }

    while (v.back()==0) 
    {
        v.pop_back(); 
    }
    cout << v.size() << endl; 
    for(auto i: v)  cout << i << ' '; 
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