#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c, d, e, f, n;

ll memo[10005], mod = 10000007;

ll dp(ll n)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;
    if (n == 3)
        return d;
    if (n == 4)
        return e;
    if (n == 5)
        return f;

    ll &ans = memo[n];
    if (ans == -1)
    {
        ans = (dp(n - 1) + dp(n - 2) + dp(n - 3) + dp(n - 4) + dp(n - 5) + dp(n - 6)) % mod;
    }
    return ans % mod;
}

void solve()
{
    cin >> a >> b >> c >> d >> e >> f >> n;

    memset(memo, -1, sizeof(memo));
    cout <<   dp(n) % mod << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}