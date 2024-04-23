#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string a, b; 
    cin >> a >> b; 

    ll x = a.length(), y = b.length(); 

    int lcs[x+1][y+1]; 

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 or j==0) lcs[i][j] = 0; 
            else if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1; 
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);        
        }
    }

    cout << lcs[x][y] << endl; 
    string ans; 
    ll i = x, j = y; 
    while(i>0 and j>0)
    {
        if(a[i-1] == b[j-1])
        {
            //cout << a[i-1]; 
            ans.push_back(a[i-1]); 
            i--, j--; 
        }
        else if(lcs[i][j-1]>lcs[i-1][j]) j--; 
        else i--; 
    }
    cout << ans << endl; 
    reverse(ans.begin(), ans.end());  
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}