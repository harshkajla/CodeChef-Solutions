#include <bits/stdc++.h>
#define mod 1000000009
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
#define index first
#define color second
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
pair<int, char> buckets[100001];
int main()
{
	int t,n,m;
	ll ans,tmp;
	
	s(t);
	
	while(t--)
	{
		s(n);s(m);
		getchar();
		
		//printf("m=%d\n",m);
		rep(i,m)
		{
			buckets[i].color=getchar();
			buckets[i].index=read_int();
			
			//printf("%c %d\n",buckets[i].color,buckets[i].index);
		}
		//puts("done");
		//sorting based on indices..
		sort(buckets,buckets+m);
		
		ans=1;
		rep(i,m-1)
		{
			if(buckets[i].color!=buckets[i+1].color && buckets[i].index!=buckets[i+1].index)
			{
				tmp=buckets[i+1].index-buckets[i].index;
				ans=(ans*tmp);
				
				if(ans>mod)ans%=mod;
			}
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}
