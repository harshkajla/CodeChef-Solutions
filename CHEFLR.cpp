#include<stdio.h>
typedef long long ll;
char str[1000001];
int main()
{
	ll cur,mod=1000000000+7;
	int i,t,level;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s",str);
		
		cur=1;level=0;
		
		for(i=0;str[i];i++)
		{
			level++;
			if(level&1)
			{
				if(str[i]=='l')
				cur=cur*2;
				
				else cur=cur*2+2;
				
				cur%=mod;
			}
			
			else
			{
				if(str[i]=='l')
				cur=cur*2-1;
				
				else cur=cur*2+1;
				
				if(cur<=0)cur+=mod;
				
				else cur%=mod;
			}
		}
		
		printf("%lld\n",cur%mod);
	}
	return 0;
}
