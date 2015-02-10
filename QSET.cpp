#include<bits/stdc++.h>
#include<stdio.h>
#define left index*2
#define right index*2+1
#define gc getchar_unlocked
using namespace std;
struct node
{
    long long ans;
    long long l[3];
    long long r[3];
    long long sum;
};
typedef struct node node;
node tree[400001];
string str;
long long read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  long long ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
void buildTree(long long index, long long l, long long r)
{
    if(l==r)
    {
        long long val = str[l]-'0';
        tree[index].sum = val;
        tree[index].ans = val%3==0;
        tree[index].l[val%3]++;
        tree[index].r[val%3]++;
        return;
    }
    long long mid = (l+r)>>1;
    buildTree(left, l, mid);
    buildTree(right, mid+1, r);
    ///storing sum.
    tree[index].sum = tree[left].sum + tree[right].sum;
    ///work for middle part.
    long long additional = tree[left].r[0] * tree[right].l[0];
    additional += tree[left].r[1] * tree[right].l[2];
    additional += tree[left].r[2] * tree[right].l[1];
    ///storing answers.
    tree[index].ans = tree[left].ans + tree[right].ans + additional;
    for(long long i=0;i<3;i++)
    {
        tree[index].l[i] = tree[left].l[i];
        tree[index].r[i] = tree[right].r[i];
    }
    for(long long i=0;i<3;i++)
    {
        tree[index].l[(tree[left].sum + i)%3] += tree[right].l[i];
        tree[index].r[(tree[right].sum + i)%3] += tree[left].r[i];
    }
}
node query(long long index, long long tl, long long tr, long long l, long long r)
{
    if(tl==l && tr==r)
    {
        return tree[index];
    }
    long long mid = (tl+tr)>>1;
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
        node lval = query(left, tl, mid, l, mid);
        node rval = query(right, mid+1, tr, mid+1, r);
        node newnode;
        newnode.sum = lval.sum + rval.sum;
        long long additional = lval.r[0] * rval.l[0];
        additional += lval.r[1] * rval.l[2];
        additional += lval.r[2] * rval.l[1];
        ///storing answers.
        newnode.ans = lval.ans + rval.ans + additional;
        for(long long i=0;i<3;i++)
        {
            newnode.l[i] = lval.l[i];
            newnode.r[i] = rval.r[i];
        }
        for(long long i=0;i<3;i++)
        {
            newnode.l[(lval.sum + i)%3] += rval.l[i];
            newnode.r[(rval.sum + i)%3] += lval.r[i];
        }
        return newnode;
    }
}
void update(long long index, long long tl, long long tr, long long i, long long val)
{
    if(i<tl || i>tr)
        return;
    //do bottom up approach..
    if(tl==tr && tl==i)
    {
        //last node.
        tree[index].l[tree[index].sum%3]--;
        tree[index].r[tree[index].sum%3]--;
        tree[index].sum = val;
        tree[index].ans = val%3==0;
        tree[index].l[val%3]++;
        tree[index].r[val%3]++;
        return;
    }
    long long mid = (tl+tr)>>1;
    if(i<=mid)
    {
        update(left, tl, mid, i, val);
    }
    else if(i>mid)
    {
        update(right, mid+1, tr, i, val);
    }
    ///storing sum.
    tree[index].sum = tree[left].sum + tree[right].sum;
    ///work for middle part.
    long long additional = tree[left].r[0] * tree[right].l[0];
    additional += tree[left].r[1] * tree[right].l[2];
    additional += tree[left].r[2] * tree[right].l[1];
    ///storing answers.
    tree[index].ans = tree[left].ans + tree[right].ans + additional;
    for(long long i=0;i<3;i++)
    {
        tree[index].l[i] = tree[left].l[i];
        tree[index].r[i] = tree[right].r[i];
    }
    for(long long i=0;i<3;i++)
    {
        tree[index].l[(tree[left].sum + i)%3] += tree[right].l[i];
        tree[index].r[(tree[right].sum + i)%3] += tree[left].r[i];
    }
}
int main()
{
    long long n,m,a,b,c;
    n=read_int();m=read_int();
    cin>>str;
    buildTree(1, 0, n-1);
    for(long long i=0;i<m;i++)
    {
        a=read_int();b=read_int();c=read_int();
        b--;
        if(a==1)
        {
            update(1, 0, n-1, b, c);
        }
        else
        {
            c--;
            printf("%lld\n",query(1, 0, n-1, b, c).ans);
        }
    }
}
