#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    ll mn = 1e18; 
    for(auto &i: v) 
    {
        cin >> i; 
        
    }
    
    
        ll  l =0, r = n-1; 
        ll ans = -1; 
        while(l<=r)
        {
            ll mid = (l+r)/2; 
            if(mid ==0 )
            {
                if(v[mid]<v[n-1] and v[mid]<v[mid+1])
                {
                    ans = mid; 
                    break;
                }
                else l = mid+1; 
            }
            else if(mid == n-1)
            {
                if(v[mid]<v[0] and v[mid]<v[mid-1])
                {
                    ans = mid; 
                    break;
                }
                r = mid -1; ;
            }
            else 
            {
                
                if(v[mid]<v[(mid-1)] and v[mid]<v[(mid+1)] )
                {
                    ans = mid; 
                    break;
                }
                else if (mid<=n/2) l = mid+1; 
                else r = mid -1; 
            }
        }
        cout << ans << endl; 
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}