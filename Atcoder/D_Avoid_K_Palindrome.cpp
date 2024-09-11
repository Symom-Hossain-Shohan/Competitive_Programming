#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
const ll MX=2e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}
ll n, k; 
string s; 
ll dp[1001][1025]; 

ll get(ll mask)
{
    for(int i=0;i<k/2; i++)
    {
        ll p1 = (mask&(1<<i))>0; 
        ll p2 = (mask&(1<<(k-i-1)))>0       ; 

        if(p1!=p2) return 1; 
    }
    return 0; 
}

ll getMask(ll mask,ll i,ll c){
	if(i<k) return mask+c*(1<<i);
	return (mask>>1)+c*(1<<(k-1));
}

ll func(ll pos, ll mask)
{
    if(pos>=k and get(mask)==0) return 0; 
    if(pos==n) return 1; 

    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask]; 
    }
    ll ans =0 , newmask = mask; 
    if(s[pos]!='?') ans = func(pos+1, getMask(mask, pos, (s[pos]-'A'))); 
    else ans=(ans+func(pos+1,getMask(mask,pos,0))+func(pos+1,getMask(mask,pos,1)))%mod;  

    dp[pos][mask] = ans;

    return dp[pos][mask]; 
}

void solve()
{
    cin >> n >> k; 
    cin >> s; 

    memset(dp, -1, sizeof(dp)); 

    cout << func(0, 0) << endl; 
    
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