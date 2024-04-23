#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e6+1; 

vector<bool> is_prime(mx,true);
vector<int> primes; 

void seive()
{
    is_prime[1]= false; 
    primes.push_back(2);
    for(int i=3;i*i<=1e6;i++)
    {
        if(is_prime[i])
        {
            for(int j =i*i; j<=1e6;j+=2*i)
            {
                is_prime[j] = false; 
            }
        }
    }

    for(int i=3;i<=1e6;i+=2) 
    {
        if(is_prime[i]) primes.push_back(i);
    }
}

void solve()
{
    seive();
    ll n; 
    cin >> n; 
    ll cnt = 0; 
    for(auto i: primes)
    {
        if(i<=n) cnt++; 
        else break;
    } 

    cout << cnt << endl; 

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