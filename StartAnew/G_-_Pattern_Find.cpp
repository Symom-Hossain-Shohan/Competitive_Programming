#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>  getLps(string text)
{
    int n = text.size(); 
    vector<ll> lps(n); 
    lps[0] = 0; 
    int i=1, j=0; 
    while(i<n)
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
    string text, pattern; 
    cin >>text >> pattern; 
    vector<ll> lps = getLps(pattern + "#" + text); 
    vector<ll> ans; 
    for(int i = (int)pattern.size();i<(int)lps.size(); i++)
    {
        if(lps[i]==(int)pattern.size())
        {
            ans.push_back(i-2*pattern.size()+ 1);  
        }
    }
    if(ans.size()==0) cout << "Not Found\n"; 
    else 
    {
        cout << ans.size() << endl; 
        for(auto i: ans)  cout << i << ' '; 
        cout << endl; 
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