#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum, n, memo[1000][100]; 
ll ar[100]; 
bool dp(ll sum, ll pos)
{
    if(sum==0) return true; 
    if(pos==n) return false;  
    if(memo[sum][pos]==-1)
    {
        memo[sum][pos] = (dp(sum-ar[pos], pos+1) | dp(sum, pos+1)); 
    }
    return memo[sum][pos]; 
}


void solve()
{
    cin >> sum >> n; 
    memset(memo, -1, sizeof(memo)); 
    for(int i = 0;i <n;i++) cin >> ar[i]; 
    if(dp(sum, 0)) cout << "Possible\n"; 
    else cout << "Not Possible\n"; 
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