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
int rem[15];
int main()
{
	int t,n,k,tmp,x,f;
	
	s(t);
	
	while(t--)
	{
		s(n);s(k);
		
		rep(i,15)
		rem[i]=0;
		
		f=0;
		rep(i,n)
		{
			x=read_int();
			tmp=x%(k+1);
			
			rem[tmp]++;
			if(rem[tmp]>=n-1)
			f=1;
		}
		
		(f)?puts("YES"):puts("NO");
	}
	return 0;
}
