#include<stdio.h>
#define gtc getchar()
inline int read_int()
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
	int n,k,x;
	int count=0;
	n=read_int();
	k=read_int();
	while(n--)
	{
		x=read_int();
		if(x%k==0)count++;
	}
	printf("%d\n",count);
	return 0;
}
