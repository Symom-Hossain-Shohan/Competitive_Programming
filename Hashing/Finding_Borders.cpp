#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2e5+5;
const int p = 31; 
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

void solve()
{
    string s; 
    cin >> s; 

    ll n = s.size();

    vector<ll> hash(n+1); 

    ll hash_value = 0;
    ll p_pow = 1;
    for (int i=0;i<n; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;

        hash[i] = hash_value; 
    }

    vector<ll> power(n+1); 
    power[0] = 1; 

    for(int i=1;i<n; i++)
    {
        power[i] = modMul(power[i-1], p); 
    }

    for(int i=0, j=n-1; i<n-1; i++, j--)
    {
        ll val1 = hash[i], val2 = (hash[n-1] - hash[j-1]);
        val2 = modDiv(val2, power[j]); 
        // cout << i << ' ' << val1 << ' ' << val2 << endl; 

        if(val1==val2) cout << i+1 << ' '; 
    }
    


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