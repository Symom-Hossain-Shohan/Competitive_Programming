#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    // we can solve this problem using time tag
    ll n;
    cin >> n;
    vector<ll> v(n), tim(n, 0);
    for (auto &i : v)
        cin >> i;
    ll qtim = 0, qup = -1;
    ll q;
    cin >> q;
    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            qtim++;
            cin >> qup;
        }
        else if (op == 2)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            if (qtim > tim[a])
            {
                tim[a] = qtim;
                v[a] = qup;
            }
            v[a] += b;
        }
        else
        {
            ll a;
            cin >> a;
            a--;
            if (qtim > tim[a])
            {
                tim[a] = qtim;
                v[a] = qup;
            }
            cout << v[a] << endl;
        }
    }
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