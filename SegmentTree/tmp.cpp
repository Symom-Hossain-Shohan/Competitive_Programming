/// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 9;
int l[M], r[M], v[M];
int t[4 * M], lz[4 * M];
void propagate(int pos)
{
    t[pos] = lz[pos];
    lz[pos] = 0;
    if (2 * pos + 1 >= 4 * M)
        return;
    lz[2 * pos] = t[pos];
    lz[2 * pos + 1] = t[pos];
}
void upd(int pos, int l, int r, int I, int J, int val)
{
    if (lz[pos])
        propagate(pos);
    if (l > J || r < I || l > r)
        return;
    if (I <= l && J >= r)
    {
        lz[pos] = val;
        propagate(pos);
        return;
    }
    int mid = (l + r) >> 1;
    upd(2 * pos, l, mid, I, J, val);
    upd(2 * pos + 1, mid + 1, r, I, J, val);
    t[pos] = val;
}
int qry(int pos, int l, int r, int idx)
{
    if (lz[pos])
        propagate(pos);
    if (l == r)
        return t[pos];
    int mid = (l + r) >> 1;
    if (idx <= mid)
        return qry(2 * pos, l, mid, idx);
    else
        return qry(2 * pos + 1, mid + 1, r, idx);
}
main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &l[i], &r[i], &v[i]);
    }
    for (int i = m; i >= 1; i--)
    {
        upd(1, 1, n, l[i], v[i] - 1, v[i]);
        upd(1, 1, n, v[i] + 1, r[i], v[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = qry(1, 1, n, i);
        printf("%d ", ans);
    }
    return 0;
}
