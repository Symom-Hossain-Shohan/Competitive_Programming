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

ll n, m; 

string name = "narek"; 
ll memo[1005][5]; 

ll dp(ll i, ll j, vector<string> &vs)
{
    if(i==n)
    {
        return -(2*j); 
    }
    else if(memo[i][j]!=-1) return memo[i][j]; 

    //taking ith position
    ll cnt = 0; 
    ll nextJ = j; 
    for(int it=0;it<m; it++)
    {
        if(vs[i][it]==name[nextJ]) 
        {
            cnt++;
            nextJ = (nextJ+1) % 5; 
        }
        else if(vs[i][it] == 'n' or vs[i][it] == 'a' or vs[i][it] == 'r' or vs[i][it] == 'e' or vs[i][it] == 'k') cnt--; 
    }
    return memo[i][j] = max(cnt+dp(i+1, nextJ, vs), dp(i+1, j, vs)); 
}

void solve()
{
    cin >> n >> m; 
    vector<string> vs; 
    for(int i=0;i<n; i++)
    {
        string s; 
        cin >> s; 
        vs.push_back(s); 
    }

    for(int i=0; i<=n+2; i++) 
    {
        for(int j=0;j<5; j++) memo[i][j] = -1; 
    }

    cout << dp(0, 0, vs) << endl; 
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