// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const ll mod=1e9+7;
// const ll MX=2e5+5;
// inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
// inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
// inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
// inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication
// inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
// inline ll modInverse(ll a) {return bigMod(a,mod-2); }
// inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

// const ll max_H = 1000, max_W = 1000, max_Y = 100000; 

// void solve()
// {
//     queue<ll> q[max_Y+1]; 
//     ll mtx[max_H][max_W]; 
//     bool inland[max_H][max_W]; 

//     ll h, w, y, ans; 
//     cin >> h >> w >> y; 
//     ans = h*w; 

//     for(int i=0;i<h; i++)
//     {
//         for(int j=0;j<w; j++) 
//         {
//             cin >> mtx[i][j]; 
//             inland[i][j] = true; 
//             if(i==0 or i==h-1 or j==0 or j==w-1)
//             {
//                 q[mtx[i][j]].push(w*i+j); 
//                 inland[i][j] = false; 
//             }
//         }
//     }

//     int dx[4]={0,0,-1,1};
// 	int dy[4]={1,-1,0,0};

//     for(ll i=1;i<=y; i++)
//     {
//         while(!q[i].empty())
//         {
//             ans--; 
//             ll z = q[i].front();
//             ll x = z/w,  y = z%w; 
//             q[i].pop(); 

//             for(int j=0; j<=4; j++)
//             {
//                 if((x+dx[j]>=0 and x+dx[j]<h) and (y+dy[j]>=0 and y+dy[j]<w))
//                 {
//                     if(inland[x+dx[j]][y+dy[j]])
//                     {
//                         q[max(mtx[x+dx[j]][y+dy[j]],i)].push(w*(x+dx[j])+(y+dy[j]));
// 						inland[x+dx[j]][y+dy[j]]=false;
//                     }
//                 }
//             }

//         }
//         cout << ans << endl;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll tc = 1;
//     //cin >> tc;
//     for (ll t = 1; t <= tc; t++)
//     {
//         solve();
//     }
//     return 0;
// }