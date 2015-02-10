#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long ll;
using namespace std;
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
int a[100001];
int main()
{
	int n,ch,l,r,d,m,p;
	
	s(n);
	
	rep(i,n)
	{
		s(a[i]);
	}
	
	s(m);
	while(m--)
	{
		s(ch);
		
		if(ch==1)
		{
			s(l);s(r);s(p);
			
			for(int i=l-1;i<r;i++)
			{
				if(a[i]%p==0)
				a[i]/=p;
			}
		}
		
		else
		{
			s(l);s(d);
			
			a[l-1]=d;
		}
	}
	
	rep(i,n)
	p(a[i]);
	
	return 0;
}
