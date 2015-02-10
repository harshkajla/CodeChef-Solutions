#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>
#include<functional>
#define gtc getchar_unlocked()
using namespace std;
vector<pair<int, int> > adj[100001];
int mindist[100001];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qq;
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
	int n,m,i,a,b,f,v,w;
	pair<int, int> vw;
	
	n=read_int();m=read_int();
	
	for(i=0;i<=n;i++)
	{
		mindist[i]=INT_MAX;
	}
	
	for(i=0;i<m;i++)
	{
		a=read_int();b=read_int();
		adj[a].push_back(make_pair(b,0));
		adj[b].push_back(make_pair(a,1));
	}
	
	mindist[1]=0;
	qq.push(make_pair(1,0));
	
	f=0;
	while(!qq.empty())
	{
		//pop a pair of vertex and weight..
		vw=qq.top();
		qq.pop();
		
		v=vw.first;
		w=vw.second;
		
		if(w<=mindist[v])
		{
			//iterate through its adjacent elements..
			for(vector<pair<int, int> >::iterator ii=adj[v].begin(); ii!=adj[v].end();ii++)
			{
				if(mindist[ii->first]>w+ii->second)
				{
					mindist[ii->first]=w+ii->second;
					qq.push(make_pair(ii->first,mindist[ii->first]));
				}
				
			}
		}
	}
	
	if(mindist[n]==INT_MAX)
	puts("-1");
	
	else printf("%d\n",mindist[n]);
	
	return 0;
}
