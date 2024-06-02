#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=5e6+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

// vector<unsigned ll> phi(MX+1); 
unsigned long long phi[MX+1]; 

// vector<ll> sum(MX+1); 

void eulerPhi()
{
    // int phi[n+1]; 
    for(ll i=1;i<=MX; i++) phi[i] = i; 
    for(ll i=2;i<=MX; i++)
    {
        if(phi[i] == i)
        {
            phi[i] = i-1; 
            for(ll j=2*i; j<=MX; j+=i)
            {
                phi[j] = (phi[j] * (i-1))/i; 
            }
        }
    }

    // for(int i = 1;i<=n; i++) cout << phi[i] << endl; 
}


void solve()
{
    ll a, b; 
    cin >> a >> b; 

    ll ans = 0; 

    cout << phi[b] - phi[a-1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    // sieve(); 
    eulerPhi();
    for(int i=1;i<=MX; i++) phi[i] = phi[i] * phi[i], phi[i] += phi[i-1]; 
    
    // for(int i=0;i<10;i++) cout << primes[i] << endl; 
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case "<< t << ": "; 
        solve();
    }
    return 0;
}