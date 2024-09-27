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
    vector<double> v(n); 

    for(auto &i: v) cin >> i; 

    sort(v.begin(), v.end()); 
    double sum = 0; 
    for(auto i: v) sum += i; 
    ll l = 0, r = 1e18, x = -1; 
    while(l<=r)
    {
        ll mid = (l+r)/2; 
        double avg = (sum+mid)/(2.0*n); 
        ll cnt = 0; 
        for(int i=0;i<n-1; i++)
        {
            if(v[i]<avg) cnt++; 
        }
        if(n%2==1)
        {
            if(cnt>=(n+1)/2) 
            {
                x = mid; 
                r = mid-1; 
            }
            else l = mid+1; 
        }
        else 
        {
            if(cnt>(n/2))
            {
                x = mid; 
                r = mid-1; 
            }
            else l = mid+1; 
        }
    }

    cout << x << endl; 
    
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