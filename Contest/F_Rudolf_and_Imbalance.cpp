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
    ll n, m, k; 
    cin >> n >> m >> k; 

    vector<ll> a(n), b(m), c(k); 

    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    for(auto &i: c) cin >> i; 

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 
    sort(c.begin(), c.end()); 

    vector<ll> dif; 
    for(int i = 1;i<n; i++) dif.push_back(a[i]-a[i-1]); 

    sort(dif.begin(), dif.end()); 

    ll maxDif = dif.back(); 
    dif.pop_back();

    ll l = 0, r = 0; 
    for(int i=1;i<n; i++) if(a[i]-a[i-1]==maxDif) l = i-1, r = i; 

    ll minDif = maxDif; 

    for(int i=0;i<m; i++)
    {
        //calculating left bound such that b[i] + c[j] >= l and <=r

        ll x = b[i]; 
        ll left = 0, right = k-1; 
        ll leftBound = -1; 
        while(left<=right)
        {
            ll mid = (left+right)/2; 

            if(c[mid]+x >= a[l])
            {
                leftBound = mid; 
                right = mid-1; 
            }
            else left = mid+1; 

        }

        left = 0, right = k-1; 
        ll rightBound = -1; 

        while(left<=right)
        {
            ll mid = (left+right)/2; 
            if(c[mid]+x<=a[r])
            {
                rightBound = mid; 
                left = mid+1; 
            }
            else right = mid-1;
        }
        // cout << x  << endl; 

        // cout << leftBound << ' ' << rightBound << endl; 

        if(leftBound<=rightBound and leftBound!=-1 and rightBound!=-1)
        {
            left = leftBound, right = rightBound; 

            while(left<=right)
            {
                ll mid = (left+right)/2; 
                ll val = c[mid] + x; 
                // cout << "Val " <<  val << endl; 
                // cout << a[l] << ' ' << a[r] << endl; 
                minDif = min(minDif, max(val-a[l], a[r]-val)); 
                if(val-a[l]<=a[r]-val)
                {
                    minDif = min(minDif, max(val-a[l], a[r]-val)); 
                    left = mid + 1; 
                    // cout << mid << endl; 
                }
                else right = mid - 1; 
            }
        }
    }
 
    if(n>2)
    cout << max(dif.back(), minDif) << endl; 
    else cout << minDif<< endl; 
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