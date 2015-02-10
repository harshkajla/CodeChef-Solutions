#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge
{
    int u;
    int v;
    ll cost;
};
typedef struct edge edge;
bool comp1(edge a, edge b)
{
    return a.cost<b.cost;
}
bool comp2(edge a, edge b)
{
    return a.cost>b.cost;
}
edge x[20001];
edge y[20001];
int parent[20001];
int findp(int x)
{
    if(parent[x]==x)
    return x;
    else parent[x]=findp(parent[x]);
    return parent[x];
}
void connect(int a, int b)
{
    int pa=findp(a);
    int pb=findp(b);
    parent[pa]=pb;
}
int main()
{
    int t,n,m1,m2;
    ll profit,cost;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m1,&m2);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<m1;i++)
        {
            scanf("%d%d%lld",&x[i].u, &x[i].v, &x[i].cost);
        }
        for(int i=0;i<m2;i++)
        {
            scanf("%d%d%lld",&y[i].u, &y[i].v, &y[i].cost);
        }
        sort(x,x+m1,comp1);
        sort(y,y+m2,comp2);
        ///first take all possible edges from y..
        int edges=n-1;
        profit=0;
        cost=0;
        for(int i=0;i<m2 && edges;i++)
        {
            int u=y[i].u;
            int v=y[i].v;
            if(findp(u)!=findp(v))
            {
                edges--;
                connect(u,v);
                profit+=y[i].cost;
                cost+=y[i].cost;
            }
        }
        for(int i=0;i<m1 && edges;i++)
        {
            int u=x[i].u;
            int v=x[i].v;
            if(findp(u)!=findp(v))
            {
                edges--;
                cost+=x[i].cost;
                connect(u,v);
            }
        }
        if(edges)
        {
            puts("Impossible");
        }
        else
        {
            printf("%lld %lld\n",profit,cost);
        }
    }
    return 0;
}
