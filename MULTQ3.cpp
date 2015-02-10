#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
#define left index*2
#define right index*2+1
typedef long long ll;
using namespace std;
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
struct node
{
	int mod0,mod1,mod2;
	int added;
}tree[300001];
void build(int index, int l, int r)
{
	if(l==r)
	{
		tree[index].mod0=1;
		tree[index].mod1=0;
		tree[index].mod2=0;
		tree[index].added=0;
	
		return;
	}
	
	int mid=(l+r)>>1;
	
	tree[index].mod0=r-l+1;
	tree[index].mod1=0;
	tree[index].mod2=0;
	tree[index].added=0;
	
	build(left, l, mid);
	build(right, mid+1, r);
	
}
inline void chmod(int index)
{
	int tmp=tree[index].mod2;
	tree[index].mod2=tree[index].mod1;
	tree[index].mod1=tree[index].mod0;
	tree[index].mod0=tmp;
}
void update(int index, int tl, int tr, int l, int r)
{
	//adding 1 to [l,r]..
	if(tl==l && tr==r)
	{
		tree[index].added++;
		chmod(index);
		
		return;
	}
	
	int mid=(tl+tr)>>1;
	
	if(r<=mid)
	{
		update(left,tl,mid,l,r);
	}
	
	else if(l>mid)
	{
		update(right,mid+1,tr,l,r);
	}
	
	else
	{
		update(left,tl,mid,l,mid);
		update(right,mid+1,tr,mid+1,r);
	}
	
	tree[index].mod0=tree[left].mod0+tree[right].mod0;
	tree[index].mod1=tree[left].mod1+tree[right].mod1;
	tree[index].mod2=tree[left].mod2+tree[right].mod2;
	
	rep(i,tree[index].added%3)
		chmod(index);
}
int query(int index, int tl, int tr, int l, int r, int added)
{
	if(tl==l && tr==r)
	{
		if(added%3==0)
		return tree[index].mod0;
		
		else if(added%3==1)
		return tree[index].mod2;
		
		else
		return tree[index].mod1;
	}
	
	added+=tree[index].added;
	int mid=(tl+tr)>>1;
	
	if(r<=mid)
	return query(left,tl,mid,l,r,added);
	
	else if(l>mid)
	return query(right,mid+1,tr,l,r,added);
	
	else
	return query(left,tl,mid,l,mid,added)+query(right,mid+1,tr,mid+1,r,added);
}
int main()
{
	int n,q,a,i,j;
	n=read_int();q=read_int();
	build(1,0,n-1);
	while(q--)
	{
		a=read_int();i=read_int();j=read_int();
		
		if(a==0)
		{
			//update operation..
			update(1,0,n-1,i,j);
		}
		
		else
		{
			printf("%d\n",query(1,0,n-1,i,j,0));
		}
	}
	
	return 0;
}
