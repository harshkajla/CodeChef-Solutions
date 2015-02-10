#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
bool visited[101];
int dist[101][101];
vector<pii > adj[101];
void dijkstra(int src, int dst)
{
    if(src == dst)
    {
        dist[src][dst] = 0;
        return;
    }
 
    memset(visited, false, sizeof visited);
    priority_queue<pii > qq;
    qq.push(mp(0,src));
    
    pii edge;
    while(!qq.empty())
    {
        edge = qq.top();
        qq.pop();
        
        int u = edge.second;
        int w = edge.first;
        
        if(visited[u])
            continue;
        
        visited[u] = true;
        dist[src][u] = -w;
        
        if(u == dst)
            return;
            
        for(int i = 0;i<adj[u].size(); i++)
        {
            if(!visited[adj[u][i].first])
                qq.push(mp(w - adj[u][i].second, adj[u][i].first));
        }
    }
}
int main()
{
    int n,m,k,q,u,v,w;
    
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dist[i][j] = -1;
            
    for(int i = 0; i < 101; i++)
        adj[i].clear();
        
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    scanf("%d",&q);
    
    while(q--)
    {
        scanf("%d%d",&u,&v);
        if(dist[u][v] !=-1)
        {
            puts(dist[u][v] <= k? "YES":"NO");
            continue;
        }
        
        dijkstra(u, v);
        puts(dist[u][v] <= k? "YES":"NO");
    }
    
    return 0;
}
