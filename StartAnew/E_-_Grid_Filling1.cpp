#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll R, C, n, h, w; 
const ll mx = 305; 
ll cnt[mx][mx][mx];  

int  vis[mx], x,sum; 

void solve()
{
    cin >> R >> C >> n >> h >> w; 
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin>> x; 
            if(!vis[x]) sum++; 
            vis[x] = 1; 
            for(int k=1;k<=n;k++) 
                cnt[i][j][k] = cnt[i-1][j][k] + cnt[i][j-1][k] - cnt[i-1][j-1][k] + (k==x); 
        }
    }

    for(int i=h;i<=R;i++, cout << endl)
    {   
        for(int j=w;j<=C;j++)
        {
            int s = 0; 
            for(int k=1;k<=n;k++)
            {
                if(vis[k]) s += cnt[i][j][k] - cnt[i-h][j][k] - cnt[i][j-w][k] + cnt[i-h][j-w][k] == cnt[R][C][k]; 
            }
            cout << sum - s << ' '; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}