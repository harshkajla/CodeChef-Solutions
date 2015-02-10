#include<stdio.h>
int main()
{
	int t,n,k,even,x;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&k);
		
		even=0;
		int nn=n;
		while(n--)
		{
			scanf("%d",&x);
			
			if((x&1)==0)
			even++;
		}
		if(k==0)
		{
			if(even==nn)
			puts("NO");
			else puts("YES");
			
			continue;
		}
		
		if(even>=k)puts("YES");
		else puts("NO");
		
	}
	
	return 0;
}
