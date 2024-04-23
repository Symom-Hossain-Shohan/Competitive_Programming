#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k; 
ll mtx [101][101];

int  fun(ll i, ll j, ll k)
{
    if(i==0 and j==0)
    {
        return mtx[i][j] = m; 
    }
    if(mtx[i][j] !=-1) return mtx[i][j]; 
    else if(i==j) return mtx[i][j] = fun(i-1, j-1, k) + k; 
    else if(i>j) return   mtx[i][j] = fun(i-1, j, k) - 1; 
    else return mtx[i][j] = fun(i, j-1, k) - 1; 
}

void solve()
{
    cin >> n >> m >> k; 
    fun(n-1, n-1, k);
    memset(mtx, -1, sizeof(mtx));
    for(int i=0;i<n;i++, cout << endl)
    {
        for(int j=0;j<n;j++)
        {
            if(mtx[i][j] == -1) fun(i, j, k);
            cout << mtx[i][j] << ' ';
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