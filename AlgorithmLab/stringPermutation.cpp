#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void permute(string &s, int l, int r)
{
    if (l==r) cout << s <<endl; 
    else 
    {
        for(int i = l; i<=r;i++)
        {
            swap(s[i],s[l]); 

            permute(s, l+1, r); 

            swap(s[i],s[l]); 
        }
    }
}

void solve()
{
    string s; 
    cin >>s; 
    permute(s, 0, (int)s.size()-1) ; 
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