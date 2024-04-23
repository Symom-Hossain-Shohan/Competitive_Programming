#include <iostream>
using namespace std;
const int N = 305;
int vis[N], sum, f[N][N][N];

int main()
{
    int n, m, K, h, w;
    cin >> n >> m >> K >> h >> w;
    for (int i = 1; i <= n; ++i)
        for (int j = 1, x; j <= m; ++j)
        {
            scanf("%d", &x);
            if (!vis[x])
                sum++;
            vis[x] = 1;
            for (int k = 1; k <= K; ++k)
                f[i][j][k] = f[i - 1][j][k] + f[i][j - 1][k] - f[i - 1][j - 1][k] + (k == x);
        }
    for (int i = h; i <= n; ++i, puts(""))
        for (int j = w; j <= m; ++j)
        {
            int s = 0;
            for (int k = 1; k <= K; ++k)
                if (vis[k])
                    s += f[i][j][k] - f[i - h][j][k] - f[i][j - w][k] + f[i - h][j - w][k] == f[n][m][k];
            printf("%d ", sum - s);
        }


   
}