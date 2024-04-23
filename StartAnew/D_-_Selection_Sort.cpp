#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
for i = 0 to A.length-1
2     mini = i
3     for j = i to A.length-1
4         if A[j] < A[mini]
5             mini = j
6     swap A[i] and A[mini]
*/

void solve()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < n ; i++)
    {
        ll mini = i;
        for (int j = i; j < n ; j++)
        {
            if (v[j] < v[mini])
                mini = j;
        }
        if (i != mini)
        {
            cnt++;
            swap(v[i], v[mini]);
        }
    }
    cout << v[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << v[i];
    cout << endl << cnt << endl; 
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