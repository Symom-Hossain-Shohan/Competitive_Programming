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


class BaseClass 
{
    private:
        int a;
    public: 
        BaseClass()
        {
            cout << "No argument constructor of BaseClass" << endl;
        }

        BaseClass(int x)
        {
            a = x;
            cout << "One argument constructor of BaseClass" << endl;
        }
};

class DerivedClass : public BaseClass 
{
    private:
        int b;
    public: 
        DerivedClass()
        {
            cout << "No argument constructor of DerivedClass" << endl;
        }

        DerivedClass(int x) : BaseClass(x)
        {
            // b = x;
            // cout << "One argument constructor of DerivedClass" << endl;
            cout << "Only base class is initialized" << endl;   
        }

        DerivedClass(int x, int y) : BaseClass(x)
        {
            b = y;
            cout << "Two argument constructor of DerivedClass" << endl;
        }
};

void solve()
{
    DerivedClass o1, o2(10), o3(10, 20);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}