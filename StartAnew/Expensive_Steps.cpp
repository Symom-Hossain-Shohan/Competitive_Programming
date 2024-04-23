#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, x1, y1, x2, y2; 
    cin >> n >> x1 >> y1 >> x2 >> y2; 
    ll ans1 = abs(x2-x1) + abs(y2-y1); 
    ll ans2 = min({x1, n-x1+1, y1, n-y1+1}) + min({x2, n-x2+1, y2, n-y2+1});
    cout << min(ans1, ans2) << endl;  
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