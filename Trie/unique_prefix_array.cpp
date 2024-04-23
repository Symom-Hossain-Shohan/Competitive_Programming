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

class Node{
    public:
    char data; 
    unordered_map<char, Node*>children; 

    bool terminal; 
    int visited; 
    Node(char d)
    {
        data = d; 
        visited = 1; 
        terminal = false; 
    } 
};

class Trie{
    Node* root; 
    int cnt; 

    public:
    Trie(){
        root = new Node('\0'); 
        cnt = 0; 
    }

    void insert(string &s)
    {
        Node* temp = root; 
        for(int i=0;i<(int)s.size(); i++)
        {
            char  ch = s[i]; 
            if(temp->children.count(ch))
            {
                temp = temp->children[ch]; 
                temp->visited++; 
            }
            else 
            {
                Node* n = new Node(ch); 
                temp->children[ch] = n; 
                temp = n; 
            }
        }
        temp->terminal = true; 
    }

    string find(string &s)
    {
        Node* temp = root; 
        string ans; 
        for(int i=0;i<(int)s.size(); i++)
        {
            char ch = s[i]; 
            ans.push_back(ch); 
            temp = temp->children[ch]; 
            if(temp->visited==1) return ans; 
        }

        return ans;  
    }

};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie t; 
        for(int i=0;i<n; i++)
        {
            t.insert(arr[i]); 
        }
        vector<string> ans; 
        for(int i=0;i<n; i++)
        {
            ans.push_back(t.find(arr[i])); 
        }
        // for(auto i: ans) cout << i << endl; 
        return ans; 
    }
    
};

void solve()
{
    Solution s; 
    string arr[] = {"zebra", "dog", "duck", "dove"}; 
    s.findPrefixes(arr, 4);  
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