#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn], b[maxn];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        a[i + 1] = s[i] - '0';
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = n; i >= 2; i--)
        a[i - 1] += a[i] / 10, a[i] = a[i] % 10;
    int flag = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] || flag)
            flag = 1, printf("%d", a[i]);
    printf("\n");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}