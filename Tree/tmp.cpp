#include<bits/stdc++.h>
using namespace std;
bool mark[200010];
int n,k,t,dep[200010];
vector<int>g[200010];
void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    for(int v:g[x])if(v!=f)dfs(v,x);
    return ;
}
void clearr(int x)
{
    for(int i=1; i<=x; i++)
    {
        g[i].clear();
        mark[i]=0;
        dep[i]=0;
    }
    return ;
}

int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        clearr(n);
        for(int i=1,p; i<=k; i++)
        {
            cin>>p;
            mark[p]=1;
        }
        for(int i=1,u,v; i<n; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dep[0]=-1;
        dfs(1,0);
        int maxn=-1,u,v;

        for(int i=1; i<=n; i++)
        {
            if(maxn<dep[i]&&mark[i])
            {
                maxn=dep[i];
                u=i;
            }
        }


        dep[0]=-1;
        dfs(u,0);
        maxn=-1;
        
        for(int i=1; i<=n; i++)
        {
            if(maxn<dep[i]&&mark[i])
            {
                maxn=dep[i];
                v=i;
            }
        }
        cout<<(maxn+1)/2<<'\n';

    }

}

