#include<stdio.h>
#include<algorithm>
#define gtc getchar_unlocked()
using namespace std;
inline int inp()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int main()
{
	int t,a,b;
	t=inp();
	while(t--)
	{
		a=inp();
		b=inp();
		printf("%d %d\n",max(a,b),a+b);
	}
	return 0;
}
