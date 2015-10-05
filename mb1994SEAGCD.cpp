#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
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
ll d[100001];
vector<ll> dino;
int main()
{
	ll t,n,pos,grass,dins;
	
	s(t);
	
	while(t--)
	{
		dino.clear();
		s(n);
		
		rep(i,n)
		{
			s(d[i]);
			
			//keeping track of dinosaurs..
			if(d[i]<0)
				dino.pb(i);		
		}
		
		grass=0;
		rep(i,n)
		{
			//if its a villager..
			if(d[i]>0)
			{
				dins=-d[dino[0]];
				pos=dino[0];
				
				//if villagers are enough..
				if(d[i]>=dins)
				{	
					d[i]+=d[pos];
					d[pos]=0;
					grass+=abs(pos-i)*dins;
					i--;
					dino.erase(dino.begin());
					
				}
				
				else
				{
					d[pos]+=d[i];
					grass+=abs(pos-i)*d[i];
					d[i]=0;
				}
			}
		}
		
		p(grass);
	}
}
