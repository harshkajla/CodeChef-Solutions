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
int marks[5][101];
int cnt[5];
int main()
{
	int n,val,min10,f;
	char sub;
	s(n);
	getchar();
	
	rep(i,n)
	{
		sub=getchar();
		s(val);
		getchar();
		
		cnt[sub-'A']++;
		marks[sub-'A'][val]++;		
	}
	
	//for each subject..
	rep(i,5)
	{
		f=0;
		rep(j,101)
		{
			if(marks[i][j]*10>cnt[i])
			{
				f=1;
				printf("%d ",j);
			}
		}
		
		if(f==0)
		puts("Nothing Unusual");
		
		else puts("");
	}
	
	return 0;
}
