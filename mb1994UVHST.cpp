#include<bits/stdc++.h>
#define lol long long
#define mp make_pair
#define pb push_back
 
using namespace std;
 
bool marked[1000001];
vector<pair<int, int> > adj[1000001];
priority_queue<pair<lol, int>, vector<pair<lol,int> >, less<pair<lol, int> > >qq;
pair<lol, int> top;
int main()
{
    int n,m,a,b,nb2,tot,u,v;
    lol cost,d,c;
    
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%lld",&a,&b,&c);
        adj[a].pb(mp(b,-c));
        adj[b].pb(mp(a,-c));
    }
    
    //creating a minimum spanning tree with the first n/2 nodes..
    qq.push(mp(0,1));
    nb2=n>>1;tot=0;
    while(!qq.empty() && tot!=nb2)
    {
        //pop the first one..
        top = qq.top();qq.pop();
        
        cost = top.first;
        v = top.second;
        
        if(marked[v])
            continue;
            
        marked[v]=true;
        tot++;
        printf("%d ",v);
        for(int i=0;i<adj[v].size();i++)
        {
            u=adj[v][i].first;
            d=adj[v][i].second;
            
            if(!marked[u])
                qq.push(mp(cost-d,u));
        }
    } 
    if(tot!=nb2)
    {
        for(int i=1;i<=n && tot!=nb2;i++)
        {
            if(!marked[i])
            {
                printf("%d ",i);
                tot++;
            }
        }
    }
    return 0;
}
