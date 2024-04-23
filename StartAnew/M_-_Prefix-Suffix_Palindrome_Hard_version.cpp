#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>  getLps(string text)
{
    int n  = text.length(); 
    vector<ll> lps(n); 
    lps[0] = 0; 
    int i=1, j = 0; 
    while(i<n)
    {
        if(text[i] == text[j])
        {
            lps[i] = j+1; 
            i++, j++; 
        }
        else 
        {
            if(j!=0 ) 
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

string soln(string text)
{
    
    string rtext  =text ; 
    reverse(rtext.begin(), rtext.end()); 
    vector<ll> lps = getLps(text + "#" + rtext); 
    ll cnt = 0; 
    //for(auto i: lps) cout << i << ' '; 
    for(int i= (int)text.size() + 1;i<(int)lps.size() and lps[i]!=0; i++)
    {   
        cnt = max(cnt, lps[i]); 
    }  
    //cout <<cnt <<endl; 
    string ans = "";  
    for(int i=0;i<cnt;i++)
    {
        ans += text[i];  
        rtext.pop_back(); 
    }
    text = rtext; 
    reverse(text.begin(), text.end()); 
    for(int i=0;i<cnt;i++) text.pop_back(); 
    rtext = text; 
    reverse(rtext.begin(), rtext.end()); 
    lps.clear(); 
    lps = getLps(text + "#" + rtext); 
    ll  x= lps.back(); 
    for(int i=0;i<x;i++) ans += text[i]; 
    for(int i=cnt-1;i>=0;i--) ans += ans[i]; 
    return ans; 
}

bool isPallindrome(string text)
{
    string rtext = text; 
    reverse(rtext.begin(), rtext.end()); 
    if(text == rtext) return true; 
    else return false; 

    
}

void solve()
{
    string text; 
    cin>> text; 
    if(isPallindrome(text))
    {
        cout<< text<<endl; 
        return; 
    }
    string rtext = text; 
    reverse(rtext.begin(), rtext.end());
    string ans1= soln(text); 
    string ans2 = soln(rtext); 
    if(ans1.size()>=ans2.size()) cout << ans1 << endl; 
    else cout << ans2 << endl; 
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