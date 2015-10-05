#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int parent[200001];
bool visited[200001];
bool marked[200001];
vector<int> vertices[200001];
void bfs(int root)
{
    queue<int> qq;int v;
    
    qq.push(root);
    
    while(!qq.empty())
    {
        v=qq.front();
        qq.pop();
        
        for(vector<int>::iterator ii=vertices[v].begin();ii!=vertices[v].end();++ii)
        {
            if(marked[*ii]==false){
            parent[(*ii)]=v;
            qq.push(*ii);
            }
        }
        marked[v]=true;
    }
}
int main()
{
    int n,i,v1,v2,q,r,u,v,start;
    
    scanf("%d",&n);
    
    //initialization..
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&v1,&v2);
        
        //adding as neighbours..
        vertices[v1].push_back(v2);
        vertices[v2].push_back(v1);
    }
    
    scanf("%d",&q);
    
    while(q--)
    {   
        scanf("%d%d%d",&r,&u,&v);
        
        //do bfs with root as 'r'..
        
        for(i=1;i<=n;i++){visited[i]=false;parent[i]=i;marked[i]=false;}
        
        bfs(r);
        
        //traverse till the root from u..
        while(u!=parent[u])
        {  
            visited[u]=true;
            u=parent[u];
            if(u==parent[u])break;
        }visited[u]=true;
        
        //do the same for v..
        while(visited[v]==false)
        {
            v=parent[v];
        }
        
        printf("%d\n",v);
    }
    
    return 0;
}
