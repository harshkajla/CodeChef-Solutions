#include <bits/stdc++.h>
#define mod 1000000007
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
pair<int, int> pts[2001];
pair<int, int> p1[2],p2[2];
void calc(int p, int r)
{
	int px=pts[p].first;
	int py=pts[p].second;
	int rx=pts[r].first;
	int ry=pts[r].second;
	
	//find pt above p->rotate r about p in anti clock.
	p1[0].first=px+py-ry;
	p1[0].second=-px+py+rx;
	
	//find pt above r->rotate p clock about r..
	p1[1].first=rx-ry+py;
	p1[1].second=rx+ry-px;
	
	//find pt below p->rotate r about p in clock.
	p2[0].first=px-py+ry;
	p2[0].second=px+py-rx;
	
	//find pt below r->rotate p about r anti clock..
	p2[1].first=rx+ry-py;
	p2[1].second=-rx+ry+px;
}
int main()
{
	int n,j,res,tmp,tmp1,tmp2;
	
	n=read_int();
	
	//accepting points..
	rep(i,n)
	{
		pts[i].first=read_int();
		pts[i].second=read_int();
	}
	
	if(n<=2)
	{
		printf("%d\n",4-n);
		return 0;
	}
	
	//sorting them based on x and y..
	sort(pts,pts+n);
	
	res=0;
	rep(i,n)
	{
		for(j=i+1;j<n;j++)
		{
			calc(i,j);
			
			tmp1=binary_search(pts,pts+n,p1[0])+binary_search(pts,pts+n,p1[1]);
			tmp2=binary_search(pts,pts+n,p2[0])+binary_search(pts,pts+n,p2[1]);
			
			tmp=max(tmp1,tmp2);
			if(res<tmp)res=tmp;
			
			if(res==2)break;
		}
		
		if(res==2)break;
	}
	
	printf("%d\n",2-res);
	return 0;
}
