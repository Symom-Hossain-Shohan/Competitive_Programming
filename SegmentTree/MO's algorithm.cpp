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

struct query
{
    int l, r, i; 
};

query Q[MX]; 
int BLOCK = 555;

int ar[MX], ans[MX]; 
int freq[MX], cnt = 0; 

bool cmp(query a, query b)
{
    if(a.l/BLOCK != b.l/BLOCK)
        return a.l/BLOCK <= b.l/BLOCK;
    else return a.r < b.r;  
}

void add(int pos)
{
    pos = ar[pos]; 
    freq[pos]++; 
    if(freq[pos]==1) cnt++; 
}

void remove(int pos)
{
    pos = ar[pos]; 
    freq[pos]--; 
    if(freq[pos]==0) cnt--; 
}


void solve()
{
    ll n, q; 
    cin >> n >> q; 
    for(int i=0;i<n; i++) cin >> ar[i]; 

    for(int i=0;i<q; i++)
    {
        ll l, r; 
        cin >> l >> r; 
        l--, r--; 
        Q[i].l = l, Q[i].r = r, Q[i].i = i; 
    }

    sort(Q, Q+q, cmp); 

    ll ML = 0, MR = -1; 

    for(int i=0; i<q; i++)
    {
        int L = Q[i].l; 
        int R = Q[i].r; 

        while(ML>L) 
        {
            ML--, add(ML); 
        }

        while(MR<R)
        {
            MR++; 
            add(MR); 
        }

        while (ML<L)
        {
            ML++; 
            remove(ML); 
        }

        while (MR>R)
        {
            MR--, remove(MR); 
        }
        
        ans[Q[i].i] =cnt; 
        
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