#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--){
		long long n,m,i,j,k,l,p,ans=1e18;
		cin>>n>>m>>k>>p;
		long long a[m+2],b[n+2];
		b[0]=0;
		for(i=1;i<=n;i++){

			long long cur=0;
			multiset<long long>st;
			for(j=1;j<=m;j++){
				cin>>a[j];a[j]++;
				if(j==1){
					cur=a[j];
				}
				else{
					cur=a[j] + *st.begin();
				}
				st.insert(cur);
				if(j-p-1 >=1){
					st.erase(st.find(a[j-p-1]));
				}
				a[j]=cur;

			}
			
			b[i]=cur;
			b[i]=b[i]+b[i-1];
			if(i>=k){
				ans=min(ans,b[i]-b[i-k]);
			}
		}
		cout<<ans<<"\n";
	}
}