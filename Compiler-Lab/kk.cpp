#include <bits/stdc++.h>
using namespace std;

vector<pair<double, int>> tokens;
map<int, int> maap;

void separateToken(string s) {
    for (int i = 0; i < s.length(); i++) {
        string temp = "";
        if (isdigit(s[i]) || s[i] == '.') {
            while (i < s.size() && (isdigit(s[i]) || s[i] == '.')) {
                temp += s[i];
                i++;
            }
            i--;
            tokens.push_back({stod(temp), 0});
        } else {
            tokens.push_back({double(s[i]), 1});
        }
    }
}

void printTokens() {
    for (int i = 0; i < tokens.size(); i++) {
        if (maap[i] == 0) {
            if (tokens[i].second != 0) {
                cout << char(int(tokens[i].first));
            } else {
                cout << tokens[i].first;
            }
        }
    }
    cout << endl;
}

double do_operation(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '%') return int(a) % int(b);
    return 0;
}

void evaluate_expression() {
    map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 3}, {'%', 2}};
    stack<pair<char, int>> operators;
    stack<pair<double, int>> operands;

    for (int i = 0; i < tokens.size(); i++) {
        double x = tokens[i].first;
        int type = tokens[i].second;

        if (type == 0) {
            operands.push({x, i});
        } else {
            char op = char(int(x));
            while (!operators.empty() && precedence[op] < precedence[operators.top().first]) {
                pair<char, int> opr = operators.top(); operators.pop();
                pair<double, int> num2 = operands.top(); operands.pop();
                pair<double, int> num1 = operands.top(); operands.pop();
                double res = do_operation(num1.first, num2.first, opr.first);
                operands.push({res, num1.second});
                tokens[num1.second] = {res, 0};
                for (int j = num1.second + 1; j <= num2.second; j++) maap[j] = 1;
                printTokens();
            }
            operators.push({op, i});
        }
    }

    while (!operators.empty()) {
        pair<char, int> opr = operators.top(); operators.pop();
        pair<double, int> num2 = operands.top(); operands.pop();
        pair<double, int> num1 = operands.top(); operands.pop();
        double res = do_operation(num1.first, num2.first, opr.first);
        operands.push({res, num1.second});
        tokens[num1.second] = {res, 0};
        for (int j = num1.second + 1; j <= num2.second; j++) maap[j] = 1;
        printTokens();
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    string s;
    getline(cin, s);
    separateToken(s);
    printTokens();
    evaluate_expression();
    return 0;
}