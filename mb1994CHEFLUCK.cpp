#include<bits/stdc++.h>
#define lol long long
using namespace std;
inline lol s(int i)
{
	lol ans=0;
	while(i)
	{
		lol r = i%10;
		
		if(r%2==0)
			ans+=r<<1;
		else ans += r;
		
		i/=10;
	}
	
	return ans;
}
lol findsum(lol a, lol b)
{
	if(a>b)
		return 0;
		
	lol ans = 0;
	for(int i = a; i <= b; i++)
	{
		ans += s(i)%10;
	}
	return ans;
}
int main()
{
	int t;
	lol a,b;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		
		lol ans = 0;
		
		//finding nearest multiple of 10 more than a.
		lol n1 = (a - 1) / 10 + 1;
		lol n2 = b / 10;
		
		if(n2 == n1 - 1)
		{
			printf("%lld\n",findsum(a,b));
			continue;
		}
		
		ans += (n2 - n1 ) * 45;
		
		n1*=10;
		n2*=10;
		
		ans += findsum(a, n1 - 1);
		ans += findsum(n2, b);
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
