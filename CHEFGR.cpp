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
int main()
{
	int t,n,m,sum;
	
	s(t);
	
	while(t--)
	{
		s(n);s(m);
		int a[n];
		
		sum=0;
		rep(i,n)
		a[i]=read_int();
		
		rep(i,m)
		{
			int x=(min_element(a,a+n))-a;
			a[x]++;
		}
		
		int x=a[0];int f=0;
		rep(i,n)
		{if(a[i]!=x){f=1;break;}}
		
		if(f)
		puts("No");
		else puts("Yes");
	}
	return 0;
}
