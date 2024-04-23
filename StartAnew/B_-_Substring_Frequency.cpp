#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getLps(string text)
{
    vector<ll> lps(text.size()); 
    lps[0] = 0; 
    int i = 1, j=0; 
    while(i<(int)text.size())
    {
        if(text[i] == text[j]) 
        {
            lps[i] = j+1; 
            i++, j++; 
        }
        else 
        {
            if(j!=0)
            {
                j = lps[j-1]; 
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
    cin >> text; 
    vector<ll> lps = getLps(text);  
    ll n = text.size() - 1; 
    if(lps[n]==0)
    {
        cout << "Just a legend\n"; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}