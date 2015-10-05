#include<bits/stdc++.h>
using namespace std;
vector<int> adj[101];
bool visited[101];
int gr[101];
void dfs(int vertex, int gno)
{
    if(visited[vertex])
        return;
    
    visited[vertex]=true;
    gr[vertex]=gno;
    for(int i=0;i<adj[vertex].size();i++)
    {
        if(!visited[adj[vertex][i]])
        {
            dfs(adj[vertex][i],gno);
        }
    }
}
int main()
{
    int n,m,t,a,b,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++)
            adj[i].clear();
            
        memset(visited, false, sizeof visited);
        
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int gno=1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,gno++);
            }
        }
        
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            puts(gr[a]==gr[b]?"YO":"NO");
        }
    }
    return 0;
}
