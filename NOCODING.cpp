#include<stdio.h>
#include<string.h>
#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main()
{
	int t,l,ans,i;
	char str[1000];
	t=read_int();
	while(t--)
	{
		scanf("%s",str);
		l=strlen(str);
		ans=l+1;//one for printing one for loading
		for(i=1;i<l;i++)
		{
			if(str[i]>=str[i-1])
			{
				ans+=str[i]-str[i-1];
			}
			else
			{
				ans+='z'-str[i-1]+str[i]-'a'+1;
			}
		}
		//printf("instructions=%d\n",ans);
		if(ans<=11*l)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
