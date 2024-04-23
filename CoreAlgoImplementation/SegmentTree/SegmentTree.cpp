#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void buildTree(int *tree, int *ar, int s, int e, int index)
{

    // base case
    if (s == e)
    {
        tree[index] = ar[s];
        return;
    }
    // recursive call
    // build the left subtree then the right subtree and finally merge
    int mid = (s + e) / 2;
    buildTree(tree, ar, s, mid, 2 * index);
    buildTree(tree, ar, mid + 1, e, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void solve()
{
    int ar[] = {1, 3, 2, - 5, 6, 4};
    int sz = sizeof(ar) / sizeof(int);
    int *tree = new int[4 * sz + 1];

    buildTree(tree, ar, 0, sz - 1, 1);
    for (int i = 1; i <= 13; i++)
        cout << tree[i] << ' ';
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