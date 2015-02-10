#include<stdio.h>
long int gcd(long int, long int);
int main()
{
 	short int t;int n,small,small1,i;
 	long int a[1000],hcf,temp;
 	
 	scanf("%hd",&t);
 	
 	while(t--)
 	{
	 		  scanf("%d",&n);
	 		  
			   for(i=0;i<n;i++)
	 		   scanf("%ld",&a[i]);
	 		   
	 		   small=0;small1=1;
	 		   
	 		   //finding smallest and second smallest elements
	 		   for(i=2;i<n;i++)
	 		   {
			   				   if(a[i]<a[small])
			   				   {
							   				 small1=small;
							   				 small=i;
											 continue;
											  }
						 if(a[i]<a[small1] && a[i]!=a[small])
						 small1=i;
						 }
						 
						 //finding gcd of first two smallest elements
						 hcf=gcd(a[small], a[small1]);
						 
						 //swapping1
						 temp=a[0];
						 a[0]=a[small];
						 a[small]=temp;
						 
						 //swapping2
						 temp=a[1];
						 a[1]=a[small1];
						 a[small1]=temp;
						 
						 
						 for(i=2;i<n;i++)
						 hcf=gcd(hcf,a[i]);
						 
						 printf("%ld\n",hcf);
						 
			 }
 					 return 0;
 }
 
 long int gcd(long int small, long int big)
 {
  	  if(big%small==0)
  	  return small;
  	  
  	  else
  	  return gcd(big%small, small);
	  }
