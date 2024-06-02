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
    ll n;  
    cin >> n; 
    vector<ll> v(n);
    ll pos = -1;  
    for(int i=0;i<n; i++)
    {
        cin >> v[i]; 

        if(v[i]==n) pos = i; 
    }

    if(pos%2==0)
    {
        vector<ll> a, b; 
        for(int i=0;i<n; i++)
        {
            if(i%2==0) a.push_back(v[i]); 
            else b.push_back(v[i]); 
        }

        sort(a.begin(), a.end()); 
        sort(b.rbegin(), b.rend());

        // for(auto i: a) cout << i << ' '; 
        // cout << endl;  
        // if(pos==0) 
        // {
        //     a.push_back(n); 
        //     reverse(a.begin(), a.end()); 
        //     a.pop_back(); 
        //     reverse(a.begin(), a.end()); 

        // }
        map<ll,ll> mp; 

        for(int i=0, j=n;i<n/2; i++, j--)
        {
            mp[a[i]] = j; 
        } 
        for(int i=0, j=1;i<n/2; i++, j++)
        {
            mp[b[i]] = j; 
        }

        for(int i=0;i<n; i++) cout << mp[v[i]] << ' '; 
        cout << endl; 
    }
    else 
    {
        vector<ll> a, b; 
        for(int i=0;i<n; i++)
        {
            if(i%2==1) a.push_back(v[i]); 
            else b.push_back(v[i]); 
        }

        sort(a.begin(), a.end()); 
        sort(b.rbegin(), b.rend());

        // if(pos==n-1)
        // {
        //     a.push_back(n); 
        //     reverse(a.begin(), a.end()); 
        //     a.pop_back(); 
        //     reverse(a.begin(), a.end()); 
        // }
        map<ll,ll> mp; 

        for(int i=0, j=n;i<n/2; i++, j--)
        {
            mp[a[i]] = j; 
        } 
        for(int i=0, j=1;i<n/2; i++, j++)
        {
            mp[b[i]] = j; 
        }

        for(int i=0;i<n; i++) cout << mp[v[i]] << ' '; 
        cout << endl;

    }


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