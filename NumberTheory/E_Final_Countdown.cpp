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
    string s; 
    cin >> s; 

    vector<ll> prefix(n+1, 0); 
    for(int i=0;i<n; i++)
    {
        prefix[i+1] = s[i] - '0'; 
        // prefix[i+1] += prefix[i]; 
    }
    for(int i=1;i<=n; i++) prefix[i] += prefix[i-1]; 

    for(int i=n; i>=2; i--)
    {
        prefix[i-1] += prefix[i] /10; 
        prefix[i] = prefix[i] % 10; 
    }

    int flag = 0; 
    for(int i=1;i<=n; i++)
    {
        if(prefix[i]==0 and flag==0) continue;
        else 
        {
            cout << prefix[i]; 
            flag = 1; 
        }
    }
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