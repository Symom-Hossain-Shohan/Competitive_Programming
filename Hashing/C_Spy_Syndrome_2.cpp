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

pair<ll,ll> compute_hash(string s) {

    reverse(s.begin(), s.end()); 

    for(int i=0;i<(int)s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    int p = 139;
    int m = 1e9 + 7;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    p = 127, p_pow = 1;
    ll hash_val = 0; 

    for (char c : s) {
        hash_val = (hash_val + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return {hash_value, hash_val};
}

void solve()
{
    ll n; 
    cin >> n; 
    string  s; 
    cin >> s; 
    
    ll mm; 
    cin >> mm; 
    map<pair<ll,ll>,string> mp;

    while(mm--)
    {
        string tmp; 
        cin >> tmp; 

        pair<ll,ll> hash = compute_hash(tmp); 
        mp[hash] = tmp; 
    }

    ll p = 139, m = 1e9+7, hash_value = 0, p_pow = 1; 
    ll p1 = 127, hash_val = 0, p_pow2 = 1; 
    for(int i=0;i<n; i++)
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        hash_val = (hash_val + (s[i]-'a'+1)*p_pow2) % m; 
        p_pow = (p_pow * p1) % m;
        if(mp.count({hash_value, hash_val})>0)
        {
            cout << mp[{hash_value, hash_val}] << ' '; 
            hash_value = 0, p_pow = 1; 
            hash_val = 0, p_pow2 = 1; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}