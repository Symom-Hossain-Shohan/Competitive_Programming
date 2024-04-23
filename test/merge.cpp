#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void merge(vector<ll> &v, vector<ll> &left, vector<ll> &right)
{
    int i = 0, j = 0, r = 0;
    while (i < (int)left.size() and j < (int)right.size())
    {
        if (left[i] < right[j])
            v[r] = left[i], i++, r++;
        else
            v[r] = right[j], j++, r++;
    }

    while (i < (int)left.size())
        v[r] = left[i], i++, r++;
    while (j < (int)right.size())
        v[r] = right[j], j++, r++;
}

void mergeSort(vector<ll> &v)
{
    ll n = v.size();
    if (n < 2)
        return;
    ll mid = n / 2;

    vector<ll> left(mid), right(n - mid);
    for (int i = 0; i < mid; i++)
        left[i] = v[i];

    for (int i = mid, j = 0; i < n; i++, j++)
        right[j] = v[i];
    mergeSort(left);
    mergeSort(right);

    merge(v, left, right);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    mergeSort(v);
    for (auto i : v)
        cout << i << ' ';
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