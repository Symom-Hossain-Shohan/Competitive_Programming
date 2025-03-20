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
    vector<ll> div_n; 
    for(ll i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            div_n.push_back(i);
            if(i*i!=n) div_n.push_back(n/i);
        }
    }

    sort(div_n.begin(), div_n.end());
    // for(auto i: div_n) cout << i << " ";
    // cout << "\n";
    ll ans = -1; 
    for(auto i: div_n)
    {
        string sub = s.substr(0, i);
        string tmp = "";
        for(ll j=0; j<n/i; j++) tmp += sub;
        int mismatch = 0;
        for(ll j=0; j<n; j++)
        {
            if(s[j]!=tmp[j]) mismatch++;
        }
        // cout << i << " " << mismatch << "\n";
        if(mismatch<=1)
        {
            ans = i;
            break;
        }

        sub = s.substr(s.size()-i, i);
        // cout << sub << "\n";
        tmp = "";
        for(ll j=0; j<n/i; j++) tmp += sub;
        mismatch = 0;
        for(ll j=0; j<n; j++)
        {
            if(s[j]!=tmp[j]) mismatch++;
        }

        // cout << i << " " << mismatch << "\n";
        if(mismatch<=1)
        {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
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