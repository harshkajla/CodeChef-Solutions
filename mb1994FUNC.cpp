#include <bits/stdc++.h>
#include <utility>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
#define Fij factors[a[i]][j].first
#define Pij factors[a[i]][j].second
typedef long long ll;
using namespace std;
bool marked[1000001];
vector<pair<int, int> > factors[1000001];
int maxpow[1000001];//max powers used for primes till 10^5
int taken[1000001];//marks if prime i has been considered for test case t
void sieve()
{
	int j,cnt,tmp;
	
	marked[0]=marked[1]=true;
	
	for(int i=2;i<1000;i++)
	{
		if(!marked[i])
		{
			//i is a prime..
			factors[i].pb(mp(i,1));
			
			for(j=i<<1;j<=1000000;j+=i)
			{
				cnt=0;tmp=j;
				marked[j]=true;
				while(tmp%i==0)
				{
					tmp/=i;cnt++;
				}
				
				factors[j].pb(mp(i,cnt));
			}
		}
	}
	
	for(int i=1001;i<=1000000;i+=2)
	{
		if(!marked[i])
		{
			factors[i].pb(mp(i,1));
		}
	}
}
int a[100001];
int main()
{
	int t,n;
	
	sieve();
	
	s(t);
	
	while(t--)
	{
		s(n);
		
		rep(i,n)
		{
			s(a[i]);
		}
		
		long long ans=0;
		rep(i,n)
		{
			if(a[i]!=1)
			{
				//traverse through factors list of i..
				for(int j=0;j<factors[a[i]].size();j++)
				{
					//if this prime considered first time..
					if(taken[Fij]!=t+1)
					{
						taken[Fij]=t+1;
						maxpow[Fij]=Pij;
						
						ans+=Pij;
					}
					
					else if(maxpow[Fij]<Pij && taken[Fij]==t+1)
					{
						ans=ans-maxpow[Fij]+Pij;
						maxpow[Fij]=Pij;
					}
				}
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
