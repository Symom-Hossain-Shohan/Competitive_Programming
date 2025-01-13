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

class base 
{
    public: 
    virtual void show()
    {
        cout << "Base class" << endl;
    }
}; 

class derived1: public base 
{
    public: 
    void show()
    {
        cout << "Derived1 class" << endl;
    }
};

class derived2: public base 
{
    public: 
    void show()
    {
        cout << "Derived2 class" << endl;
    }
};

void solve()
{
    base *ptr, b; 
    b.show(); 

    ptr = &b; 
    ptr->show();
    derived1 d1; 
    derived2 d2;
    ptr = &d1;

    ptr->show();

    ptr = &d2;
    ptr->show();
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