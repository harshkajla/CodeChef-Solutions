#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long int ll;
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
ll anss=1;
void calc()
{
	//calculate 5^(mod-2)%mod
	ll a=120;
	ll pow=mod-2;
	
	while(pow)
	{
		if(pow&1)
		anss=(anss*a)%mod;
		
		a=(a*a)%mod;
		pow>>=1;
	}
}
ll C(ll a)
{
	ll temp=a;
	temp*=a-1;if(temp>=mod)temp%=mod;
	temp*=a-2;if(temp>=mod)temp%=mod;
	temp*=a-3;if(temp>=mod)temp%=mod;
	temp*=a-4;if(temp>=mod)temp%=mod;
	return (temp*anss)%mod;
}
int main()
{
	ll n,i;
	ll A,B;
	ll ans=0;
	
	calc();
	scanf("%lld",&n);
	
	for(i=6;i<=n;i+=2)//variable 2*a1..
	{
		A=i>>1;
		B=n-i;
		
		if(B<=0)break;
		
		//now i know a pair (A,B) such that 2A+B=N.
		//time to calc number of ways in which A can be realized.
		//that is C(A-1,5)
		
		if(A<=5)continue;
		
		ans+=C(A-1);
		
		if(ans>mod)
		ans%=mod;
		
	}
	
	printf("%lld\n",ans);
	return 0;
}
