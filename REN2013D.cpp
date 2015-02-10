#include<stdio.h>
#include<algorithm>
#include<iostream>
 
using namespace std;
 
int main()
{
	int t,a[100000];
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		int i;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		
		sort(a,a+n);
		
		if(n==1)
		{
		printf("YES\n");
		continue;
			
		}
		
		
		if(a[0]!=1 && a[0]!=0)
		{
		 printf("NO\n");
		 continue;
		}
	    long long int sum=1+a[0];
		//printf("%d\n",sum);
		for(i=1;i<n;i++)
		{
	         if(sum>=a[i])
              sum+=a[i];
              	
              
              else
              break;
              
              
              //
		}
		
	
	
		if(i==n)
			printf("YES\n");
		
		else
			printf("NO\n");
	}
	return 0;
}
