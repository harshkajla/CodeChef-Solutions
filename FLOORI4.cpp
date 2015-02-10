#include <bits/stdc++.h>
#define s(t) scanf("%d",&t)
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
ll m;
ll power(ll a)
{
	ll temp=a%m;
	temp=(temp*temp)%m;
	temp=(temp*temp)%m;
	
	return temp;
}
ll g(ll n)
{
	ll ans, mm=30*m;
	
	ll t1=n%mm;
	ll t2=(n+1)%mm;
	ll t3=(2*n+1)%mm;
	ll t4=(3*n)%mm;
	t4=(t4*(n+1))%mm;
	t4--;
	while(t4<0)t4+=mm;
	
	ans=(t1*t2)%mm;
	ans=(((ans*t3)%mm)*t4)%mm;
	
	return (ans/30)%m;
}
int main()
{
	ll n,sum,i,x,sr,ans,k,temp;
	int t;
	s(t);
	
	while(t--)
	{
		scanf("%lld %lld",&n,&m);
		
		ans=0;
		for(i=1;i<=n/i;i++)
		{
			k=n/i;
			
			temp=(k-i+1)*power(i);	
			if(temp>=m)temp%=m;
			
			x=g(k)-g(i);
			while(x<0)x+=m;
			if(x>=m)x%=m;
			
			temp+=x;
			if(temp>=m)temp%=m;
			
			ans=(ans+temp);
			
			if(ans>=m)ans%=m;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
