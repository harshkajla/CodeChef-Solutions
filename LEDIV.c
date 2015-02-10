#include<stdio.h>
#include<math.h>
#define min(a,b) a<b?a:b
#define gc getchar_unlocked
int a[100001];
int primes[100001];
void sieve()
{
	int i,j,c=0;
	for(i=0;i<100001;i++)primes[i]=i;
	primes[1]=-1;
	for(i=2;i<=316;i++)
	{
		if(primes[i]==i)//is a prime..
		{
			for(j=i*i;j<=100000;j+=i)
			{
				primes[j]=min(i,primes[j]);
			}
		}
	}
}
inline int gcd(int a, int b)
{
	return (b==0)?a:gcd(b,a%b);
}
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
	int t,n,gd,i,sroot;
	sieve();
	t=read_int();
	while(t--)
	{
		n=read_int();
		for(i=0;i<n;i++)
			a[i]=read_int();
		gd=a[0];
		for(i=1;i<n;i++)
		{
			gd=gcd(gd,a[i]);
		}
		printf("%d\n",primes[gd]);
	}
	return 0;
}
