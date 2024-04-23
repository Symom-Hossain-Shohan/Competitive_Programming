#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb           push_back
#define mp           make_pair
#define in           insert
#define pi           2*acos(0.0)
#define srt(s)       sort(s.begin(),s.end())
#define rsrt(s)      sort(s.rbegin(),s.rend())
#define all(x)       x.begin(),x.end()
#define mem(a, b)    memset(a, b, sizeof(a))
#define c_test       printf("Case %lld: ",t)

const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

//code goes from here...



int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll tc;
    cin>> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n),suf(n),pref(n);
        for(ll i=0;i<n;i++) cin >> v[i];
        pref[0]=0^v[0];
        suf[n-1]=0^v[n-1];

        for(ll i=1;i<n;i++) pref[i]=pref[i-1]^v[i];
        for(ll i=n-2;i>=0;i--) suf[i]=suf[i+1]^v[i];
        bool ok=false;
        for(ll i=0;i<n-1;i++)
        {
            if(pref[i]==suf[i+1]) ok=true;
        }

        for(ll i=0;i<n;i++)
        {
            for(ll j=i+2;j<n;j++)
            {
                ll p1=pref[i];
                ll p2=pref[i]^pref[j-1];
                ll p3=suf[j];
                if(p1==p2 and p2==p3) ok=true;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
    //---------------------------------
    
    return 0;
}