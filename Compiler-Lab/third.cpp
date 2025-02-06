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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    int first = 0, sec = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*' or s[i] == '/' or s[i] == '%')
            first++;
        else if (s[i] == '+' or s[i] == '-')
            sec++;
    }

    cout << s << endl;

    while (first--)
    {
        string newS;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                int res = (s[i - 1] - '0') * (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                cout << newS << endl;
                s = newS;
                break;
            }
            else if (s[i] == '/')
            {
                int res = (s[i - 1] - '0') / (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
            else if (s[i] == '%')
            {
                int res = (s[i - 1] - '0') % (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
        }
    }

    // cout << sec << endl;

    while (sec--)
    {
        string newS;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
            {
                int res = (s[i - 1] - '0') + (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
            else if (s[i] == '-')
            {
                int res = (s[i - 1] - '0') - (s[i + 1] - '0');
                s[i] = res + '0';
                s[i - 1] = 'x';
                s[i + 1] = 'x';
                for (auto j : s)
                {
                    if (j == 'x')
                        continue;
                    // cout << j;
                    newS.push_back(j);
                }
                // cout << endl;
                cout << newS << endl;
                s = newS;
                break;
            }
        }
    }
}