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
//[x][y]=0,  [x][w]=1 and [y][w]=1
char mat[2001][2001];
vector<int> con[2001];
int main()
{
	int n,j,k,u,v;
	ll ans=0;
	
	s(n);
	
	rep(i,n)
	{
		scanf("%s",mat[i]);
		rep(j,n)
		{
			if(mat[i][j]=='1')
			con[i].pb(j);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(mat[i][j]=='0')
			{
				//i and j are disconnected..ive to find one number which is connected to both of them..
				for(k=0;k<con[i].size();k++)
				{
					if(mat[con[i][k]][j]=='1')
					{
						ans+=2;break;
					}
				}
			}
		}
	}
	
	printf("%lld\n",ans);
	return 0;
}
