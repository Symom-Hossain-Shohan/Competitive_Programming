#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> cfg;
string start_symbol;

bool isAccepted(string current, string sample, int pos) {
    int x = sample.size();

    if (current.empty()) {
        return pos == x;
    }

    string first_symbol = "";
    first_symbol += current[0];
    string rest = current.substr(1);
    
    if (cfg.find(first_symbol) == cfg.end()) { 
        if (pos < x && first_symbol == string(1, sample[pos])) {
            return isAccepted(rest, sample, pos + 1);
        }
        return false;
    }
    
    for (string production : cfg[first_symbol]) {
        if (production == "e") { 
            if (isAccepted(rest, sample, pos)) {
                return true;
            }
        } else {
            if (isAccepted(production + rest, sample, pos)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        string lhs;
        cin >> lhs;
        string rhs;
        getline(cin, rhs);
        
        stringstream ss(rhs);
        string token;
        vector<string> productions;
        
        while (ss >> token) {
            productions.push_back(token);
        }
        
        cfg[lhs] = productions;
        if (i == 0) {
            start_symbol = lhs;
        }
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        string sample;
        cin >> sample;
        
        if (isAccepted(start_symbol, sample, 0)) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }
}