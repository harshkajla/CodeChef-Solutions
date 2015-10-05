#include <bits/stdc++.h>
#define mod 10000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
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
int t;
int marked[1001];
string adj[1001];
int c=1;
int bfs(int v)
{	
	queue<pair<int, int> > q;
	q.push(make_pair(v,0));
	int dist=0;
	pair<int, int> x;
	
	marked[v]=c;
	
	while(!q.empty())
	{
		x=q.front();q.pop();
		dist+=x.second;
		
		rep(i,adj[x.first].size())
		{
			if(adj[x.first].at(i)=='1' && marked[i]!=c)
			{
				q.push(make_pair(i,x.second+1));marked[i]=c;
			}
		}
	}
	return dist;
}
int main()
{
	int n,q,v,a,b,m;
	s(t);
	
	while(t--)
	{
		s(n);
		rep(i,n)
		{
			cin>>adj[i];
		}
		
		s(q);
		
		while(q--)
		{
			s(v);s(m);
			
			v--;
			rep(i,m)
			{
				s(a);s(b);
				a--;b--;
				adj[a].at(b)='1'-adj[a].at(b)+'0';//reverse the edge.
			}
			
			c++;
			p(bfs(v));
		}
	}
	
	return 0;
}
