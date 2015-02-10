#include<stdio.h>
long long int a[1001];
int main()
{
	long long int t,i,n,k,ans;
	char op[10];
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&ans);
		
		for(i=0;i<n;i++)
		scanf("%lld",i+a);
		scanf("%s",op);
		
		if(op[0]=='X')//XOR op
		{
			if(k%2)
			for(i=0;i<n;i++)ans^=i[a];
		}
		
		else if(op[0]=='A' && k!=0)//AND op
		for(i=0;i<n;i++)
		ans&=i[a];
		
		else if(k!=0)
		for(i=0;i<n;i++)ans|=i[a];
		
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
