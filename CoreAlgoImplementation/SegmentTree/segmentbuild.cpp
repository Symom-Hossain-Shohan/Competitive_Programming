#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void buildTree(int *tree, int *ar, int s, int e, int index)
{
    if (s == e)
    {
        tree[index] = ar[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(tree, ar, s, mid, 2 * index);
    buildTree(tree, ar, mid + 1, e, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

ll query(int *tree, int ss, int se, int qs, int qe, int index)
{
    // completer overlap
    if (ss >= qs and se <= qe)
    {
        return tree[index];
    }
    // non overlapping 
    else if (qe<ss or qs>se)
    {
        return INT_MAX ;
    }
    else
    {
        ll mid = (ss + se) / 2;
        ll left = query(tree, ss, mid, qs, qe, 2 * index);
        ll right = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
        return min(left, right);
    }
}

void update(int *tree, int ss, int se, int i, int increment, int index)
{
    if(i<ss or i>se) return; 
    if(ss == se) 
    {
        tree[ss] += increment; 
        return;
    }

    int mid = (ss + se)/2; 
    update(tree, ss, mid, i, increment, 2*index);
    update(tree, mid+1, se, i, increment, 2*index + 1); 
    tree[index] = min(tree[2*index], tree[2*index+1]); 
    return; 
}

void solve()
{
    int ar[] = {1, 3, 2, -5, 6, 4};
    int sz = sizeof(ar) / sizeof(int);

    int *tree = new int(4 * sz + 1);
    buildTree(tree, ar, 0, sz - 1, 1);
    
    update(tree, 0, sz-1, 3, 10, 1); 

    int q; 
    cin >> q; 
    while(q--)
    {
        ll l, r; 
        cin >> l >> r; 
        cout << query(tree, 0, sz-1, l, r, 1) << endl;
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