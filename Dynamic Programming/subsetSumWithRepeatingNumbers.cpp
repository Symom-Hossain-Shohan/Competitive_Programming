#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll sum, n, memo[100][1000], ar[100];

bool dp(ll pos, ll sum)
{
    if (sum == 0)
        return true;
    if (pos == n)
        return false;

    if (memo[pos][sum] == -1)
    {
        memo[pos][sum] = (dp(pos + 1, sum - ar[pos]) | dp(pos + 1, sum) | dp(pos, sum - ar[pos]));
    }
    return memo[pos][sum];
}

void solve()
{
    cin >> sum >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    memset(memo, -1, sizeof(memo)); 
    if (dp(0, sum))
        cout << "Possible\n";
    else
        cout << "Not Possible\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}