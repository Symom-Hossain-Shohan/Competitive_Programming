#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 2e5 + 5;
inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication
inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int ans = 0; 
        int l = 0, r = citations.back();

        while(l<=r)
        {
            int mid = (l+r)/2; 

            int l_ = 0, r_ = citations.size()-1;
            int pos = 0; 
            while(l_<=r_)
            {
                int mid_ = (l_+r_)/2;
                if(citations[mid_] >= mid)
                {
                    pos = mid_;
                    r_ = mid_-1;
                }
                else
                {
                    l_ = mid_+1;
                }
            }

            if(citations.size()-pos >= mid)
            {
                ans = max(ans, mid);
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }

        return ans;
    }
};

void solve()
{
    Solution s1;
    vector<int> citations = {10, 11};
    cout << s1.hIndex(citations) << endl;
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