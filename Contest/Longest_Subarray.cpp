#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    for (int i = 1; i < n; i++)
        a[i] |= a[i - 1];
    for (int i = n - 2; i >= 0; i--)
        b[i] |= b[i + 1];

    if (a[n - 1] == 0)
        cout << n << endl;
    else
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}