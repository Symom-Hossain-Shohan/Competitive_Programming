//https://codeforces.com/problemset/problem/577/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m; 
ll memo[1005][1005], ar[1005]; 

bool dp(ll pos, ll sum)
{
    if(sum == 0) return true; 
    if(pos==n) return  false; 

    ll &ans = memo[pos][sum]; 
    if(ans==-1)
    {
        if(sum-ar[pos]<0)
        {
            ans = (dp(pos+1, (sum+m-ar[pos])) |dp(pos+1, sum) );  
        }
        else 
        {
            ans = (dp(pos+1, (sum-ar[pos])) | dp(pos+1, sum)); 
        }
    }
    return ans; 
}


void solve()
{
    cin >> n >> m; 
    if(n>m) cout << "YES\n"; //pigeonhole principle er karone 
    else 
    {
        for(int i = 0;i<n;i++)
        {
            cin >> ar[i]; 
            ar[i] %= m; 
        }
        if(count(ar, ar+n, 0)) 
        {
            cout << "YES\n"; 
            return; 
        }

        memset(memo, -1, sizeof(memo)); 

        if(dp(0, m)) cout << "YES\n"; 
        else cout << "NO\n"; 
    }
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