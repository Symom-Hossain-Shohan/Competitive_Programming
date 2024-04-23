#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 
    vector<ll> tmp = v;  
    sort(v.begin(), v.end());  
    int i= -1, j=-1;  
    if(tmp==v)
    {
        cout << "yes\n1 1\n"; 
    }
    else 
    {
        i = 0; 
        while(tmp[i]==v[i]) i++; 
        j = n-1; 
        while(tmp[j]==v[j]) j--; 
        //cout << i << ' ' << j << endl;
        reverse(tmp.begin()+i, tmp.begin()+j+1); 
        // for(auto i: tmp) cout << i << ' '; 
        // cout << endl; 
        if(tmp==v)
        {
            cout << "yes\n"; 
            cout << i+1 << ' ' << j+1 << endl; 
        }
        else 
        {
            cout << "no\n"; 
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