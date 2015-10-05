#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
using namespace std;
int gcdTree[400010];
int a[200001];
void buildTree(int index, int l, int r)
{
    if(l==r)
    {
        gcdTree[index] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    buildTree(left, l, mid);
    buildTree(right, mid+1, r);
    gcdTree[index] = __gcd(gcdTree[left], gcdTree[right]);
    return;
}
int query(int index, int tl, int tr, int l, int r)
{
    if(tl==l && tr==r)
    {
        return gcdTree[index];
    }
    int mid = (tl+tr)>>1;
    if(r<=mid)
    {
        return query(left, tl, mid, l, r);
    }
    else if(l>mid)
    {
        return query(right, mid+1, tr, l, r);
    }
    else
    {
        int x = query(left, tl, mid, l, mid);
        int y = query(right, mid+1, tr, mid+1, r);
        return __gcd(x,y);
    }
}
int main()
{
    int t,n,q,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        buildTree(1, 0, n-1);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            l--;r--;
            if(l==0)
            {
                printf("%d\n",query(1, 0, n-1, r+1, n-1));
            }
            else if(r==n-1)
            {
                printf("%d\n",query(1, 0, n-1, 0, l-1));
            }
            else
            {
                printf("%d\n",__gcd(query(1,0,n-1,0,l-1), query(1,0,n-1,r+1,n-1)));
            }
        }
    }
    return 0;
}
