#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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




// #include <ext/pb_ds/assoc_container.hpp> // Common
void solve()
{
    ll n, q; 
    cin >> n >> q; 
    vector<ll> v(n), query(q); 

    for(auto &i: v) cin >> i; 

    vector<ll> ans(n+1, 0); 
    for(auto &i: query)
    {
        cin >> i; 
    }

    multiset<ll> vals, mins; 

    ans[0] = v[0]; 
    vals.insert(v[0]); 

    ll sum = 0; 
    sum += v[0]; 

    for(int i=1;i<n; i++)
    {
        vals.insert(v[i]); 
        sum += v[i]; 

        if(i%2==0)
        {
            sum -= 2 * (*vals.begin());
            mins.insert(*vals.begin());
            vals.erase(vals.find(*vals.begin()));
            ans[i] = sum;
        }
        else 
        {
            while(mins.size() && *vals.begin() < *mins.rend())
            {
                sum -= 2 * (*vals.begin()); 
                sum += 2 * (*mins.rend()); 

                int x = *vals.begin(), y = *mins.rbegin();
                vals.insert(y); mins.insert(x);
                vals.erase(vals.find(x));
                mins.erase(mins.find(y));

            }
        }
    }
    
    
    for(auto i: query) cout << ans[i-1] << ' '; 
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