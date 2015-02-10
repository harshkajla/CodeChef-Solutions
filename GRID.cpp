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
int mat[1001][1001];
int sum[1001][1001];
int sum1[1001][1001];
int main()
{
	int t,i,j;
	int n;
	
	s(t);
	
	while(t--)
	{
		s(n);
		getchar();
		
		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		{
			mat[i][j]=getchar();
		}
		getchar();
		}
		
		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		{
			if(j==0)
			sum[i][j]=(mat[i][j]!='.');
			
			else
			sum[i][j]=sum[i][j-1]+(mat[i][j]!='.');
		}
		}
		
		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		{
			if(i==0)
			sum1[i][j]=(mat[i][j]!='.');
			
			else
			sum1[i][j]=sum1[i-1][j]+(mat[i][j]!='.');
		}
		}
		
		int cnt=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][j]=='.')
				{
						if((sum[i][n-1]-sum[i][j])==0 && (sum1[n-1][j]-sum1[i][j])==0)
						cnt++;
				}
			}
		}
		
		printf("%d\n",cnt);
		
	}
	return 0;
}
