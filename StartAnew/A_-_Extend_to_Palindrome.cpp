#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getLps(string text)
{
    ll n = text.length();
    vector<ll> lps(n);
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < n)
    {
        if (text[i] == text[j])
        {
            lps[i] = j + 1;
            i++, j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve()
{
    string text;
    while (cin >> text)
    {
        string rtext = text;
        //cout << text << endl; 

        reverse(rtext.begin(), rtext.end());
        if(text == rtext)
        {
            cout << text << endl; 
            continue;
        }
        vector<ll> lps = getLps(rtext +"#" +text);
        cout << text ; 
        for(int i=text.size()-lps.back()-1;i>=0;i--) cout << text[i];  
        cout << endl;  
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}