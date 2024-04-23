#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getZ(string text)
{
    vector<ll> Z(text.length());
    ll n = text.length();
    int l = 0, r = 0;
    Z[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = i, r = i;
            while (r < n and text[r - l] == text[r])
            {
                r++;
            }
            Z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (Z[k] + i <= r)
            {
                Z[i] = Z[k];
            }
            else
            {
                l = i;
                while (r < n and text[r - l] == text[r])
                    r++;
                Z[i] = r - l;
                r--;
            }
        }
    }
    return Z; 
}

void solve()
{
    string text;
    cin >> text;
    vector<ll> Z = getZ(text);
    for (auto i : Z)
        cout << i << ' ';
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