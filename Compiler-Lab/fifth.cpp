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

vector<vector<string>> solve(vector<string> vString)
{
    vector<vector<string>> ans;

    int fst = 0, sec = 0;
    for (auto i : vString)
    {
        if (i == "*" or i == "/" or i == "%")
            fst++;
        else if (i == "+" or i == "-")
            sec++;
    }

    while (fst--)
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
                ans.push_back(vString);
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
                ans.push_back(vString);
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
                ans.push_back(vString);
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
                ans.push_back(vString);
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
                ans.push_back(vString);
                break;
            }
        }
    }

    return ans; 
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    int first = 0, sec = 0, third = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*' or s[i] == '/' or s[i] == '%')
            first++;
        else if (s[i] == '+' or s[i] == '-')
            sec++;
        else if (s[i] == '(')
            third++;
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

    while (third--)
    {
        int lastOpen = -1;
        for (int i = 0; i < vString.size(); i++)
        {
            if (vString[i] == "(")
                lastOpen = i;
        }

        if (lastOpen == -1)
            break;

        int lastClose = -1;
        for (int i = lastOpen; i < vString.size(); i++)
        {
            if (vString[i] == ")")
            {
                lastClose = i;
                break;
            }
        }

        vector<string> tmp;
        for (int i = lastOpen + 1; i < lastClose; i++)
        {
            tmp.push_back(vString[i]);
        }

        vector<vector<string>> res = solve(tmp);
        reverse(res.begin(), res.end());    
        for(int i=0;i<res.size()-1;i++)
        {
            for(int j=0;j<lastOpen; j++)
            {
                cout << vString[j];
            }
            // cout << res[i] ; 
            cout << res.back(); 
        }
    }
}