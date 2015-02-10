#include<stdio.h>
#include<algorithm>
#define M 1000000007
 
using namespace std;
int main()
{
	long long int t,n,k,i,j,maxi,x,tt,r,m,ans;
	long long int numPerm[201],counts[201];
 
	scanf("%lld",&tt);
 
	while(tt--)
	{
		scanf("%lld%lld",&n,&k);
 
		for(i=0;i<201;i++){numPerm[i]=counts[i]=0;}
		maxi=0;
 
		for(i=0;i<n;i++)
		{
			scanf("%lld",&x);
			maxi=max(maxi,x);
			counts[x]++;
		}
 
		//starting with number of ways for excitingness=1.inserting largest element..
		numPerm[0]=1;
		m=0;
 
		for(i=maxi;i>=1;i--)
		{
			if(counts[i])//n copies of i..inserting..
			{
				t=1;
				for(j=m+1;j<=m+counts[i]-1;j++)
				{
					t=(t*j)%M;
				}
 
				for(r=k;r>=0;r--){
				numPerm[r+1]+=(((numPerm[r]*t)%M)*counts[i])%M;
				numPerm[r]=(((numPerm[r]*t)%M)*m)%M;
				}
 
				m+=counts[i];
			}
		}
		ans=0;
		for(i=1;i<=k;i++)
		{
			ans+=numPerm[i];
			ans%=M;
		}
 
		printf("%lld\n",ans);
	}
 
	return 0;
}
