#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n%2==1)
    {
        ll x = n/2+1; 
        ll y = n; 
        while(y>n/2+1)
        {
            cout << x << ' ' << y << ' '; 
            x--, y--; 
        }
        cout << x << endl; 
    }
    else 
    {
        ll x = n/2, y = n; 
        while(x>0)
        {
            cout << x << ' ' << y << ' ';
            x--, y--; 
        }
        cout << endl; 

   }
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