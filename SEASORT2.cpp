#include<stdio.h>
#include<algorithm>
using namespace std;
struct lr
{
int l;
int r;
};
typedef struct lr lr;
inline int selectionAsc(int* a, int l, int r, int n, int array_no, lr* qq, int* c)
{
int i,j,k,min,mini,temp,q1=0;
//performing selection sort
for(i=l;i<r;i++)
{
min=a[i];mini=i;
//finding ith maximum
for(j=i+1;j<=r;j++)
{
if(a[j]<=min)
{
min=a[j];
mini=j;
}
}
//swapping ith position with maxi position
if(a[mini]!=a[i])
{
q1++;
//printf("selection interval = [%d %d]\n",i,mini);
//storing l and r
qq[c[array_no]].l=i+1;
qq[c[array_no]].r=mini+1;
c[array_no]++;
k=i;
while(k<=mini)
{
temp=a[k];
a[k]=a[mini];
a[mini]=temp;
k++;
mini--;
}
}}
return q1;
}
inline int selectionDesc(int* a, int l, int r, int n, int array_no, lr* qq, int* c)
{/*
	printf("In descending selection..\n");
	printf("Array:\n");
*/
int i,j,max,maxi,temp,q1=0,k;
/*
for(i=l;i<r;i++)
{
	printf("%d ",a[i]);
}
printf("\n");*/
//performing selection sort
for(i=l;i<r;i++)
{
max=a[i];maxi=i;
//finding ith maximum
for(j=i+1;j<=r;j++)
{
if(a[j]>=max)
{
max=a[j];
maxi=j;
}
}
//swapping ith position with maxi position
if(a[maxi]!=a[i])
{
q1++;
//storing l and r
qq[c[array_no]].l=i+1;
qq[c[array_no]].r=maxi+1;
c[array_no]++;
k=i;
while(k<=maxi)
{
temp=a[k];
a[k]=a[maxi];
a[maxi]=temp;
k++;
maxi--;
}
}}
return q1;
}
int main()
{
	int n,i,maxs=0,x,j,ll=0,rr=0,cc=5,temp,least;
	scanf("%d",&n);
	int a[8][n];
	lr qq[8][n];
	int c[8],q[8];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[0][i]);
	}
	for(i=0;i<8;i++)
	{
		c[i]=q[i]=0;
	}
	for(i=1;i<8;i++)
	{
		for(j=0;j<n;j++)
		a[i][j]=a[0][j];
	}
	q[0] = selectionAsc(a[0],0,n-1,n,0,qq[0],c);
	q[1] = selectionDesc(a[1],0,n-1,n,1,qq[1],c) + 1;
	//printf("SelectionDesc = %d\n",q1);
	q[2]= selectionAsc(a[2],0,n/2,n,2,qq[2],c) + selectionAsc(a[2],n/2+1,n-1,n,2,qq[2],c) + selectionAsc(a[2],0,n-1,n,2,qq[2],c);
	//printf("SelectionAsc halves = %d\n",q2);
    q[3] = selectionDesc(a[3],0,n/2,n,3,qq[3],c) + selectionDesc(a[3],n/2+1,n-1,n,3,qq[3],c)+ selectionDesc(a[3],0,n-1,n,3,qq[3],c) + 1; //for reversing
	//printf("SelectionDesc halves = %d\n",q3);
	q[4] = selectionAsc(a[4],0,n/2,n,4,qq[4],c) + selectionDesc(a[4],n/2+1,n-1,n,4,qq[4],c) + selectionAsc(a[4],0,n-1,n,4,qq[4],c) ;
	//printf("Asc-Desc-Asc = %d\n",q4);
	q[5] = selectionDesc(a[5],0,n/2,n,5,qq[5],c) + selectionAsc(a[5],n/2+1,n-1,n,5,qq[5],c) + selectionAsc(a[5],0,n-1,n,5,qq[5],c) ;
	//printf("Desc-Asc-Asc = %d\n",q5);
	q[6] = selectionDesc(a[6],0,n/2,n,6,qq[6],c) + selectionAsc(a[6],n/2+1,n-1,n,6,qq[6],c) + selectionDesc(a[6],0,n-1,n,6,qq[6],c) + 1;
	//printf("Desc-Asc-Dessc = %d\n",q6);
	q[7] = selectionAsc(a[7],0,n/2,n,7,qq[7],c) + selectionDesc(a[7],n/2+1,n-1,n,7,qq[7],c) + selectionDesc(a[7],0,n-1,n,7,qq[7],c) + 1;
	//printf("Asc-Desc-Desc = %d\n",q7);
	int minimum=0;
	for(i=0;i<8;i++)
	{
		if(q[i]<q[minimum])
			minimum=i;
	}
	//printing number of swaps
	printf("%d\n",q[minimum]);
	//printing the swap intervals
	for(i=0;i<q[minimum];i++)
	{
	    if(i==(q[minimum]-1) && ((minimum==1)||(minimum==3)||(minimum==6)||(minimum==7)))
		printf("1 %d\n",n);
		else
		printf("%d %d\n",qq[minimum][i].l,qq[minimum][i].r);
	}
	return 0;
}
//54126398710
