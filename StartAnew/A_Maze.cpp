#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

void solve()
{
    ll n, m, k; 
    cin >> n >> m >> k; 
    vector<vector<char>> v(n, vector<char>(m));
    pair<int, int> start = {-1, -1};
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<m; j++)
        {
            cin >> v[i][j];
            if(v[i][j] == '.' and start.first == -1)
            {
                start = {i, j};
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    map<ll, vector<pair<ll,ll>>> lvl; 
    int mxLevel = 0;
    vector<vector<int>> level(n, vector<int>(m, 0));
    queue<pair<ll, ll>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    lvl[0].push_back(start);
    level[start.first][start.second] = 0;
    ll dx[] = {0, 0, 1, -1};
    ll dy[] = {1, -1, 0, 0};
    while(!q.empty())
    {
        ll x = q.front().first, y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if(nx>=0 and ny>=0 and nx<n and ny<m and v[nx][ny] == '.' and !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                lvl[level[x][y] + 1].push_back({nx, ny});
                level[nx][ny] = level[x][y] + 1;
                mxLevel = max(mxLevel, level[nx][ny]);
            }
        }
    }
    for(int i=mxLevel; i>=0 and k; i--)
    {

        for(auto x: lvl[i])
        {
            v[x.first][x.second] = 'X';
            k--;
            if(k == 0)
            {
                break;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}