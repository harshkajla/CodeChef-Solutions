#include <bits/stdc++.h>
#define mod 1000000007
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
int fpref[501][501];
int mpref[501][501];
int mprior[501][501];
int fprior[501][501];
int husband[501],wife[501];
int main()
{
	int t,n,tmp,crush,biwi;
	t=read_int();
	while(t--)
	{
		queue<int> qq;
		n=read_int();
		memset(husband,0,sizeof husband);
		memset(wife,0,sizeof wife);
		memset(fprior,0,sizeof fprior);
		memset(mprior,0,sizeof mprior);
		
		for(int i=1;i<=n;i++)
		{
			tmp=read_int();
			husband[i]=-1;
			qq.push(i);
			for(int j=1;j<=n;j++)
			{
				fpref[i][j]=read_int();
				fprior[i][fpref[i][j]]=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			tmp=read_int();
			wife[i]=-1;
			for(int j=1;j<=n;j++)
			{
				mpref[i][j]=read_int();
				mprior[i][mpref[i][j]]=j;
			}
		}
		
		int flag=0;
		
		while(!qq.empty())
		{
			int man=qq.front();
			qq.pop();
			
			//printf("popped=%d, wife=%d\n",man,wife[man]);
			
			for(int i=1;i<=n;i++)
			{
				crush=mpref[man][i];
			
				//printf("crush=%d\n",crush);
				
				if(wife[man]==crush)
				break;
				
				//if this lady is alone..
				if(husband[crush]==-1)
				{
					//printf("Crush is alone\n");
					//and man is also alone..
					if(wife[man]==-1)
					{
						//printf("Man is also alone\n");
						husband[crush]=man;
						wife[man]=crush;
						break;
					}
					
					//this man was already married..
					//break the marriage..
					//printf("Man was married..breaking marriage..\n");
					husband[wife[man]]=-1;
					wife[man]=crush;
					husband[crush]=man;
					break;
				}
			
				//this woman is engaged already..
				//check if this woman wants this man more than her husband..
				if(fprior[crush][man] < fprior[crush][husband[crush]])
				{
					//printf("Crush prefers %d over husband %d\n",man,husband[crush]);
					//then break this marriage..
					if(wife[man]!=-1)
					husband[wife[man]]=-1;
					
					wife[husband[crush]]=-1;
					qq.push(husband[crush]);
					
					//marry the new couple..
					husband[crush]=man;
					wife[man]=crush;
					break;
				}
			}
		}
		
		//once im out of the loop..all marriages have been performed..
		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",i,wife[i]);
		}
	}
	return 0;
}
