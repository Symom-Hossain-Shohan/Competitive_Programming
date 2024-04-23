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
ll prop[4*MX+1];  


void buildTree(int s, int e, int index)
{
    if(s==e)
    {
        tree[index] = ar[s]; 
        return; 
    }

    int mid = (s+e)/2; 
    buildTree(s, mid, 2*index); 
    buildTree(mid+1, e, 2*index+1); 

    tree[index]= min(tree[2*index], tree[2*index+1]); 
    return; 
}

void updateRangeLazy(int ss, int se, int l, int r, int inc, int index)
{
    if(prop[index])
    {
        tree[index] += prop[index]; 

        if(ss!=se)
        {
            prop[2*index] += prop[index]; 
            prop[2*index+1] += prop[index]; 
        }
        prop[index] = 0; 
    }

    if(ss>r or l>se)
    {
        return; 
    }

    if(ss>=l and se<=r)
    {
        tree[index] += inc; 
        if(ss!=se)
        {
            prop[2*index] += inc; 
            prop[2*index+1] += inc; 
        }
        return; 
    }

    int mid = (ss+se)/2; 
    updateRangeLazy(ss, mid, l, r, inc, 2*index); 
    updateRangeLazy(mid+1, se, l, r, inc, 2*index+1);

    tree[index] = min(tree[2*index], tree[2*index+1]); 
    return; 
}

int queryLazy(int ss, int se, int qs, int qe, int index)
{
    if(prop[index])
    {
        tree[index] += prop[index]; 

        if(ss!=se)
        {
            prop[2*index] += prop[index]; 
            prop[2*index+1] += prop[index]; 
        }
        prop[index] = 0; 
    }

    if(ss>qe or se<qs)
    {
        return INT_MAX; 
    }

    if(ss>=qs and se<=qe)
    {
        return tree[index]; 
    }

    int mid = (ss+se)/2; 
    int left = queryLazy(ss, mid, qs, qe, 2*index); 
    int right = queryLazy(mid+1, se, qs, qe, 2*index+1); 

    return min(left, right); 
}

void solve()
{
     
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}