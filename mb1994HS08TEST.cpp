#include<bits/stdc++.h>
bool hash[1025];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j;
		scanf("%d%d",&n,&k);
		int a[n+1];
        memset(hash, false, sizeof hash);
		hash[0]=true;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			hash[a[i]]=true;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<1025;j++)
			{
				if(hash[j])
				hash[a[i]^j]=true;
			}
		}
		int ans=k;
		for(i=0;i<1025;i++)
		{
			if(hash[i])
			{
				if((i^k)>ans)
				ans=i^k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
