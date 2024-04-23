#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll board[20][20], n; 

void printBoard()
{
    for(int i = 0;i<n;i++, cout << endl)
    {
        for(int j=0;j<n;j++) cout << board[i][j] << ' ';
    }
}

bool isSafe(ll r, ll c)
{
    for(int i = 0;i<r; i++) if(board[i][c]) return false; 

    for(int i = r - 1, j= c-1; i>=0 and j>=0; i--, j--) if(board[i][j]) return false; 
    for(int i = r-1, j = c + 1; i>=0; i--, j++) if(board[i][j]) return false; 
    return true; 
}

bool solveNq(ll r)
{
    if(r==n)
    {
        printBoard();
        return true; 
    }

    for(int c = 0; c<n; c++)
    {
        if(isSafe(r, c))
        {
            board[r][c] = 1; 
            if(solveNq(r+1)) return true; 

            board[r][c] = 0; 
        }
        
    }
    return false; 
}

void solve()
{
    cin >> n; 
    solveNq(0);
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