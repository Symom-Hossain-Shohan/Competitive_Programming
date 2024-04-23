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

ll ar[MX]; 
ll tree[4*MX+1]; 

void buildTree(int s, int e, int index, int lvl)
{
    if(s==e)
    {
        tree[index] = ar[s]; 
        return; 
    }

    int mid = (s+e)/2; 
    buildTree(s, mid, 2*index, lvl-1); 
    buildTree(mid+1, e, 2*index+1, lvl-1); 

    if(lvl%2)
    {
        tree[index] = tree[2*index] | tree[2*index+1]; 
    }
    else 
    {
        tree[index] = tree[2*index] ^ tree[2*index+1]; 
    }

}

void updateNode(int ss, int se, int i, int increment, int index, int lvl)
{
    if(i>se or i<ss) 
    {
        return; 
    }

    if(ss==se)
    {
        tree[index] = increment; 
        return; 
    }

    int mid = (ss+se)/2; 
    updateNode(ss, mid, i, increment, 2*index, lvl-1); 
    updateNode(mid+1, se, i, increment, 2*index+1, lvl-1); 

    if(lvl%2)
    {
        tree[index] = tree[2*index] | tree[2*index+1]; 
    }
    else 
    {
        tree[index] = tree[2*index] ^ tree[2*index+1]; 
    }
}

void solve()
{
    ll x, q; 
    cin >> x >> q; 
    ll n = pow(2, x); 
    for(int i=0;i<n; i++)
    {
        cin >> ar[i]; 
    }
    // for(int i=0;i<n; i++) cout << ar[i] << ' '; 
    // cout << endl; 

    buildTree(0, n-1, 1, x); 
    while(q--)
    {
        ll p, b; 
        cin >> p >> b; 
        p--; 
        // for(int i=1;i<=7; i++) cout << tree[i] << ' '; 
        // cout << endl; 
        updateNode(0, n-1, p, b, 1, x); 
        cout << tree[1] << endl; 
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