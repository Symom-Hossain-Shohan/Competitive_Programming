#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N = 5, board[][5] = {0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0};

bool isSafe(ll row, ll col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 and j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNqueen(ll row)
{
    if (row >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(row, i))
        {
            board[row][i] = 1;
            if (solveNqueen(row + 1))
                return true;
            board[row][i] = 0;
        }
    }

    return false;
}

void solve()
{
    solveNqueen(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << board[i][j] << ' ';
        cout << endl;
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
