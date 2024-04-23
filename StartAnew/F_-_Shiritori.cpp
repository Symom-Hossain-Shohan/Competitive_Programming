#include <iostream>
#include <cstring>
using namespace std;

int N;
char arr[16][2];
int dp[65536];

int canwin(int selected, char start)
{
    if (dp[selected] == -1)
    {
        bool win = true;
        for (int i = 0, s = 1; i < N; i++, s <<= 1)
        {
            if (selected & s)
                continue;
            if (arr[i][0] != start)
                continue;
            if (canwin(selected | s, arr[i][1])==false)
                continue;
            win = false;
            break;
        }
        dp[selected] = win;
    }
    return dp[selected];
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        arr[i][0] = str[0];
        arr[i][1] = str[str.length() - 1];
    }

    bool firstwin = false;
    for (int i = 0, s = 1; i < N; i++, s <<= 1)
    {
        if (canwin(s, arr[i][1]) == 1)
        {
            firstwin = true;
            break;
        }
    }

    if (firstwin)
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}