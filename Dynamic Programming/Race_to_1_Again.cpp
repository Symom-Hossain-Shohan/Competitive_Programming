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


double divv[MX], ev[MX]; 
void precalculate()
{
    ev[1] = 0, divv[1] = 1; 
    for(int i=2;i<MX; i++)
    {
        ev[i] = (ev[i]+2)/(divv[i]+1); 
        for(int j=i+i; j<MX; j+=i)
        {
            divv[j]++; 
            ev[j] += ev[i] + 1; 
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    cout << fixed << setprecision(10); 
    cout << ev[n] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalculate(); 
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}