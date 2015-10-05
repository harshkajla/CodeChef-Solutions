#include<stdio.h>
#include<string.h>
char str[1000001];
int main()
{
	long long int t,open,ans,i,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",str);
		l=strlen(str);
		open=0;
		ans=0;
		for(i=0;i<l;i++)
		{
			if(str[i]=='<')
				open++;
			else
				open--;
			if(open==-1)break;
			else if(open==0)ans=i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
