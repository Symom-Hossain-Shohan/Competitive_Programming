#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getLps(string text)
{
    int n = text.size(); 
    vector<ll> lps(n); 
    lps[0] = 0; 
    int i = 1, j=0; 
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
    string text; 
    cin>> text; 
    int n = (int)text.size(); 
    int i = 0, j = n-1; 
    //cout << j << ' '; 
    while(text[i] == text[j] and i<j)  i++, j--; 

    string newText  = ""; 
    for(int k=i;k<=j;k++) newText += text[k]; 
    //cout << newText <<endl; 

    string rtext = newText ;
    reverse(rtext.begin(), rtext.end()); 
    //cout << newText <<endl; 
    vector<ll> lps = getLps(newText + "#" + rtext); 
    ll cnt = lps.back(); 

    lps.clear(); 
    lps = getLps(rtext + "#" + newText); 
    ll cnt1 = lps.back(); 
    string ans; 
    //cout << j << ' '; 
    for(int k=0;k<i;k++) ans.push_back(text[k]); 
    //cout<< cnt <<endl; 
    if(cnt>=cnt1)for(int k=0;k<cnt;k++) ans.push_back(newText[k]); 
    else 
    {
        for(int k=0;k<cnt1;k++) ans.push_back(rtext[k]); 
    }
    for(int k=j+1;k<n;k++) ans.push_back(text[k]); 
    cout << ans <<endl; 

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