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


ll partition(vector<ll> &v, ll st, ll end)
{
    ll idx = st-1, pivot = v[end]; 
    for(int j=st;j<end; j++)
    {
        if(v[j]<pivot)
        {
            idx++; 
            swap(v[j], v[idx]); 
        }
    }
    idx++; 
    swap(v[idx], v[end]); 
    return idx; 
}

void quickSort(vector<ll> &v, ll st, ll end)
{
    if(st<end)
    {
        ll pivIndx = partition(v, st, end); 
        quickSort(v, st, pivIndx-1); 
        quickSort(v, pivIndx+1, end); 
    }
}

void solve()
{
    vector<ll> v = {4, 2, 5, 1, 3}; 
    quickSort(v, 0, v.size()-1); 
    for(auto i: v) cout << i << endl; 
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