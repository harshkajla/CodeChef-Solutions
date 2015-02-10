#include<stdio.h>
#include<algorithm>
using namespace std;
int n,ch;
#define inchar getchar_unlocked
inline int readint() {
	n = 0;
	ch = inchar();
	while (ch < '0' || ch > '9') ch = inchar();
	while (ch >= '0' && ch <= '9') {
		n = (n << 3) + (n << 1) + (ch - '0');
		ch = inchar();
	}
	return n;
}
int main()
{
	int t,n,g,ans,mini,i;
	t=readint();
	while(t--)
	{
		ans=0;
		n=readint()-1;
		mini=readint();
		for(i=1;i<=n;i++)
		{
			g=readint();
			ans=max(ans,g-mini);
			mini=min(mini, g);
		}
		if(ans==0)printf("UNFIT\n");
		else printf("%d\n",ans);
	}
	return 0;
}
