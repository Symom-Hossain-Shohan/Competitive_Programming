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
    bool increasingTriplet(vector<int> &nums)
    {
        stack<int> st; 

        st.push(nums[0]); 
        int n = nums.size(); 

        for(int i=1;i<n; i++)
        {
            if(st.empty()) st.push(nums[i]); 
            else if(st.top()<nums[i])
            {
                st.push(nums[i]); 
            }
            else 
            {
                while(!st.empty() and st.top()>=nums[i]) st.pop(); 
                st.push(nums[i]); 
            }

            if(st.size()>=3) return true; 
        }

        return st.size()>=3; 
    }
};
void solve()
{
    Solution s;
    vector<int> nums = {2,1,5,0,4,6};
    bool a = s.increasingTriplet(nums);
    cout << a << endl;
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