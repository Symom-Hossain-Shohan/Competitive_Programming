#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string productionRule;
    int n;

    // cout << "Enter production rule (e.g., A -> aB | b): ";
    getline(cin, productionRule);

    size_t arrowPos = productionRule.find("->");
    if (arrowPos == string::npos)
    {
        cerr << "Invalid production rule format!" << endl;
        return 1;
    }

    string lhs = productionRule.substr(0, arrowPos - 1);
    string rhs = productionRule.substr(arrowPos + 2);

    lhs.erase(remove(lhs.begin(), lhs.end(), ' '), lhs.end());
    rhs.erase(remove(rhs.begin(), rhs.end(), ' '), rhs.end());

    vector<string> productions;
    size_t pos = 0;
    while ((pos = rhs.find("|")) != string::npos)
    {
        productions.push_back(rhs.substr(0, pos));
        rhs.erase(0, pos + 1);
    }
    productions.push_back(rhs);

    cout << "Enter the number of grammar strings to check: ";
    cin >> n;
    cin.ignore();

    vector<string> grammar;
    cout << "Enter the grammar strings: \n";
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        grammar.push_back(str);
    }

    cout << "Checking grammar against production rule...\n";
    for (const string &str : grammar)
    {
        bool accepted = false;
        for (const string &prod : productions)
        {
            if (regex_match(str, regex(prod)))
            {
                accepted = true;
                break;
            }
        }
        if (accepted)
        {
            cout << "Accepted: " << str << endl;
        }
        else
        {
            cout << "Rejected: " << str << endl;
        }
    }

    return 0;
}