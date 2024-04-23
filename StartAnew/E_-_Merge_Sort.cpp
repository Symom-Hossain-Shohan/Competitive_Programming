#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll cnt = 0;

void Merge(vector<ll> &v, vector<ll> &L, vector<ll> &R)
{
    int i = 0, j = 0, k = 0;
    while (i < (int)L.size() and j < (int)R.size())
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++, k++;
        }
        else
        {
            v[k] = R[j];
            k++, j++;
        }
        cnt++;
    }
    while (i < (int)L.size())
    {
        v[k] = L[i];
        i++, k++, cnt++;
    }
    while (j < (int)R.size())
    {
        v[k] = R[j];
        j++, k++, cnt++;
    }
}

void mergeSort(vector<ll> &v)
{
    int n = v.size();
    if (n < 2)
        return;
    ll mid = n / 2;
    vector<ll> L(mid), R(n - mid);
    for (int i = 0; i < mid; i++)
        L[i] = v[i];
    for (int j = 0, i = mid; i < n; i++, j++)
        R[j] = v[i];
    mergeSort(L);
    mergeSort(R);
    Merge(v, L, R);
}

void solve()
{
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    mergeSort(v);
    cout << v[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << v[i];
    }
    cout << endl
         << cnt << endl;
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