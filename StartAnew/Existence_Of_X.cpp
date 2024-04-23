#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getBit(int a, int i)
{
    return (a >> i) & 1;
}

int getSum(int a, int b, int c)
{
    return a ^ b ^ c;
}

int getCary(int a, int b, int c)
{
    return (a & b) + (c & (a ^ b));
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll cary = 0, ai = 0, bi = 0, ci = 0, aix, bix, cix, sum = 0, sumxor = 0;
    for (int i = 0; i < 27; i++)
    {
        ai = getBit(a, i);
        bi = getBit(b, i);
        ci = getBit(c, i);

        sum = getSum(ai, bi, cary);

        aix = ai ^ 1, bix = bi ^ 1, cix = ci ^ 1;
        sumxor = getSum(aix, bix, cary);

        if (sum == ci)
        {
            cary = getCary(ai, bi, cary);
        }
        else if (sumxor == cix)
            cary = getCary(aix, bix, cary);
    }

    if (cary == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}