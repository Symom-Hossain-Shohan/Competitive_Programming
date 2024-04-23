#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,i,j,k,l,p,q;
	cin>>n>>q;
	long long a[n+2],b[n+2];
	for(i=1;i<=n;i++){
		cin>>a[i];b[i]=a[i];
	}
	long long cur=0,ans=0,curr=0;
	for(i=0;i<=60;i++){
		curr+=(1ll<<i);
	}
	for(p=1;p<=q;p++){
		cin>>k;ans=0;cur=curr;
		for(i=1;i<=n;i++)a[i]=b[i];
		for(j=60;j>=0;j--){
			
			cur-=(1ll<<j);
			
			long long need=0;
			for(i=1;i<=n;i++){
			
				if((1ll<<j)&a[i])continue;
				need += ((1ll<<j)-(a[i]&cur));
				
				
				if(need>k)break;
			}
			
			if(need<=k){
				k-=need;
				
				ans|=(1ll<<j);
				for(i=1;i<=n;i++){
					if((1ll<<j)&a[i])continue;
				    a[i]|=(1ll<<j);
				    for(int bit=j-1;bit>=0;bit--){
				    	if((1ll<<bit)&a[i])a[i]^=(1ll<<bit);
				    }

				   
				}
			}
		}
		cout<<ans<<"\n";
	}
}