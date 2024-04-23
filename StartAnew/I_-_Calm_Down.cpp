#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pi acos(-1)

void solve()
{
    double R, r, n; 
    cin >> R >> n; 
    r = (R*sin(pi/n))/(1+sin(pi/n)); 
    cout << setprecision(10) << fixed << r << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}