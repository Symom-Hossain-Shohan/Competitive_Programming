#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    int ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1]) swap(ar[j], ar[j+1]); 
        }

    }

    for(auto i: ar) cout << i << ' '; 
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