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
int primes[30000];
int marked[100001];
bool m[100001];
int c=0;
void sieve()
{
	//finding primes till 31622..
	m[0]=m[1]=-1;
	
	for(int i=2;i<=178;i++)
	{
		if(!m[i])
		{
			primes[c++]=i;
			for(int j=i*i;j<=31700;j+=i)
			m[j]=-1;
		}
	}
	for(int i=179;i<=31699;i+=2)
	if(!m[i])primes[c++]=i;
}
int main()
{
	int t,m,n,lb,ub,multiple;
	
	sieve();
	s(t);
	
	while(t--)
	{
		s(m);s(n);
		
		//[m,n] entirely in [1,31622]..
		if(m>=1 && n<=31700)
		{
			lb=lower_bound(primes,primes+c,m)-primes;
			ub=upper_bound(primes,primes+c,n)-primes-1;
			
			for(int i=lb;i<=ub;i++)
			p(primes[i]);
		}
		
		//[m,n] partially or entirely not in [1,31622]..
		else
		{
			//sieving using primes till 31700..
			for(int i=0;primes[i]*primes[i]<=n;i++)
			{
				//going to nearest multiple of primes[i] in [m,n]..
				multiple = ((m-1)/primes[i]+1)*primes[i];
				
				for(int j=multiple;j<=n;j+=primes[i])
						if(j!=primes[i])marked[j-m]=t+1;
			}
			
			for(int i=m;i<=n;i++)
			{
				if(marked[i-m]!=t+1 && i!=1)p(i);
			}
		}
		
		puts("");
	}
	return 0;
}
