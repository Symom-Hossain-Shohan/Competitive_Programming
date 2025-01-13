#include <bits/stdc++.h>
using namespace std;

bool isGood(char c)
{
    if (c >= 'a' and c <= 'z')
        return true;
    if (c >= 'A' and c <= 'Z')
        return true;
    if (c >= '0' and c < '9')
        return true;
    return false;
}

bool isOps(char c)
{
    if (c == '+' or c == '-' or c == '*' or c == '/')
        return true;
    return false;
}

bool isPunc(char c)
{
    if (c == ',' or c == '.' or c == ':' or c == ';')
        return true;
    return false;
}
int main()
{
    FILE *ptr, *wptr;
    ptr = fopen("in.txt", "r");
    wptr = fopen("out.txt", "w");
    char arr[100001];
    vector<string> functions, operators, dataTypes, punctuations, keywords;
    functions = {"main", "printf", "scanf"};
    operators = {"+", "-", "*", "/", "%"};
    dataTypes = {"int", "float", "double", "string", "char", "bool"};
    punctuations = {",", ".", ":", ";"};
    keywords = {"return", "true", "false", "if", "else", "for", "while", "do"};

    sort(functions.begin(), functions.end());
    sort(operators.begin(), operators.end());
    sort(dataTypes.begin(), dataTypes.end());
    sort(punctuations.begin(), punctuations.end());
    sort(keywords.begin(), keywords.end());

    vector<string> keys, funs, dTypes, others;
    vector<char> ops, puns;

    while (fgets(arr, 100001, ptr))
    {
        string cur = "";

        for (int i = 0; arr[i] != '\0'; i++)
        {
            if (isGood(arr[i]))
            {
                cur += arr[i];
            }
            else
            {
                if (binary_search(keywords.begin(), keywords.end(), cur))
                    keys.push_back(cur);
                else if (binary_search(functions.begin(), functions.end(), cur))
                    funs.push_back(cur);
                else if (binary_search(dataTypes.begin(), dataTypes.end(), cur))
                    dTypes.push_back(cur);
                else if (cur != "")
                    others.push_back(cur);

                cur = "";
                if (isOps(arr[i]))
                    ops.push_back(arr[i]);
                else if (ispunct(arr[i]))
                    puns.push_back(arr[i]);
            }
        }
    }

    cout << "Keywords: \n";
    for (auto i : keys)
        cout << i << "\n";
    cout << "Functions: \n";
    for (auto i : funs)
        cout << i << "\n";
    cout << "Operators: \n";
    for (auto i : ops)
        cout << i << "\n";
    cout << "Others: \n";
    for (auto i : puns)
        cout << i << endl;
    for (auto i : others)
        cout << i << "\n";
    cout << "Data Types: \n";
    for (auto i : dTypes)
        cout << i << "\n";

    fprintf(wptr, "Keywords:\n");
    for (auto i : keys)
        fprintf(wptr, "%s\n", i.c_str());
    fprintf(wptr, "Functions:\n");
    for (auto i : funs)
        fprintf(wptr, "%s\n", i.c_str());
    fprintf(wptr, "Operators:\n");
    for (auto i : ops)
        fprintf(wptr, "%c\n", i);
    fprintf(wptr, "Punctuations:\n");
    for (auto i : puns)
        fprintf(wptr, "%c\n", i);
    fprintf(wptr, "Others:\n");
    for (auto i : others)
        fprintf(wptr, "%s\n", i.c_str());
    fprintf(wptr, "Data Types:\n");
    for (auto i : dTypes)
        fprintf(wptr, "%s\n", i.c_str());
}