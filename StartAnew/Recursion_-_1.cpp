#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll n)
{
    if(n==0) return n; 
    else return  fun(n-1) + n; 
}


void solve()
{
    ll n; 
    cin >> n; 
    cout << fun(n) << endl; 
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