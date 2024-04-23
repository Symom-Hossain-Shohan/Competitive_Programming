#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        ll sum = 0;
        n--;
        k *= 2; 
        if (k >= n)
        {
            sum = n * (n + 1) / 2;
        }
        else
        {
            sum = n * (n + 1) / 2;
            n -= k;
            k--;
            sum -= n * (n + 1) / 2;
        }
        cout << sum << endl;
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