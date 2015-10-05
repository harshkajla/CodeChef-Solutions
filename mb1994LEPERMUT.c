#include <stdio.h>
int main() {
	
	int m,n,i,j,l,r,c;
	
	long long int e1=0,e2=0,max;
	
	scanf("%d%d",&n,&m);
	
	long long int a[n][m];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	
	scanf("%d",&l);
	
	for(i=0;i<l;i++)
	{
		scanf("%d%d",&r,&c);
		
		//summing a[r-1][c-1]..i.e. E1
		if(e1!=-1)
		{
			if(r<=n && c<=m)
			e1+=a[r-1][c-1];
			
			else
			e1=-1;
		}
		
		if(e2!=-1)
		{
			if(c<=n && r<=m)
			e2+=a[c-1][r-1];
			
			else
			e2=-1;
		}
		
	}
	
	max=(e1>=e2)?e1:e2;
	
	printf("%lld\n",max);
	
	return 0;
}
