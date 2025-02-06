#include <bits/stdc++.h>
using namespace std;

vector<string> keys = {"int", "for", "return", "while", "true", "false", "do"};
vector<string> ops = {"+", "-", "*", "/", "%", "++", "--", "<", "<=", ">", ">=", "&", "|", "!", "&&", "||", ","};

set<string> keyword, operators, constants, functions, idnt;
map<string, int> identifiers;

bool is_terminal(char c)
{
    return c == ' ' or c == '\n' or c == '+' or c == '-' or c == '*' or c == '%' or c == '(' or c == ')' or c == '{' or c == '}' or c == ',' or c == ';' or c == '=' or c == '<';
}

bool isKey(string s)
{
    return s == "int" or s == "for" or s == "return";
}

map<string, int> mp;
int cnt = -1;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    sort(keys.begin(), keys.end());
    sort(ops.begin(), ops.end());
    string s;
    while (getline(cin, s))
    {
        string lex = "";
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (is_terminal(s[i]))
            {
                // cout << lex << endl;
                if (s[i] == '+')
                {
                    if (i + 1 < s.size() and s[i + 1] == '+')
                    {
                        operators.insert("++");
                    }
                    else
                        operators.insert("+");
                }
                else if (s[i] == '-')
                {
                    if (i + 1 < s.size() and s[i + 1] == '-')
                    {
                        operators.insert("--");
                    }
                    else
                        operators.insert("-");
                }
                else if (s[i] == '<')
                {
                    if (i + 1 < s.size() and s[i + 1] == '=')
                    {
                        operators.insert("<=");
                    }
                    else
                        operators.insert("<");
                }
                else if (s[i] == ',' or s[i] == ';' or s[i] == '(' or s[i] == ')' or s[i] == '{' or s[i] == '}')
                {
                    string op = "";
                    op += s[i];
                    operators.insert(op);
                }

                if (i + 1 < s.size() and s[i + 1] == '+')
                {
                    operators.insert("++");
                }
                else
                    operators.insert("+");
                if (lex[0] >= '0' and lex[0] <= '9')
                {
                    constants.insert(lex);
                }
                else if (isKey(lex))
                {
                    keyword.insert(lex);
                }
                else if (lex == "main")
                {
                    functions.insert(lex);
                }
                else
                {
                    idnt.insert(lex);
                    if (mp.count(lex) == 0 and lex[0] != ' ')
                    {
                        mp[lex] = cnt;
                        cnt++;
                    }
                }
                lex = "";
            }
            else
            {
                lex += s[i];
            }
        }
        if (lex[0] >= '0' and lex[0] <= '9')
        {
            constants.insert(lex);
        }
        else if (isKey(lex))
        {
            keyword.insert(lex);
        }
        else if (lex == "main")
        {
            functions.insert(lex);
        }
        else
        {
            idnt.insert(lex);
            if (mp.count(lex) == 0 and lex[0] != ' ')
            {
                mp[lex] = cnt;
                cnt++;
            }
        }
        // cout << lex;
    }

    cout << "Keywords: \n";
    for (auto i : keyword)
        cout << i << endl;
    cout << "Functions: \n";
    for (auto i : functions)
        cout << i << endl;
    cout << "Constants: \n";
    for (auto i : constants)
        cout << i << endl;
    cout << "Identifiers: \n";
    for (auto i : idnt)
        if (i != "")
            cout << i << endl;

    cout << "Operators: \n";
    for (auto i : operators)
    {
        if (i[0] != ' ')
            cout << i << endl;
    }

    cout << "Symbol Table: \n";
    for (auto i : mp)
    {
        if (i.second == -1)
            continue;
        else
            cout << i.first << ' ' << i.second << endl;
    }
}