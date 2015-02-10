#include<stdio.h>
int combination(int , int);
int main()
{
	short int t,k,a[11],temp,i,j,count,count1;
	scanf("%hd",&t);
	while(t--)
	{count=0;
	count1=1;
		for(i=0;i<11;i++)
		scanf("%hd",&a[i]);
		scanf("%hd",&k);
		//sorting
		for(i=0;i<10;i++)
		for(j=i+1;j<11;j++)
		if(a[i]>a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
		//counting frequency of smallest
		for(i=11-k-1;i>=0;i--)
		{
			if(a[i]==a[11-k])
			count++;
			else
			break;
		}
		for(i=11-k+1;i<11;i++)
		{
			if(a[i]==a[11-k])
			count1++;
			else
			break;
		}
		printf("%d\n",combination(count+count1,count1));
}
		return 0;
}
int combination(int n, int r)
{
	if(r==0 || r==1)
	return n;
	return ((n-r+1)*combination(n,r-1)/r);
}
