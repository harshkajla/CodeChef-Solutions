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
map<ll, int> counts;
ll a[100001];
int main()
{
	int n,k,i,ii;
	ll cd, maxcd,first,ffirst,fcd;
	
	n=read_int();
	k=read_int();
	
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		
		if(i>0)
		{
			cd=a[i]-a[i-1];
			counts[cd]++;
		}
	}
	
	ffirst=INT_MAX;
	fcd=INT_MAX;
	
	//find max cd with count >=n-k
	for(i=1;i<n;i++)
	{
		cd=a[i]-a[i-1];
		//printf("cd bw %d and %d =%d, count=%d\n",a[i],a[i-1],cd,counts[cd]);
		if(counts[cd]>=(n-k-1))
		{
			//printf("cd btw %d and %d=%d and count=%d\n",a[i],a[i-1],cd,counts[cd]);
			first=a[i]-i*cd;
			if(first<ffirst || (first==ffirst && cd<fcd))
			{
				ffirst=first;
				fcd=cd;
			}
		}
	}
	//i now have max cd with count>=n-k
	//finding a pair with cd=maxcd
	a[0]=ffirst;
	printf("%lld ",a[0]);
	i=1;
	while(i<n)
	{
		a[i]=a[i-1]+fcd;
		printf("%lld ",a[i]);
		i++;
	}
	
	return 0;
}
