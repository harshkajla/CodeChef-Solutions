#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[100001];
bool compare(int l, int r)
{
	while(l<=r)
	{
		if(str[l]!=str[r])
			return false;
		l++;r--;
	}
	return true;
}
int main()
{
	int t,len,l,r;
	bool ispalin,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		len=strlen(str);
		ispalin=true;
		l=0;r=len-1;
		while(l<r)
		{
			if(str[l]!=str[r])
			{
				ispalin=false;
				break;
			}
			l++;r--;
		}
		if(ispalin)
		{
			puts("YES");
		}
		else
		{
			//l and r were unequal..
			ans=compare(l+1,r) || compare(l,r-1);
			if(ans==true)
			{
				puts("YES");
			}
			else puts("NO");
		}
	}
	return 0;
}
