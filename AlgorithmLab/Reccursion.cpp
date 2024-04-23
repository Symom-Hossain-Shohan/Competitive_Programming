#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib(ll n)
{
    if(n<=1) return n; 
    else return fib(n-1) + fib(n-2); 
}

void solve()
{
    int n; 
    cin >>n; 
    cout << fib(n) <<endl; 
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
