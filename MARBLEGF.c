#include<stdio.h>
#include<stdlib.h>
struct node
{
	long long int sum;
	int l;
	int r;
	struct node* left;
	struct node* right;
};
typedef struct node node;
inline node* buildTree(long long int* a, int l, int r)
{
	int mid;
	node* temp=malloc(sizeof(node));
	if(l==r)
	{
		temp->l=temp->r=l;
		temp->sum=a[l];
		temp->left=temp->right=NULL;
		return temp;
	}
	else
	{
		mid=l+(r-l)/2;
		temp->left=buildTree(a,l,mid);
		temp->right=buildTree(a,mid+1,r);
		temp->sum=(temp->left->sum)+(temp->right->sum);
		temp->l=l;
		temp->r=r;
		return temp;
	}
}
inline void give_or_take(node* root, int index, int value)
{
	if(root==NULL)
	return;
	if(index<root->l || index>root->r)
	return;
	root->sum+=value;
	give_or_take(root->left,index,value);
	give_or_take(root->right,index,value);
	return;
}
inline long long int query(node* root, int l, int r)
{
	if(root==NULL)
	return 0;
	//within range
	if(root->l>=l && root->r<=r)
	return root->sum;
	//outside range
	if(l>root->r || r<root->l)
	return 0;
	else
	return query(root->left, l, r)+query(root->right, l, r);
}
int main()
{
	int n,q,i,j;
	char type;
	node* root=NULL;
	scanf("%d%d",&n,&q);
	long long int a[n];
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	root=buildTree(a,0,n-1);
	while(q--)
	{
		scanf("%s%d%d",&type,&i,&j);
		switch(type)
		{
			case 'S':
				printf("%lld\n",query(root,i,j));
				break;
			case 'G':
				give_or_take(root,i,j);
				break;
			case 'T':
				give_or_take(root,i,-1*j);
				break;
		}
	}
	return 0;
}
