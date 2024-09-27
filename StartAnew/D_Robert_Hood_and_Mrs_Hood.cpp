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
    ll n, d, k; 
    cin >>  n >> d >> k; 


    vector<pair<ll,ll>> jobs; 
    for(int i=0;i<k; i++)
    {
        ll a, b; 
        cin >> a >> b; 
        jobs.push_back({a, b}); 
    }
    


    sort(jobs.begin(), jobs.end()); 
    // cout << "Hello\n"; 

    priority_queue<ll, vector<ll>, greater<int>> pq; 
    vector<ll> cnt(n+1); 
    int j=0; 
    ll mx = -1, mn = 1e9; 
    ll b = -1, m = -1; 
    for(int i=1;i<=n; i++)
    {
        // ll r = i+d-1; 
        // while(pq.top()<i and !pq.empty()) pq.pop();
        // while(jobs[j].first<=r) pq.push(jobs[j].second), j++; 
        // cnt[i] = pq.size(); 
        ll r = i+d-1; 
        while(!pq.empty())
        {
            if(pq.top()<i) pq.pop(); 
            else break;
        }
        while(j<k)
        {
            if(jobs[j].first<=r)
            {
                pq.push(jobs[j].second); 
                j++; 
            }
            else break;
        }

        cnt[i] = pq.size(); 

    }
    

    for(int i=1;i<=n-d+1; i++)
    {
        if(cnt[i]<mn)
        {
            mn = cnt[i]; 
            b = i; 
        }
        if(cnt[i]>mx)
        {
            mx = cnt[i]; 
            m = i; 
        }
    } 

    cout << m << ' ' << b << endl; 
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