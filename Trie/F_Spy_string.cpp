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

ll dif(string a, string b)
{
    ll n = a.size(); 
    ll cnt = 0; 
    for(int i=0;i<n; i++) cnt += (a[i]!=b[i]); 

    return cnt; 
}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<string> vs; 
    for(int i=0;i<n; i++)
    {
        string s; 
        cin >> s; 
        vs.push_back(s); 
    }

    string ans = vs[0]; 

    for(int i=0;i<ans.size(); i++)
    {
        for(char c = 'a'; c<='z'; c++)
        {
            ans[i] = c; 
            bool ok = true; 
            for(int j=0;j<n; j++)
            {
                if(dif(vs[j], ans)<2) continue;
                else ok = false; 
            }

            if(ok) 
            {
                cout << ans << endl; 
                return; 
            }
        }
        
        ans = vs[0]; 

    }
    cout << -1 << endl; 
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