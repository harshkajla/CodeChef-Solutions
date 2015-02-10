#include<stdio.h>
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
	int t,n,i,ans;
	char str[1001];
	t=read_int();
	while(t--)
	{
		ans=0;
		n=read_int();
		scanf("%s",str);
		if(n==1){printf("%d\n",(str[0]=='0'));continue;}
		if(n==2){printf("%d\n",2*(str[0]=='0' && str[1]=='0'));continue;}
		for(i=1;i<n-1;i++)
		{
			if(str[i]=='0' && str[i+1]=='0' && str[i-1]=='0')
				ans++;
		}ans+=(str[0]=='0' && str[1]=='0')+(str[n-1]=='0' && str[n-2]=='0');
		printf("%d\n",ans);
	}
	return 0;
}
