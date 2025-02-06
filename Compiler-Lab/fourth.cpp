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

    // cout << s << endl;

    vector<string> vString;
    int dig = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            dig = dig * 10 + (s[i] - '0');
        }
        else
        {
            if (dig)
            {
                vString.push_back(to_string(dig));
                dig = 0;
            }
            string tmp = "";
            tmp += s[i];
            vString.push_back(tmp);
        }
    }

    if (dig)
    {
        vString.push_back(to_string(dig));
    }

    for (auto x : vString)
    {
        cout << x;
    }
    cout << endl;

    while (first--)
    {
        vector<string> newS;
        for (int i = 0; i < vString.size(); i++)
        {
            if (vString[i] == "*")
            {
                int a = stoi(vString[i - 1]);
                int b = stoi(vString[i + 1]);
                int res = a * b;
                for (int j = 0; j < i - 1; j++)
                {
                    newS.push_back(vString[j]);
                }
                newS.push_back(to_string(res));
                for (int j = i + 2; j < vString.size(); j++)
                {
                    newS.push_back(vString[j]);
                }
                vString = newS;
                for (auto i : vString)
                {
                    cout << i;
                }
                cout << endl;
                break;
            }
            else if (vString[i] == "/")
            {
                int a = stoi(vString[i - 1]);
                int b = stoi(vString[i + 1]);
                int res = a / b;
                for (int j = 0; j < i - 1; j++)
                {
                    newS.push_back(vString[j]);
                }
                newS.push_back(to_string(res));
                for (int j = i + 2; j < vString.size(); j++)
                {
                    newS.push_back(vString[j]);
                }
                vString = newS;
                for (auto i : vString)
                {
                    cout << i;
                }
                cout << endl;
                break;
            }
            else if (vString[i] == "%")
            {
                int a = stoi(vString[i - 1]);
                int b = stoi(vString[i + 1]);
                int res = a % b;
                for (int j = 0; j < i - 1; j++)
                {
                    newS.push_back(vString[j]);
                }
                newS.push_back(to_string(res));
                for (int j = i + 2; j < vString.size(); j++)
                {
                    newS.push_back(vString[j]);
                }
                vString = newS;
                for (auto i : vString)
                {
                    cout << i;
                }
                cout << endl;
                break;
            }
        }
    }

    while (sec--)
    {
        vector<string> newS;
        for (int i = 0; i < vString.size(); i++)
        {
            if (vString[i] == "+")
            {
                int a = stoi(vString[i - 1]);
                int b = stoi(vString[i + 1]);
                int res = a + b;
                for (int j = 0; j < i - 1; j++)
                {
                    newS.push_back(vString[j]);
                }
                newS.push_back(to_string(res));
                for (int j = i + 2; j < vString.size(); j++)
                {
                    newS.push_back(vString[j]);
                }
                vString = newS;
                for (auto i : vString)
                {
                    cout << i;
                }
                cout << endl;
                break;
            }
            else if (vString[i] == "-")
            {
                int a = stoi(vString[i - 1]);
                int b = stoi(vString[i + 1]);
                int res = a - b;
                for (int j = 0; j < i - 1; j++)
                {
                    newS.push_back(vString[j]);
                }
                newS.push_back(to_string(res));
                for (int j = i + 2; j < vString.size(); j++)
                {
                    newS.push_back(vString[j]);
                }
                vString = newS;
                for (auto i : vString)
                {
                    cout << i;
                }
                cout << endl;
                break;
            }
        }
    }
}