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
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    stack<ll> st; 
    vector<ll> ans(n); 
    for(int i=0;i<n; i++)
    {
        if(i==0)
        {
            ans[i] = v[i]; 
            st.push(i); 
            cout << ans[i]+1 << ' '; 
            continue;
        }

        while(!st.empty() and v[st.top()]<=v[i])
            st.pop(); 
        if(!st.empty() and v[i]<v[st.top()])
        {
            ans[i] = ans[st.top()] + (i-st.top())*v[i] ;
        }
        else 
        {
            ans[i] = (i+1)*v[i]; 
        }

        st.push(i); 
        cout << ans[i]+1 << ' '; 
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