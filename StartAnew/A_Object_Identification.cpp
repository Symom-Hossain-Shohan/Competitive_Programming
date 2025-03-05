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


void query(ll a, ll b)
{
    cout << "? " << a << " " << b << endl;
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i : v) cin >> i;
    map<ll,ll> mp;
    for(int i=0;i<n; i++) mp[v[i]] = i+1; 
    if(mp.size() == n)
    {
        query(mp[1], mp[n]);
        ll rep;
        cin >> rep;
        if(rep <n-1)
        {
            cout << "! " << 'A' << endl;
        }
        else if(rep>n-1)
        {
            cout << "! " << 'B' << endl;
        }
        else 
        {
            query(mp[n], mp[1]);
            ll rep;
            cin >> rep;
            if(rep == n-1)
            {
                cout << "! " << 'B' << endl;
            }
            else
            {
                cout << "! " << 'A' << endl;
            }
        }
    }
    else 
    {
        for(int i=1;i<=n; i++)
        {
            if(mp[i]==0)
            {
                ll x = i+1; 
                if(x==n+1) x = 1;

                query(i, x);
                ll rep; 
                cin >> rep; 
                if(rep == 0)
                {
                    cout << "! " << 'A' << endl;
                }
                else 
                {
                    cout << "! " << 'B' << endl;
                }
                return; 
            }
        }
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