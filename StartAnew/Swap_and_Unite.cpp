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
    string s; 
    cin >> s; 
    ll n = (int) s.size(); 

    vector<ll> v; 
    ll ans = 1e18; 
    ll mtx[26][n+1]; 

    for(int i=0;i<26; i++)
    {
        for(int j=0;j<n; j++) mtx[i][j] = 0; 
    }

    for(int i=0;i<n; i++)
    {
        mtx[s[i]-'a'][i]++; 
    }

    for(int i=0;i<26; i++)
    {
        for(int j=1;j<n; j++) mtx[i][j] += mtx[i][j-1]; 
    }
    for(char ch = 'a'; ch<='z'; ch++)
    {
        ll ct = count(s.begin(), s.end(), ch);
        // cout << "ct " << ct << endl; 
        if(ct==0) continue;
        else 
        {
            // cout << "ct " << ct << endl;
            ll cnt = 0; 
            for(int i=0;i<n; i++)
            {
                if(i==0) ans = min(ans, ct- mtx[ch-'a'][ct-1]); 
                else if(i+ct-1<n)
                {
                    cnt = ct - (mtx[ch-'a'][i+ct-1] - mtx[ch-'a'][i-1]); 
                    ans = min(ans, cnt); 
                }
            } 
        }
         
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << endl; 
        solve();
    }
    return 0;
}