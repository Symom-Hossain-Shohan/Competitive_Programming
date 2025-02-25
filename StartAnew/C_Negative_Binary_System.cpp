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

ll n; 
string s; 

ll calc(string s)
{
    ll p = 1; 
    ll res = 0; 
    reverse(s.begin(), s.end());
    for(auto i: s)
    {
        if(i=='1')
        {
            res += p; 
        }
        p *= -2; 
    }

    return res;
}

void solve()
{
    cin >> n >> s; 

    ll x = calc(s);
    // cout << x << endl; 
    if(x<0)
    {
        x = x/2; 
    }
    else 
    {
        x = (x+1)/2; 
    }
    // cout << x << endl; 
    string res = "";
    while(x!=0)
    {
        ll rem = x % (-2); 
        x /= -2;
        if(rem<0)
        {
            rem += 2;
            x++; 
        }

        res += to_string(rem);
        
    }
    reverse(res.begin(), res.end());
    if(res=="") res = "0";
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