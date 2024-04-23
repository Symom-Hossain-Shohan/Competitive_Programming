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

ll ask(ll x, ll y)
{
    cout << "? " << x << ' ' << y << endl; 
    ll d; 
    cin >> d; 
    return d; 
}

void ans(ll x, ll y)
{
    cout << "! " << x << ' ' << y << endl; 
    // cout << "YES\n"; 
    return; 
}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    ll d1 = ask(1,1); 
    ll d2 = ask(1, m); 
    ll d3 = ask(n, 1); 

    if(d1==0)
    {
        ans(1, 1); 
        return; 
    }
    if(d2==0)
    {
        ans(1, m); 
        return; 
    }
    if(d3==0)
    {
        ans(n, 1); 
        return; 
    }

    if(d1+d3>=n-1)
    {
        if((d1+d3-n+1)%2==0)
        {
            ll y = 1 + (d1+d3-n+1)/2; 
            ll x = 1 + (d1-y+1); 

            ll d4 = ask(x, y); 
            if(d4==0)
            {
                ans(x, y); 
                return; 
            }
        }
    }

    if(d1+d2>=m-1)
    {
        if((d1+d2-(m-1))%2==0)
        {
            ll x = 1 + (d1+d2-(m-1))/2; 
            ll y = 1 + (d1 - (x-1)); 
            ans(x, y); 
            return; 
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