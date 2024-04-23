#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, fib[105];

ll dpFib(ll n)
{
    if(n<=1) return n;
    if(fib[n]!=-1) return fib[n];
    return fib[n] = dpFib(n-1) + dpFib(n-2);
}


void solve()
{
    cin >> n; 
    memset(fib, -1, sizeof(fib)); 
    cout << dpFib(n) << endl; 

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