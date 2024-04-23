#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll factorial(ll n)
{
    if(n==0) return 1; 
    else return n * factorial(n-1);
}

void solve()
{
    ll n;
    cin >> n; 
    cout << factorial(n) << endl; 

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