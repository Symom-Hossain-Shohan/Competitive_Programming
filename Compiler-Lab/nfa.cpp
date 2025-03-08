#include <bits/stdc++.h>
using namespace std;

map<pair<char, char>, string> rules; 


bool nfaAccepts(int pos, string s, char cur, vector<char> endSymbols)
{
    if(pos==s.size())
    {
        for(auto x: endSymbols)
        {
            if(cur == x)
            {
                return true;
            }
        }
        return false;
    }

    if(rules.find({cur, s[pos]}) == rules.end())
    {
        return false;
    }

    bool ok = false; 
    for(auto x: rules[{cur, s[pos]}])
    {
        ok |= nfaAccepts(pos+1, s, x, endSymbols);
    }
    return ok;
}

int main()
{
    char start; 
    cout << "Enter the start symbol: \n";
    cin >> start;
    cout << "Enter the number of end symbols: \n";
    int n;
    cin >> n;
    cout << "Enter the end symbols: \n";
    vector<char> endSymbols;
    for(int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        endSymbols.push_back(x);
    }
    

    cout << "Enter the number of rules: \n";
    int m;
    cin >> m;
    cout << "Enter the rules: \n";
    for(int i = 0; i < m; i++)
    {
        char a, b, c; 
        cin >> a >> b >> c;
        rules[{a, b}].push_back(c);
    }

    cout << "Enter the number of strings: \n";
    int k;
    cin >> k;
    cout << "Enter the strings: \n";
    for(int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        if(nfaAccepts(0, s, start, endSymbols))
        {
            cout << "Accepted\n";
        }
        else
        {
            cout << "Not Accepted\n";
        }
    }
    return 0;
}