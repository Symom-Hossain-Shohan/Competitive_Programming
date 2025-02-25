#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2e5+5;
inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            //for rows 
            int rows = matrix.size(), cols = matrix[0].size(); 
    
            int l = 0, r = rows*cols-1; 
            // cout << rows << " " << cols << endl;
            // cout << l << " " << r << endl;
            while(l<=r)
            {
                int mid = (l+r)/2; 
                int i = mid/cols, j = mid%cols; 
                cout << i << " " << j << endl;
                if(matrix[i][j]==target)
                {
                    return true; 
                }
                if(matrix[i][j]<target)
                {
                    l = mid+1; 
                }
                else r = mid-1; 
            }
            return false; 
    
        }
    };
    

void solve()
{
    vector<vector<int>> matrix = {{1}}; 
    int target = 2; 

    Solution obj;
    cout<<obj.searchMatrix(matrix,target)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}