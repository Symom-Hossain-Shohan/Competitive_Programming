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
    ll n, m; 
    cin >> n >> m; 
    ll cnt = 0; 
    vector<ll> leading_zero; 
    for(int i=0;i<n; i++)
    {
        string s; 
        cin >> s; 

        cnt += (int)s.size(); 
        ll zero = 0; 
        reverse(s.begin(), s.end()); 

        ll x = 0; 
        while(s[x]=='0')zero++, x++; 

        leading_zero.push_back(zero); 
    }

    sort(leading_zero.rbegin(), leading_zero.rend()); 

    // for(auto i: leading_zero) cout << i << endl; 
    for(int i=0;i<(int)leading_zero.size(); i+=2)
    {
        cnt -= leading_zero[i]; 
    }

    if(cnt>m )cout << "Sasha\n"; 
    else cout << "Anna\n"; 
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