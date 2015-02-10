#include <bits/stdc++.h>
#define mod 1000000009
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
int rr[101],gg[101],bb[101];
int main()
{	
	int t,r,g,b,mm,maxi,globalmax,pos;
	int m[3];
	
	s(t);
	
	while(t--)
	{
		m[0]=m[1]=m[2]=INT_MIN;
		
		s(r);s(g);s(b);s(mm);
		
		rep(i,r)
		{
			s(rr[i]);
			if(rr[i]>m[0])m[0]=rr[i];
		}
		
		rep(i,g)
		{
			s(gg[i]);
			if(gg[i]>m[1])m[1]=gg[i];
		}
		
		rep(i,b)
		{
			s(bb[i]);
			if(bb[i]>m[2])m[2]=bb[i];
		}
		
		globalmax=INT_MAX;
		
		while(mm--)
		{
			//at each stage..ill find max element..
			pos=max_element(m,m+3)-m;
			maxi=m[pos];
			
			//printf("maxi current =%d\n",maxi);
			
			if(maxi<globalmax)
			globalmax=maxi;
			
			m[pos]>>=1;
		}	
		pos=max_element(m,m+3)-m;
		maxi=m[pos];
		//printf("maxi current =%d\n",maxi);
			
		if(maxi<globalmax)
		globalmax=maxi;
		
		p(globalmax);
	}	
	return 0;
}
