#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string str, tmp; 

void func(int i, int j)
{
    if(i == str.length())
    {
        for(int k = 0; k<j; k++) cout << tmp[k]; 
        cout << endl; 
        return; 
    }
    tmp[j] = str[i];
    func(i+1, j+1);
    func(i+1, j);
}


void solve()
{
    cin >> str; 
    func(0, 0);
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