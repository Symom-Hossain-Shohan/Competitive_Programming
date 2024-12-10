#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 2e5 + 5;
inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication
inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

void calc(ll a, ll b, ll c)
{

    double s = (a + b + c) / 2.0;

    double area = (s * (s - a) * (s - b) * (s - c));

    if ((a + b + c) % 2 == 1)
    {

        ll odd = (a % 2) + (b % 2) + (c % 2);
        if (odd == 3)
        {
            ll ar2 = floor(area), s2 = floor(s * s);
            // cout <<  << endl; 
            // cout << fixed <<  setprecision(8) << area << endl;
            // cout << s * s << endl;
            ll up = 16 * ar2 + 3;
            ll dn = 4 * ((4 * s2) + 1);

            ll gc = __gcd(up, dn);
            up /= gc;
            dn /= gc;
            cout << up << "/" << dn << endl;
        }
        else
        {
            ll ar2 = floor(area), s2 = floor(s * s);
            // cout << area << endl;
            // cout << fixed <<  setprecision(8) << area << endl;

            // cout << s * s << endl;
            ll up = 16 * ar2 + 15;
            ll dn = 4 * ((4 * s2) + 1);

            ll gc = __gcd(up, dn);
            up /= gc;
            dn /= gc;
            cout << up << "/" << dn << endl;
        }
    }
    else
    {
        // cout << "Hi\n";
        // area = ll(area), s = ll(s);
        ll ar = area, ss = s * s;
        // s = s * s;
        ll gcd = __gcd(ar, ss);
        ar /= gcd;
        ss /= gcd;
        cout << ar << "/" << ss << endl;
    }

    return;
}

void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    calc(x, y, z);
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