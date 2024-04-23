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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second!=b.second) return a.second<b.second; 
    return a.first< b.first; 
}

void solve()
{
    ll n, m;
    cin >> n >> m; 
    vector<pair<ll,ll>> vp; 
    for(int i=0;i<n; i++)
    {
        ll l, r; 
        cin >> l >> r; 
        vp.push_back({l, r}); 
    }

    sort(vp.begin(), vp.end()); 

    map<int, int> en; 
    int ongoing = 0; 
    int ans = 0; 
    set<int> cl; 

    for(int i=0;i<n; i++)
    {
        if(vp[i].first==1) continue;

        while(cl.size() && *cl.begin()<=vp[i].first)
        {
            ongoing -= en[*cl.begin()]; 
            cl.erase(cl.begin()); 
        }

        ongoing++; 
        en[vp[i].second+1]++; 
        cl.insert(vp[i].second+1); 
        ans = max(ans, ongoing); 
    }

    cl.clear(), ongoing = 0, en.clear(); 

    sort(vp.begin(), vp.end(), cmp); 

    for(int i =n-1;i>=0; i--)
    {
        if(vp[i].second==m) continue;

        while(cl.size() and *cl.rbegin()>=vp[i].second)
        {
            ongoing -= en[*cl.rbegin()]; 
            cl.erase(--cl.end()); 
        }

        ongoing++ ;
        en[vp[i].first-1]++; 
        cl.insert(vp[i].first-1); 
        ans = max(ans, ongoing); 
    }
    cout << ans << "\n"; 
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