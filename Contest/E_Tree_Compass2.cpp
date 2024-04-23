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

void solve()
{
    int n; 
    cin >> n; 
	vector<vector<int>> g(n + 1, vector<int>());
    
    for(int i=1, u, v; i<n; i++)
    {
        cin >> u >> v; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }

    vector<int> d(n+1), f(n+1); 

    int s, t, mx = 0; 

    auto dfs = [&] (auto self, int u, int fa) -> void{
        d[u] = d[fa] + 1; 
        f[u] = fa; 

        for(auto child: g[u])
        {
            if(child==fa) continue;
            self(self, child, u); 
        }

        if(d[u]>mx)
        {
            mx = d[u]; 
            t = u; 
        }
    };

    dfs(dfs, 1, 0); 
    s = t, mx = 0; 
    dfs(dfs, s, 0); 

    vector<int> a; 
    int x = t; 
    while(x!=s)
    {
        a.push_back(x); 
        x = f[x]; 
    }
    a.push_back(s); 

    

	int len = a.size();
	x = len / 2;
	if (len % 4 == 0) {
		cout << len / 2 << "\n";
		for (int i = 1; i < len / 2; i += 2) {
			cout << a[x] << " " << i << "\n"; 
			cout << a[x - 1] << " " << i << "\n";
		}
	}
	else if (len % 4 == 1) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i <= len / 2; i++) {
			cout << a[x] << " " << i << "\n"; 
		}
	}
	else if (len % 4 == 2) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i < len / 2; i += 2) {
			cout << a[x] << " " << i << "\n"; 
			cout << a[x - 1] << " " << i << "\n";
		}
	}
	else if (len % 4 == 3) {
		cout << len / 2 + 1 << "\n";
		for (int i = 0; i <= len / 2; i++) {
			cout << a[x] << " " << i << "\n"; 
		}
	}

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}