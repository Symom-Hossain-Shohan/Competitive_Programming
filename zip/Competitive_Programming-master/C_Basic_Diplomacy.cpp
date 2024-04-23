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

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

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
    cin >> tc;
    while(tc--)
    {
        ll n,m;
        cin >> n >> m;
        vector<ll> adj[m],ans(m);

        for(ll i=0;i<m;i++)
        {
            ll x;
            cin >> x;
            while(x--)
            {
                ll a;
                cin >> a;
                adj[i].pb(a);
            }
        }

        map<ll,ll> mp,np;

        for(ll i=0;i<m;i++)
        {
            ans[i]=adj[i][0];
            mp[adj[i][0]]++;
            //if(adj[i].size()==1) np[adj[i][0]]++;
        }

    

    
        
            ll point;
            for(ll i=1;i<=n;i++)
            {
                if(mp[i]>(m+1)/2)
                {
                    point=i;
                    break;
                }
            }

            ll x=mp[point]-(m+1)/2;
            for(ll i=0;i<m and x;i++)
            {
                if(adj[i][0]==point and adj[i].size()>1)
                {
                    
                    for(ll j=1;j<(int)adj[i].size();j++)
                    {
                        if(mp[adj[i][j]]<(m+1)/2)
                        {
                            mp[adj[i][j]]++;
                            x--;
                            ans[i]=mp[adj[i][j]];
                            break;
                        }
                    }
                }
            }

            bool ok=true;

            for(auto i: ans) 
            {
                np[i]++;
                if(np[i]>(m+1)/2) ok=false;
       
            }

            if(ok) 
            {
                cout << "YES\n";
                for(auto i: ans) cout << i << ' ';
                cout<< endl;
            }
            else cout << "NO\n";
        
    }
    
    //---------------------------------
    
    return 0;
}