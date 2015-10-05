#include <bits/stdc++.h>
#define mod 10000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%lld",&t)
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
int main()
{
	double area;
	ll t,h,a,m,b,ind,n,cur,x,y;
	pair<ll, ll> prev;
	
	scanf("%lld", &t);
	
	while(t--)
	{
		s(h);
		s(n);s(m);s(a);s(b);s(ind);
		ll d[m];
		rep(i,m)
		{
			s(d[i]);
		}
		
		//generating x values..
		area=0;
		prev=make_pair(0,0);
		for(int i=1;i<n;i++)
		{
			cur=prev.first+d[ind];
			ind=a*ind+b;ind%=m;
			
			//finding area..
			if(i&1)//odd x coord..y is h..
			{
				x=cur;y=h;
				
				if(prev.second==0)
				{
					area+=((x+0.0-prev.first)*y)/2.0;
				}
				
				else//prev y also h
				{
					area+=(x-prev.first)*(h+0.0);
				}
				
				prev=make_pair(x,y);
			}
			
			else//this y is 0..x is even..
			{
				x=cur;y=0;
				
				if(prev.second==0)//prev y also 0..
				{}
				
				else//prev y is h..
				{
					area+=(x+0.0-prev.first)*h/2.0;
				}
				
				prev=make_pair(x,y);
			}
		}
		
		printf("%.1lf\n",area);
	}
}
