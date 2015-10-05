#include<bits/stdc++.h>
#define lol long long
using namespace std;
const lol mod=1000000007;
lol a[10000001], b[10000001], present[10000001];
inline lol modpow(lol a, lol b)
{
	if(b==0)
		return 1;
		
	lol ans=1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
			if(ans>mod)ans%=mod;
		}
			
		a=(a*a);
		if(a>mod)a%=mod;
		
		b>>=1;
	}
	
	return ans;
}
int main()
{
	int t;
	int n,m,l,r;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&l,&r);
		
		lol ans=0;
		memset(present, 0, sizeof present);
		
		for(int i=m;i>=1;i--)
		{
			if(present[m/i])
			a[i] = present[m/i];
			
			else
			present[m/i] = a[i] = modpow(m/i,n);
			
			lol subt = 0;
			
			int k=i<<1;
			while(k<=m)
			{
				subt+=b[k];
				if(ans>mod)ans%=mod;
				
				k+=i;
			}
			
			b[i]=a[i]-subt;
			while(b[i]<0)b[i]+=mod;
			
			
			if(i>=l && i<=r)
				ans+=b[i];
				
			if(ans>mod)ans%=mod;
		}
		
		printf("%lld\n",ans);
	}
}
