#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
using namespace std;
vector<int> adj[100001];
long long nskill[100001],skill[100001];
int number[100001],child[100001];
long long tree[400001];
bool visited[1000001];
void buildtree(int index, int l, int r)
{
    if(l==r)
    {
        tree[index]=nskill[l];
        return;
    }
    
    int mid=(l+r)>>1;
    
    buildtree(index*2, l, mid);
    buildtree(index*2+1, mid+1, r);
    
    tree[index]=tree[left]+tree[right];
    return;
}
long long query(int index, int tl, int tr, int l, int r)
{
    if(tl==l && tr==r)
            return tree[index];
    
    int mid=(tl+tr)>>1;
    
    if(r<=mid)
        return query(left, tl, mid, l, r);
    else if(l>mid)
        return query(right, mid+1, tr, l, r);
    else
    {
        long long lval = query(left, tl, mid, l, mid);
        long long rval = query(right, mid+1, tr, mid+1, r);
        return lval+rval;
    }
}
//point update..
void update(int index, int tl, int tr, int pt, int val)
{
    if(tl==pt && tr==pt)
    {
        tree[index]+=val;
        return;
    }
    
    tree[index]+=val;
    
    int mid=(tl+tr)>>1;
    if(pt<=mid)
        update(left, tl, mid, pt, val);
    else update(right, mid+1, tr, pt, val);
}
int dfs(int vertex, int num)
{
    visited[vertex]=true;
    number[vertex]=num;
    
    int children=0;
    for(int i=0;i<adj[vertex].size();i++)
    {
        if(!visited[adj[vertex][i]])
        {
            //do dfs for this one..
            int temp = dfs(adj[vertex][i],++num);
            num+=temp;
            children+=temp+1;
        }
    }
    return child[number[vertex]]=children;
}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>skill[i];
    }
    
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //now re-numbering the vertices..
    dfs(1,1);
    
    //re-storing the skills.
    for(int i=1;i<=n;i++)
    {
        nskill[number[i]]=skill[i];
    }
    
    //now building the segment tree..
    buildtree(1, 1, n);
    
    int soldier;
    long long new_skill;
    char op;
    
    while(m--)
    {
        cin>>op;
        
        if(op=='U')
        {
            cin>>soldier>>new_skill;
            soldier = number[soldier];
            update(1, 1, n, soldier, new_skill-nskill[soldier]);
            nskill[soldier]=new_skill;
        }
        
        else
        {
            cin>>soldier;
            cout<<query(1,1,n,number[soldier],number[soldier]+child[number[soldier]])<<endl;
        }
    }
}
