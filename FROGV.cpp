#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<iostream>
#include<set>
#include<stack>
#include<string>
#include<cstdlib>
#include<sstream>
#define LEFT index*2+1
#define RIGHT index*2+2
#define gtc getchar_unlocked()
using namespace std;
struct node
{
    int l;
    int r;
    int max;
};
typedef struct node node;
node tree[400001];
inline int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
int bsearch(int* a, int n, int key)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]>key)
        r=mid-1;
        else l=mid+1;
    }
    return -1;
}
node buildtree(int* a, int l, int r, int index)
{
    if(l==r)
    {
        tree[index].l=tree[index].r=r;
        tree[index].max=a[l];
        return tree[index];
    }
    int mid=l+(r-l)/2;
    tree[LEFT]=buildtree(a, l, mid, LEFT);
    tree[RIGHT]=buildtree(a, mid+1, r, RIGHT);
    tree[index].l=l;
    tree[index].r=r;
    tree[index].max=max(tree[LEFT].max, tree[RIGHT].max);
    return tree[index];
}
int query(int l, int r, int index)
{
    //disjoint..
    if(tree[index].l>r || tree[index].r<l)
    return -1;
    //fit..
    if(tree[index].l>=l && tree[index].r<=r)
    return tree[index].max;
    else return max(query(l, r, LEFT), query(l, r, RIGHT));
}
int a[200001],b[200001],diff[200001];
int main()
{
    int n,k,p,i,x,y,xx;
    n=read_int();
    k=read_int();
    p=read_int();
    for(i=0;i<n;i++)
    {
        a[i]=read_int();
        b[i]=a[i];
    }
    sort(b,b+n);
    for(i=0;i<n-1;i++)
    {
        diff[i]=b[i+1]-b[i];
    }
    if(n>=2)
    buildtree(diff, 0, n-2, 0);
    for(i=0;i<p;i++)
    {
        x=read_int();y=read_int();
        if(n==1)
        {
            printf("Yes\n");continue;
        }
        int p1=bsearch(b,n,a[x-1]);
        int p2=bsearch(b,n,a[y-1]);
        if(p1==p2)
        printf("Yes\n");
        else if((xx=query(min(p1, p2), max(p1,p2)-1, 0))<=k)
        printf("Yes\n");
        else printf("No\n");
        //printf("xx=%d\n",xx);
    }
	return 0;
}
