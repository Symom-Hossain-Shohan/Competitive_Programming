#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+9;
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
    string s; 
    while(cin >> s)
    {
        string rs = s; 
        reverse(rs.begin(), rs.end()); 

        if(rs == s) cout << s << "\n";
        else 
        {
            const int p = 127;
            const int m = 1e9 + 9;
            long long hash_value = 0;
            long long p_pow = 1;
            unordered_map<ll,ll> mp; 
            ll n = s.size(); 
            for (int i = 0;i<n ;i++) {
                hash_value = (hash_value + (rs[i] - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;

                mp[hash_value]++; 
            }
            hash_value = 0;
            p_pow = 1;
            vector<ll> hash(n+1); 
            for (int i = 0;i<n ;i++) {
                hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;

                // mp[hash_value]++; 
                hash[i] = hash_value; 
            }

            
            vector<ll> power(n+1); 
            power[0] = 1; 
            for(int i=1;i<n; i++)
            {
                power[i] = modMul(power[i-1], p); 
            }

            for(int i=1;i<n; i++)
            {
                ll h1 = hash[n-1] - hash[i-1]; 
                h1 = modDiv(h1, power[i]); 

                if(mp[h1])
                {
                    for(int j=i-1;j>=0; j--) 
                    {
                        s.push_back(s[j]); 
                    }
                    break;
                }
            }

            cout << s << endl; 

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