#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=5e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

int ar[MX]; 
int tree[4*MX+1]; 



int query(int ss, int se, int qs, int qe, int index)
{
    if(ss>=qs and se<=qe)
    {
        return tree[index]; 
    }
    if(qe<ss or qs>se)
    {
        return 0; 
    }

    int mid = (ss+se)/2; 
    int left = query(ss, mid, qs, qe, 2*index); 
    int right = query(mid+1, se, qs, qe, 2*index+1); 

    return max(left, right); 
}

void updateNode(int ss, int se, int i, int increment, int index)
{
    if(i>se or i<ss) 
    {
        return; 
    }

    if(ss==se)
    {
        tree[index] = max(tree[index], increment); 
        return; 
    }

    int mid = (ss+se)/2; 
    updateNode(ss, mid, i, increment, 2*index); 
    updateNode(mid+1, se, i, increment, 2*index+1); 

    tree[index] = max(tree[2*index], tree[2*index+1]); 
}


void updateRange(int ss, int se, int l, int r, int inc, int index)
{
    if(l>se or r<ss)
    {
        return; 
    }
    if(ss==se)
    {
        tree[index] += inc; 
        return; 
    }

    int mid = (ss+se)/2; 
    updateRange(ss, mid, l, r, inc, 2*index); 
    updateRange(mid+1, se, l, r, inc, 2*index+1); 

    tree[index] = max(tree[2*index], tree[2*index+1]); 
    return; 
}

void solve()
{
    int n; 
    cin >> n; 

    vector<int> v(n), mx(n);
    int m = 0;;  
    for(int i=0;i<n; i++) 
    {
        cin >> v[i]; 
        m = max(m, v[i]); 
        mx[i] = m; 
    }

    for(int i=0;i<4*n+1; i++) tree[i] = 0; 
    vector<int> ans(n); 

    for(int i=n-1;i>=0; i--)
    {
        ans[i] = max(mx[i], query(0, n, 0, mx[i]-1, 1)); 
        updateNode(0, n, v[i], ans[i], 1); 
    } 

    for(auto i: ans)  cout << i << ' '; 
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