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
    ll n, m, k, d; 
    cin >> n >> m >> k >> d; 
    vector<ll> a(m+2), b(n+2); 
    b[0] = 0; 
    for(int i=1;i<=n; i++)
    {
        ll cur = 0; 
        multiset<ll> st; 
        for(int j=1;j<=m; j++)
        {
            cin >> a[j]; 
            a[j]++; 
            if(j==1) cur = a[j]; 
            else 
            {
                cur = a[j] + *st.begin(); 
            }
            st.insert(cur); 

            if(j-d-1>=1) st.erase(st.find(a[j-d-1])); 

            a[j] = cur; 
        }

        b[i] = cur; 
    }

    for(int i=1;i<=n; i++) b[i] += b[i-1]; 
    ll ans = b[k]; 
    for(int i=k+1; i<=n; i++)
    {
        ans = min(ans, b[i] - b[i-k]); 
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
        solve();
    }
    return 0;
}