#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
bool occupied[401];
int a[401];
int findnext(int* a, int l, int r, int key)
{
	int i;
	
	for(i=l;i<=r;i++)
	{
		if(a[i]==key)
		return i;
	}
	
	return r+1;
}
int main()
{
	int t,n,m,i,tables,cleaned,maxindex,removed,j,pos;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&m);
		
		for(i=0;i<=400;i++)
		{
			occupied[i]=false;
		}
			
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
		}
		
		tables=0;cleaned=0;
		for(i=0;i<m;i++)
		{
			if(!occupied[a[i]])
			{
				
				
				if(tables<n)
				{
					tables++;
					cleaned++;
				}
				
				else
				{
					//remove a customer which occurs last..
					removed=-1;
					maxindex=INT_MIN;
					
					for(j=0;j<i;j++)
					{
						if(occupied[a[j]])
						{
							pos=findnext(a,i+1,m-1,a[j]);
							
							if(pos>maxindex)
							{
								maxindex=pos;
								removed=a[j];
							}
						}
					}
					
					occupied[removed]=false;
					cleaned++;
				}
				
				occupied[a[i]]=true;
			}
		}
			printf("%d\n",cleaned);
	}
		
		return 0;
}
