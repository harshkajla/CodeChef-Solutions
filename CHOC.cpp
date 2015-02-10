#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
#define lol long long
using namespace std;
lol a[10001];
lol tree[50001];
lol marked[50001];
void update(int index, int tl, int tr, int l, int r, lol val)
{
    if(tl==l && tr==r)
    {
        tree[index] += (r-l+1)*val;
        marked[index]+=val;
        return;
    }
    
    int mid=(tl+tr)>>1;
    
    if(r<=mid)
        update(left, tl, mid, l, r, val);
    else if(l>mid)
        update(right, mid+1, tr, l, r, val);
    else
    {
        update(left, tl, mid, l, mid, val);
        update(right, mid+1, tr, mid+1, r, val);
    }
}
lol query(int index, int tl, int tr, int l, lol sum)
{
    if(tl==l && tr==l)
    {
        return tree[index]+sum;
    }
    
    int mid=(tr+tl)>>1;
    if(l<=mid)
        return query(left, tl, mid, l, sum+marked[index]);
    else
        return query(right, mid+1,tr,l,sum+marked[index]);
}
int main()
{
    int t,n,u,x,y;
    lol z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&u);
        memset(a,0, sizeof a);
        memset(tree,0,sizeof tree);
        memset(marked,0,sizeof marked);
        
        for(int i=0;i<u;i++)
        {
            scanf("%d%d%lld",&x,&y,&z);
            update(1, 0, n-1, x, y, z);
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            printf("%lld\n",query(1,0,n-1,x,0));
        }
    }
    return 0;
}
