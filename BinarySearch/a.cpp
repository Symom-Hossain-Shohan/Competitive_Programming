#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] += i + 1;
        }
        sort(a, a + n, greater<int>());
        for (int i = 1; i < n; i++)
            a[i] = min(a[i], a[i - 1] - 1);
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
}