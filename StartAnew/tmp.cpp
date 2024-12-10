#include<bits/stdc++.h>
using namespace std;

const int MX = 5e5+9;

int st[4*MX];

void update(int id, int b, int e, int i, int val) {
    if(i < b || e < i) return;
    if(b == i && e == i) {
        st[id] = max (st[id], val);
        return;
    }
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    update(l_id,b,mid,i,val);
    update(r_id,mid+1,e,i,val);
    st[id] = max (st[l_id], st[r_id]);
}

int query(int id, int b, int e, int i, int j) {
    if(j < b || e < i) return 0;
    if(b >= i && e <= j) return st[id];
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    return max (query(l_id,b,mid,i,j), query(r_id,mid+1,e,i,j));
}


int32_t main () {
  cin.tie(0) -> sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
      int n, mx = 0;
      cin >> n;
      int a[n], val[n];
      int ans[n];
      for (int i = 0; i < n; i++) {
          cin >> a[i];
          mx = max (mx, a[i]);
          val[i] = mx;
      }
      for (int i = 0; i <= 4*n; i++) st[i] = 0;
      for (int i = n-1; i >= 0; i--) {
          ans[i] = max (val[i], query(1, 0, n, 0, val[i]-1));
          update (1, 0, n, a[i], ans[i]);
      }
      for (int i = 0; i < n; i++) cout << ans[i] << ' ';
      cout << "\n";
  }
}
