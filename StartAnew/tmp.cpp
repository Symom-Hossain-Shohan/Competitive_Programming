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
    int compress(vector<char>& chars) {
        vector<char> res;
        int cnt = 0, ans = 0;
        char c = chars[0];
        for (int i = 0; i < (int)chars.size(); i++) {
            if (chars[i] == c) {
                cnt++;
            } else {
                if (cnt > 1) {
                    ans += 2;
                    res.push_back(c);
                    string s = to_string(cnt); 
					for(auto it: s) res.push_back(it); 
					
                } else {
                    ans++;
                    res.push_back(c);
                }
                c = chars[i], cnt = 1;
            }
        }
        if (cnt > 1) {
            ans += 2;
            res.push_back(c);
            string s = to_string(cnt); 
			for(auto it: s) res.push_back(it); 
        } else {
            ans++;
            res.push_back(c);
        }

        for (int i = 0; i <(int) res.size(); i++)
            chars[i] = res[i];
        return ans;
    }
};

void solve()
{
	Solution s; 
	vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};	
	cout << s.compress(chars) << endl; 
	for(auto i: chars) cout << i << endl; 

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