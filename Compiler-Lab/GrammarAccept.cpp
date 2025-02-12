#include <bits/stdc++.h>
using namespace std;

map<char, vector<string>> productionRules;

bool isAccepted(string chk, string grammar)
{
    // if(chk.size() > grammar.size()) return false;
    // if(chk.size()==0) return false;
    int non_terminal = 0;

    for (auto i : chk)
    {
        if (productionRules.count(i) == 0)
            non_terminal++;
    }

    if (non_terminal > grammar.size())
    {
        // cout << "Chk " << chk << endl;
        return false;
    }
    if (chk.size() == grammar.size())
    {
        // cout << chk << endl;
        if (chk == grammar)
            return true;
        // else return false;
    }

    bool flag = false;
    for (int i = 0; i < chk.size(); i++)
    {
        if (productionRules.count(chk[i]))
        {
            string newchkL = "";
            for (int j = 0; j < i; j++)
                newchkL += chk[j];
            string newchkR = "";
            for (int j = i + 1; j < chk.size(); j++)
                newchkR += chk[j];

            for (auto it : productionRules[chk[i]])
            {
                string mid = it;
                if (mid == "e")
                    mid = "";
                string newchk = newchkL + mid + newchkR;
                flag = flag | isAccepted(newchk, grammar);
            }
        }
    }
    return flag;
}

int main()
{
    cout << "Enter the number of production rules: ";
    int n;
    cin >> n;
    cin.ignore();
    char strt = '#';
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter rule for production " << i << ": \n";
        string s;
        getline(cin, s);
        // cout << s << endl;
        if (strt == '#')
            strt = s[0];
        string tmp = "";
        for (int j = 1; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                if (tmp.size())
                    productionRules[s[0]].push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += s[j];
            }
        }
        if (tmp.size())
            productionRules[s[0]].push_back(tmp);
    }

    cout << "Enter the number of grammar: " << endl;
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cout << "Enter the grammer " << i << ": \n";
        string grammar;
        cin >> grammar;
        string chk = productionRules[strt][0];
        // chk.push_back(strt);
        if (isAccepted(chk, grammar))
        {
            cout << "Accepted\n";
        }
        else
            cout << "Rejected\n";
    }

    return 0;
}