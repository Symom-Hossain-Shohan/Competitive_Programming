#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod=1e9+7;
const ll MX=2e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



void solve()
{
    string s; 
    cin >> s; 
    
    string bad; 
    cin >> bad; 

    ll k; 
    cin >> k; 

    ll ans = 0; 
    ll n = s.length(); 
    ll prefix[n][26]; 


    vector<ll> hash(n+1), hash2(n+1);
    ll p = 31;  
    ll p2 = 127; 

    ll hash_value = 0;
    ll hash_value2 = 0; 
    ll p_pow = 1;
    ll p_pow2 = 1; 
    ll mod2 = 1e9 + 9; 
    for (int i=0;i<n; i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;

        hash[i] = hash_value; 

        hash_value2 = (hash_value2 + (s[i]-'a'+1)*p_pow2) % mod2; 
        p_pow2 = (p_pow2 * p2) % mod2; 

        hash2[i] = hash_value2; 
    }

    vector<ll> power(n+1), power2(n+1); 
    power[0] = 1; 
    power2[0] = 1; 

    for(int i=1;i<n; i++)
    {
        power[i] = modMul(power[i-1], p); 
        power2[i]= (power2[i-1]*p2) %  1000000009;
    }


    for(int i=0;i<n; i++)
    {
        for(int j=0;j<26; j++) prefix[i][j] = 0; 
    }

    for(int i=0;i<n; i++)
    {
        prefix[i][s[i]-'a']++; 
    }

    for(int i = 1; i<n; i++)
    {
        for(int j=0;j <26; j++) 
        {
            prefix[i][j] += prefix[i-1][j]; 
        }
    }

    // u<pair<ll,ll>> st; 
    unordered_map<ll,ll> st; 

    for(int i=0;i<n; i++)
    {
        string tmp; 
        for(int j=i; j<n; j++)
        {
            bool ok = true; 
            tmp.push_back(s[j]); 
            ll cnt = 0; 

            for(int jj=0;jj<26; jj++)
            {
                if(bad[jj]=='0')
                {
                    cnt += prefix[j][jj]; 
                    if(i>0) cnt -= prefix[i-1][jj]; 

                    // cout << i << ' ' << j << ' ' << jj << ' ' << cnt << endl; 
                }
            }
            if(cnt>k) 
            {
                ok = false; 
                // continue;
                break;
            }
            if(ok) 
            {
                ll _hash = hash[j];
                ll _hash2 = hash2[j]; 
                if(i!=0) 
                {
                    _hash -= hash[i-1]; 
                    mod = 1e9 + 7; 
                    _hash = modDiv(_hash, power[i]); 

                    _hash2 -= hash2[i-1];
                    mod = 1e9 + 9; 
                    _hash2 = modDiv(_hash2, power2[i]); 
                    mod = 1e9 + 7; 
                }

                // st.insert({_hash, _hash2}); 
                ll hv = (_hash<<31)+ _hash2; 

                st[hv]++; 
                 
            } 
        }
    }

    cout << st.size() << endl; 
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