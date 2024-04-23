#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char ar[17][2];
ll dp[65536];
ll n; 

bool isSafe(ll selected, char start)
{
    if(dp[selected]==-1)
    {
        bool ok = true; 
        for(int i=0, s = 1;i<n;i++, s<<=1)
        {
            if(s & selected) continue;
            if(start != ar[i][0]) continue;
            if(isSafe(s|selected, ar[i][1])==false) continue;

            ok = false; 
            break;
        }
        dp[selected] = ok; 
    }
    return dp[selected];
}
void solve()
{
    cin >> n; 
    for(int i=0;i<n;i++)
    {
        string s; 
        cin >> s; 
        ar[i][0] = s[0];
        ar[i][1] = s[s.length()-1]; 
    }
    memset(dp, -1, sizeof(dp)); 

    bool ok = false; 
    for(int i=0, s = 1; i<n;i++, s<<=1)
    {
        if(isSafe(s, ar[i][1]))
        {
            ok = true; 
            break;
        }
    }
    if(ok) cout << "First\n"; 
    else cout << "Second\n"; 
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